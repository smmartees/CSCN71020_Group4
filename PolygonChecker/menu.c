#define _CRT_SECURE_NO_WARNINGS

#include "menu.h"
#include <stdbool.h>
#include <stdio.h>

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
		// get user input
		printf("Enter number: ");
		if (scanf("%1d", &shapeChoice) != 1)
		{
			while (getchar() != '\n');
			printf("Invalid input\n");
		}
		// check input
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