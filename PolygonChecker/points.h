#pragma once
#include "main.h"

// note: might want to change this to POINT, instead of POINTS
typedef struct point {
	double x;
	double y;
} POINT, *PPOINT;

// Creates / initializes the array of points
PPOINT createPointsArray();

// finds length between 2 points (param order doesn't matter)
double findSideLength(POINT p1, POINT p2);

// returns sum of lengths betweeen 4 points in array
double findPerimeter(PPOINT points);

// Reads x and y coordinates from user input
void getPoint(POINT* point);               

// Updates a point's x and y coordinates with given values
void setPoint(POINT* point, int x, int y); 