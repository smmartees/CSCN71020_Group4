// CSCN71000 - section 1 - Group 4 - Group Assignment
// 
// Sam Pelot
// Megha Panchani
// Brodie Arkell
// Aleksandar Kekic

#define _CRT_SECURE_NO_WARNINGS

#include "triangleSolver.h"
#include "points.h"
#include "menu.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();
		int shapeChoice = printShapeMenu();
		switch (shapeChoice)
		{
		case 1:
			printf("Triangle selected.\n");
			double triangleSides[TRIANGLESIDES] = { 0, 0, 0 };
			double* triangleSidesPtr = getTriangleSides(triangleSides);
			
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf("%s\n", result);
			// if statement here for getting and printing angles
			if (result != "Not a triangle") {
				printf("\nAngles of the triangle:\n");
				printf("Angle 1: %lf\n", getAngle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]));
				printf("Angle 2: %lf\n", getAngle(triangleSidesPtr[1], triangleSidesPtr[2], triangleSidesPtr[0]));
				printf("Angle 3: %lf\n", getAngle(triangleSidesPtr[2], triangleSidesPtr[0], triangleSidesPtr[1]));
			}
			break;
		case 2:
			// Rectangle case
			printf("Rectangle selected.\n");
			PPOINT pointsArray = createPointsArray();
			fillPointsArray(pointsArray);
			// order points, and check if it is a rectangle
			bool rectangleCheck = orderAndAnalyze4Points(&pointsArray);
			// get perimeter and area
			printf("Perimeter: %lf\n", findPerimeter(pointsArray));
			if (rectangleCheck != true) {
				printf("Not a rectangle\n");
			}
			else {
				printf("This is a rectangle\n");
				printf("Area: %lf\n", getArea(pointsArray));
			}
			// free points after case finished
			free(pointsArray);
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf("Invalid value entered.\n");
			while (getchar() != '\n');
			break;
		}
	}
	return 0;
}