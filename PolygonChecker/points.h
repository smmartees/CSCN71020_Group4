#pragma once
#include <stdlib.h>
#include "math.h"

#define NUMOFPOINTS 4

// note: might want to change this to POINT, instead of POINTS
typedef struct points {
	int x;
	int y;
} POINTS, *PPOINTS;

// note: do not need to pass numOfPoints, as it is already a #define
PPOINTS createPointsArray(int numOfPoints);

// finds length between 2 points (param order doesn't matter)
double findSideLength(POINTS p1, POINTS p2);

// returns sum of lengths betweeen 4 points in array
double findPerimeter(PPOINTS points);
