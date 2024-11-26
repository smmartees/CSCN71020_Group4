#define _CRT_SECURE_NO_WARNINGS
#include "points.h"
#include "main.h"
#include "triangleSolver.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

PPOINT createPointsArray() {
	PPOINT newArray = (PPOINT)malloc(NUMOFPOINTS * sizeof(POINT));
	if (newArray == NULL) {
		printf("did not allocate memory properly\n");
		exit(EXIT_FAILURE);
	}

	return newArray;
}

double findSideLength(POINT p1, POINT p2) {
	double x, y;
	// first, check orientation of points relative to eachother
	if (p1.x < p2.x) {
		x = p2.x - p1.x;
	}
	else {
		x = p1.x - p2.x;
	}
	if (p1.y < p2.y) {
		y = p2.y - p1.y;
	}
	else {
		y = p1.y - p2.y;
	}
	// now we can find side length
	return (sqrt((x * x) + (y * y))); // pythagorean theorem
}

double findPerimeter(PPOINT points) {
	return (findSideLength(points[0], points[1]) +
			findSideLength(points[1], points[2]) +
			findSideLength(points[2], points[3]) +
			findSideLength(points[3], points[0]) );
}

double getArea(PPOINT pointsArray) {	
	return (findSideLength(pointsArray[0], pointsArray[1]) *
			findSideLength(pointsArray[1], pointsArray[2]));
}


void setPoint(PPOINT point, double x, double y) {
	point->x = x;
	point->y = y; 
}

double scanAndCheck(double number) {
	bool validity = false;
	while (true) {
		printf("Enter number: ");
		if (scanf("%lf", &number) != 1)
		{
			while (getchar() != '\n');
			printf("Invalid input\n");
		}
		while (getchar() != '\n');
		if (number > 0) {
			return number;
		}
		else {
			printf("Invalid input\n");
			//while (getchar() != '\n');
		}
	}
}


void fillPointsArray(PPOINT pointsArray) {
	int pointNum = 1;
	for (int i = 0; i < NUMOFPOINTS; i++) {
		
		double x = 0;
		double y = 0;

		printf("\nPoint%d X\n", pointNum);
		x = scanAndCheck(x);

		printf("\nPoint%d Y\n", pointNum);
		y = scanAndCheck(y);

		setPoint(&pointsArray[i], x, y);
		pointNum++;
	}
}

bool compareDoubles(double a, double b) {
	return (fabs(a - b) < (DBL_EPSILON * fabs(a + b)));
}


// NOTE: these functions could be added later, 
//		 to make analyze4Points() more modular.
// 
//void setAngles(double[] sideArray, double* angleArray[]) {
//	// could be written
//}
// 
//bool isQuadrilateral(double sum) {
//	return (compareDoubles(sum, 360));
//}
//
//bool isRectangle(double A, double B, double C, double D) {
//	return (compareDoubles(A, 90) && compareDoubles(B, 90) && 
//			compareDoubles(C, 90) && compareDoubles(D, 90));
//}

bool analyze4Points(PPOINT* points) {
	// define all 6 possible side lengths, and 4 interior angles
	double s1 = findSideLength((*points)[0], (*points)[1]);
	double s2 = findSideLength((*points)[1], (*points)[2]);
	double s3 = findSideLength((*points)[2], (*points)[3]);
	double s4 = findSideLength((*points)[3], (*points)[0]);
	double hs1s2 = findSideLength((*points)[0], (*points)[2]);
	double hs2s3 = findSideLength((*points)[1], (*points)[3]);
	double A = getAngle(hs2s3, s4, s1);
	double B = getAngle(hs1s2, s1, s2);
	double C = getAngle(hs2s3, s2, s3);
	double D = getAngle(hs1s2, s3, s4);
	// There are 3 possible shapes: 2 bowties, and a quadrilateral.
	// If it is a quadrilateral, then sum of interior angles == 360
	// Return if quadrilateral, or swap points around until it is.
	
	// check if shape is a quadrilateral
	if ((compareDoubles(A+B+C+D, 360))) {
		// return true if quadrilateral is rectangle
		return (compareDoubles(A, 90) && compareDoubles(B, 90) &&
				compareDoubles(C, 90) && compareDoubles(D, 90));
	}
	// swap P3 with P4
	POINT temp = (*points)[2];
	(*points)[2] = (*points)[3];
	(*points)[3] = temp;
	// reset interior angles
	A = getAngle(s2, hs1s2, s1);
	B = getAngle(s4, s1, hs2s3);
	C = getAngle(s2, hs2s3, s3);
	D = getAngle(s4, s3, hs1s2);
	// check if shape is a quadrilateral
	if ((compareDoubles(A + B + C + D, 360))) {
		// return true \ if quadrilateral is rectangle
		return (compareDoubles(A, 90) && compareDoubles(B, 90) &&
				compareDoubles(C, 90) && compareDoubles(D, 90));
	}
	// swap P2 with P3
	temp = (*points)[1];
	(*points)[1] = (*points)[2];
	(*points)[2] = temp;
	// reset interior angles
	A = getAngle(s1, hs2s3, s2);
	B = getAngle(s3, s2, hs1s2);
	C = getAngle(s1, hs1s2, s4);
	D = getAngle(s3, s4, hs2s3);
	// shape must be a quadrilateral. Return true if it is a rectangle
	return (compareDoubles(A, 90) && compareDoubles(B, 90) &&
			compareDoubles(C, 90) && compareDoubles(D, 90));
}