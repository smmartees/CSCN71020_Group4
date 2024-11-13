#define _CRT_SECURE_NO_WARNINGS
#include "main.h"
#include "triangleSolver.h"
#include <stdio.h>
#include <stdbool.h>

#define ZERO 0
#define ONE 1
#define TWO 2
#define TRIANGLESIDES 3


// addd struct next
// for points 


int side = ZERO;

int main() {


	int triangleSides[TRIANGLESIDES] = { ZERO, ZERO, ZERO };

	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf("Triangle selected.\n");
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			
			char* result = analyzeTriangle(triangleSidesPtr[ZERO], triangleSidesPtr[ONE], triangleSidesPtr[TWO]);
			printf("%s\n", result);
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf("Invalid value entered.\n"); // clear buffer if char inputted
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
// Next on the list to fix// ensure garbage values don't break it
int printShapeMenu() {
	printf("1. Triangle\n");
	printf("2. triangle Angles\n");
	printf("0. Exit\n");

	int shapeChoice;

	printf("Enter number: ");
	scanf("%1o", &shapeChoice); // next on list to improve

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