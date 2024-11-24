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

void getPoint(POINT* point) {
	printf("Enter x-coordinate: ");
	scanf("%d", &(*point).x); 
	printf("Enter y-coordinate: ");
	scanf("%d", &(*point).y); 
}



void setPoint(POINT* point, int x, int y) {
	(*point).x = x; 
	(*point).y = y; 
}

bool analyze4Points(PPOINT* points) {
	double s1 = findSideLength(*points[0], *points[1]);
	double s2 = findSideLength(*points[1], *points[2]);
	double s3 = findSideLength(*points[2], *points[3]);
	double s4 = findSideLength(*points[3], *points[0]);
	double hs1s2 = findSideLength(*points[0], *points[2]);
	double hs2s3 = findSideLength(*points[1], *points[3]);
	double A = getAngle(hs2s3, s4, s1);
	double B = getAngle(hs1s2, s1, s2);
	double C = getAngle(hs2s3, s2, s3);
	double D = getAngle(hs1s2, s3, s4);
	if (A == 90 && B == 90 & C == 90 & D == 90) {
		return true;
	}
	// Swap points 3 and 4, and see if new shape is a rectangle
	A = getAngle(s2, hs1s2, s1);
	B = getAngle(s4, s1, hs2s3);
	C = getAngle(s2, hs2s3, s3);
	D = getAngle(s4, s3, hs1s2);
	if (A == 90 && B == 90 & C == 90 & D == 90) {
		// actually swap the points before returning
		POINT temp = *points[2];
		*points[2] = *points[3];
		*points[3] = temp;
		return true;
	}
	return false;
}