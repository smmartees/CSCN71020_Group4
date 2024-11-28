// CSCN71000 - section 1 - Group 4 - Group Assignment

#pragma once

#include <stdbool.h>

// This value is used in the comparison of doubles
#define DBL_EPSILON		2.2204460492503131e-13
// Number of points in a quadrilateral
#define NUMOFPOINTS 4

// ADT for a single point in a 2D plane
typedef struct point {
	double x;
	double y;
} POINT, *PPOINT;

// Creates / initializes the array of points
PPOINT createPointsArray();

// Finds length between 2 points (param order doesn't matter)
double findSideLength(POINT p1, POINT p2);

// Returns sum of lengths betweeen 4 points in array
double findPerimeter(PPOINT points);

// Returns area of a rectangle. Must confirm that it is a rectangle first.
double getArea(PPOINT pointsArray);
              
// Updates a point's x and y coordinates with given values
void setPoint(PPOINT point, double x, double y); 

// Gets user input, and checks if it is a valid double
double scanAndCheck(double number);

// Fills a POINT array
void fillPointsArray(PPOINT pointsArray);

// Returns true if a and b are """equal""" (comparing doubles in C is weird...)
// www.reddit.com/r/C_Programming/comments/4thsn7/comparing_doubles_in_c/
bool compareDoubles(double a, double b);

// Swaps points until it forms a proper quadrilateral,
// then returns whether or not it is a rectangle.
bool orderAndAnalyze4Points(PPOINT* points);
// NOTE:
// There are 3 possible shapes: 2 bowties, and a quadrilateral.
// (it can also be a point, line, or triangle, but they don't matter.)
// If it is a quadrilateral, then sum of interior angles == 360
// If it is a bowtie, then sum of interior angles != 360
// Return only if quadrilateral, otherwise, swap points around until it is.

