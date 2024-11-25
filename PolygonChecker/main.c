#define _CRT_SECURE_NO_WARNINGS

#include "main.h"
#include "triangleSolver.h"
#include "points.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// CSCN7
// samp - CSCN71000 (Implementation) - Group Project - Section 1


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
				printf("Angle 1: %f\n", getAngle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]));
				printf("Angle 2: %f\n", getAngle(triangleSidesPtr[1], triangleSidesPtr[2], triangleSidesPtr[0]));
				printf("Angle 3: %f\n", getAngle(triangleSidesPtr[2], triangleSidesPtr[0], triangleSidesPtr[1]));
			}
			break;
		case 2:
			// Rectangle case
		{
			PPOINT pointsArray = createPointsArray(NUMOFPOINTS);
			
			fillPointsArray(pointsArray);

							/// just to test points ///
			printf("point1: X = %lf  Y = %lf\n", pointsArray[0].x, pointsArray[0].y);
			printf("point2: X = %lf  Y = %lf\n", pointsArray[1].x, pointsArray[1].y);
			printf("point3: X = %lf  Y = %lf\n", pointsArray[2].x, pointsArray[2].y);
			printf("point4: X = %lf  Y = %lf\n", pointsArray[3].x, pointsArray[3].y);
							/// just to test points ///

			printf("Perimeter: %lf\n", findPerimeter(pointsArray));
			bool rectangleCheck = analyze4Points(pointsArray);
			if (rectangleCheck != true) {
				printf("Not a rectangle\n");
			}
			else {
				printf("This is a rectangle\n");
				//findArea(pointsArray);
			}

			// free points after case finished
			free(pointsArray);
		}
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

void printWelcome() {
	printf("\n");
	printf(" **********************\n");
	printf("**     Welcome to     **\n");
	printf("**   Polygon Checker  **\n");
	printf(" **********************\n");
}


int printShapeMenu() {
	printf("1. Triangle\n");
	printf("2. Rectangle\n");
	printf("0. Exit\n");

	int shapeChoice;
	bool validity = false;
	do {
		printf("Enter number: ");
		if (scanf("%1d", &shapeChoice) != 1)
		 {
			while (getchar() != '\n');
			printf("Invalid input\n");
		}

		if (shapeChoice == 1 || shapeChoice == 2 || shapeChoice == 0) {
			validity = true;
		}
		else {
			printf("Invalid input\n");
			while (getchar() != '\n');
		}

	} while (validity == false);
	return shapeChoice;
}


double* getTriangleSides(double* triangleSides) {
	int sideNum[TRIANGLESIDES] = { 1, 2, 3 };
	printf("Enter the three sides of the triangle: \n");
	for (int i = 0; i < TRIANGLESIDES; i++)
	{
		printf("side%d: ", sideNum[i]);
		if (scanf("%lf", &triangleSides[i]) != 1) {
			printf("Invalid input. Please enter number\n");
			i--;

			while (getchar() != '\n');
		}
	}
	return triangleSides;
}