#pragma once
#include "main.h"
#include <stdbool.h>

// This helps in the comparison of doubles
//#define DBL_EPSILON 2.2204460492503131e-16

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

// returns area of a rectangle. Must confirm that it is a rectangle first.
double getArea(PPOINT pointsArray);
              

// Updates a point's x and y coordinates with given values
void setPoint(PPOINT point, double x, double y); 

double scanAndCheck(double number);

void fillPointsArray(PPOINT pointsArray);

bool analyze4Points(PPOINT* points);