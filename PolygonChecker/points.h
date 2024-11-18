#pragma once
#include <stdlib.h>

#define NUMOFPOINTS 4

typedef struct points {
	int x;
	int y;
} POINTS, *PPOINTS;


PPOINTS createPointsArray(int numOfPoints);
