#pragma once

#define M_PI 3.14159265358979323846
#define TRIANGLESIDES 3

double* getTriangleSides(double* triangleSides);


char* analyzeTriangle(double side1, double side2, double side3);

// Takes three side lengths of a triangle,
// and returns the angle opposite to the FIRST side agruement
double getAngle(double a, double b, double c);