// CSCN71000 - section 1 - Group 4 - Group Assignment

#pragma once

// The approximate value of PI
#define M_PI 3.14159265358979323846
// The number of sides in a triangle
#define TRIANGLESIDES 3

// fills an array of doubles via user input, and makes sure they're positive double
double* getTriangleSides(double* triangleSides);

// returns a string that states what type of triangle the 3 sides make
char* analyzeTriangle(double side1, double side2, double side3);

// Takes three side lengths of a triangle,
// and returns the angle opposite to the FIRST side agruement
double getAngle(double a, double b, double c);