#define _CRT_SECURE_NO_WARNINGS
#include "points.h"
#include "main.h"
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

