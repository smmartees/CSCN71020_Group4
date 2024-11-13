#define _CRT_SECURE_NO_WARNINGS
// CSCN7
// samp - CSCN71000 (Implementation) - Group Project - Section 1

#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#define ZERO 0
#define ONE 1
#define TWO 2
#define TRIANGLESIDES 3

int side = 0;

int main() {

	

	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf("Triangle selected.\n");
			int triangleSides[TRIANGLESIDES] = { ZERO, ZERO, ZERO };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf("%s\n", result);
			// if statement here
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

// next to fix // ensure no garbage
int printShapeMenu() {
	printf("1. Triangle\n");
	printf("0. Exit\n");

	int shapeChoice;

	printf("Enter number: ");
	scanf("%1o", &shapeChoice); // next fix

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	int sideNum[TRIANGLESIDES] = { ONE, TWO, TRIANGLESIDES };
	printf("Enter the three sides of the triangle: \n");
	for (int i = ZERO; i < TRIANGLESIDES; i++)
	{
		printf("side%d: ", sideNum[i]);
		if (scanf("%d", &triangleSides[i]) != ONE) {
			printf("Invalid input. Please enter integer\n");
			i--;

			while (getchar() != '\n');
		}
	}
	return triangleSides;
}