#include "points.h"

PPOINTS createPointsArray(int numOfPoints) {
	PPOINTS newArray = (PPOINTS)malloc(numOfPoints * sizeof(POINTS));
	if (newArray == NULL) {
		printf("did not allocate memory properly\n");
		exit(EXIT_FAILURE);
	}

	return newArray;

}