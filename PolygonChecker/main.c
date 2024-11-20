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
			int triangleSides[TRIANGLESIDES] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			
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
			// Need to get the points & validate them


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


int* getTriangleSides(int* triangleSides) {
	int sideNum[TRIANGLESIDES] = { 1, 2, 3 };
	printf("Enter the three sides of the triangle: \n");
	for (int i = 0; i < TRIANGLESIDES; i++)
	{
		printf("side%d: ", sideNum[i]);
		if (scanf("%d", &triangleSides[i]) != 1) {
			printf("Invalid input. Please enter integer\n");
			i--;

			while (getchar() != '\n');
		}
	}
	return triangleSides;
}