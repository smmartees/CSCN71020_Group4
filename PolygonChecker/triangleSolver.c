#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
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
	// formula for findng angle A with sides a b c
	return acos( ((b * b) + (c * c) - (a * a)) / (2 * b * c) );
}