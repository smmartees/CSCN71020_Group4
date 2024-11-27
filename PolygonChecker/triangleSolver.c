#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "triangleSolver.h"
// The approximate value of PI


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

char* analyzeTriangle(double side1, double side2, double side3) {
	char* result = "Not a Triangle";

	if (side1 <= 0 || side2 <= 0 || side3 <= 0 ||
		!(side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1)) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) ||
		(side1 == side3 && side1 != side2) ||
		(side2 == side3 && side2 != side1)){
		result = "Isosceles triangle";
	}
	else {
		return "Scalene triangle";
	}

	return result;
}

double getAngle(double a, double b, double c) {
	// formula for findng angle A with sides a b c. Also, it convers rad to deg
	return (180/M_PI * acos( ((b * b) + (c * c) - (a * a)) / (2 * b * c) ));
}

