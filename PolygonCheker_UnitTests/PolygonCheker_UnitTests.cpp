#include "pch.h"
#include "CppUnitTest.h"
#include "math.h"
#include <stdbool.h>

// ***NOTE**** may need to add additional .obj files from the linker menu.
// currently linked: main.obj, triangleSolver.obj,

extern "C" {
#include "../PolygonChecker/main.h"
#include "../PolygonChecker/triangleSolver.h"
#include "../PolygonChecker/points.h"	
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonChekerUnitTests
{
	TEST_CLASS(mainFunctionsTests)
	{
	public:
		
		TEST_METHOD(GetTriangleSides111)
		{
			/*int TriangleSides[3];
			int ExpectedSides[3] = { 1,1,1 };
			int* ActualSides = getTriangleSides(TriangleSides);*/
			// Can't test functions that require user input without modifying
			// the code to use something like fscanf so it can read a file.
			// the other ways to fix it are far beyond me.
		}
	};

	TEST_CLASS(triangleSolverTests)
	{
	public:

		TEST_METHOD(AT111)	// testing analyze triangle using sides 1 1 1
		{
			double TriangleSides[3] = { 1,1,1 };
			char* ExpectedResult = "Equilateral triangle";
			char* ActualResult = analyzeTriangle(TriangleSides[0], TriangleSides[1], TriangleSides[2]);
			Assert::AreEqual(ExpectedResult, ActualResult);
		}
		TEST_METHOD(AT222)
		{
			double TriangleSides[3] = { 2,2,2 };
			char* ExpectedResult = "Equilateral triangle";
			char* ActualResult = analyzeTriangle(TriangleSides[0], TriangleSides[1], TriangleSides[2]);
			Assert::AreEqual(ExpectedResult, ActualResult);
		}
		TEST_METHOD(AT225)
		{
			double TriangleSides[3] = { 2,2,5};
			char* ExpectedResult = "Not a triangle";
			char* ActualResult = analyzeTriangle(TriangleSides[0], TriangleSides[1], TriangleSides[2]);
			Assert::AreEqual(ExpectedResult, ActualResult);
		}
		TEST_METHOD(AT255)		//failed: function didn't compare all sides
		{
			double TriangleSides[3] = { 2,5,5 };
			char* ExpectedResult = "Isosceles triangle";
			char* ActualResult = analyzeTriangle(TriangleSides[0], TriangleSides[1], TriangleSides[2]);
			Assert::AreEqual(ExpectedResult, ActualResult);
		}
		TEST_METHOD(AT525)
		{
			double TriangleSides[3] = { 5,2,5 };
			char* ExpectedResult = "Isosceles triangle";
			char* ActualResult = analyzeTriangle(TriangleSides[0], TriangleSides[1], TriangleSides[2]);
			Assert::AreEqual(ExpectedResult, ActualResult);
		}
		TEST_METHOD(AT343)
		{
			double TriangleSides[3] = { 3,4,3 };
			char* ExpectedResult = "Isosceles triangle";
			char* ActualResult = analyzeTriangle(TriangleSides[0], TriangleSides[1], TriangleSides[2]);
			Assert::AreEqual(ExpectedResult, ActualResult);
		}
		TEST_METHOD(AT123)
		{
			double TriangleSides[3] = { 1,2,3 };
			char* ExpectedResult = "Not a triangle";
			char* ActualResult = analyzeTriangle(TriangleSides[0], TriangleSides[1], TriangleSides[2]);
			Assert::AreEqual(ExpectedResult, ActualResult);
		}
		TEST_METHOD(AT734)
		{
			double TriangleSides[3] = { 6,3,4 };
			char* ExpectedResult = "Scalene triangle";
			char* ActualResult = analyzeTriangle(TriangleSides[0], TriangleSides[1], TriangleSides[2]);
			Assert::AreEqual(ExpectedResult, ActualResult);
		}
		TEST_METHOD(ATEquilateralFloat)
		{
			double TriangleSides[3] = { 1.5,1.5,1.5 };
			char* ExpectedResult = "Equilateral triangle";
			char* ActualResult = analyzeTriangle(TriangleSides[0], TriangleSides[1], TriangleSides[2]);
			Assert::AreEqual(ExpectedResult, ActualResult);
		}
		TEST_METHOD(ATIsoscelesFloat)	//failed: function cast to int
		{
			double TriangleSides[3] = { 1.5,1.3,1.5 };
			char* ExpectedResult = "Isosceles triangle";
			char* ActualResult = analyzeTriangle(TriangleSides[0], TriangleSides[1], TriangleSides[2]);
			Assert::AreEqual(ExpectedResult, ActualResult);
		}
		TEST_METHOD(ATScaleneFloat)		//failed: function cast to int
		{
			double TriangleSides[3] = { 1.2,1.3,1.4 };
			char* ExpectedResult = "Scalene triangle";
			char* ActualResult = analyzeTriangle(TriangleSides[0], TriangleSides[1], TriangleSides[2]);
			Assert::AreEqual(ExpectedResult, ActualResult);
		}
	};

	TEST_CLASS(InternalTriangleTests) 
	{
	public:
		TEST_METHOD(EqualSides)
		{
			double Actual = getAngle(2.0, 2.0, 2.0);
			double Expected = 60.00;
			double precision = 1e-6;
			Assert::AreEqual(Expected, Actual, precision);
		}
		TEST_METHOD(Isosceles322)
		{
			double Actual = getAngle(3.0, 2.0, 2.0);
			double Expected = 97.1808;
			double precision = 1e-2;
			Assert::AreEqual(Expected, Actual, precision);
		}
		TEST_METHOD(Isosceles232)
		{
			double Actual = getAngle(2.0, 3.0, 2.0);
			double Expected = 41.4069;
			double precision = 1e-2;
			Assert::AreEqual(Expected, Actual, precision);
		}
		TEST_METHOD(Isosceles223)
		{
			double Actual = getAngle(2.0, 2.0, 3.0);
			double Expected = 41.4069;
			double precision = 1e-2;
			Assert::AreEqual(Expected, Actual, precision);
		}
	};

	TEST_CLASS(PointTests)
	{
	public:
		TEST_METHOD(SideLength1234)
		{
			POINT p1;
			p1.x = 1;
			p1.y = 2;
			POINT p2;
			p2.x = 3;
			p2.y = 4;

			double expected = sqrt(8);
			double actual = findSideLength(p1, p2);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(SameXCoordinates2324)
		{
			POINT p1;
			p1.x = 2;
			p1.y = 3;
			POINT p2;
			p2.x = 2;
			p2.y = 4;

			double expected = sqrt(1);
			double actual = findSideLength(p1, p2);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(SameYCoordinates3242)
		{
			POINT p1;
			p1.x = 3;
			p1.y = 2;
			POINT p2;
			p2.x = 4;
			p2.y = 2;

			double expected = sqrt(1);
			double actual = findSideLength(p1, p2);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(SameCoordinates4444)
		{
			POINT p1;
			p1.x = 4;
			p1.y = 4;
			POINT p2;
			p2.x = 4;
			p2.y = 4;

			double expected = sqrt(0);
			double actual = findSideLength(p1, p2);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(Sub1Coordinates)
		{
			POINT p1;
			p1.x = 0.5;
			p1.y = 0.7;
			POINT p2;
			p2.x = 0.4;
			p2.y = 0.9;

			double expected = sqrt(0.05);
			double actual = findSideLength(p1, p2);
			double precision = 1e-6;
			Assert::AreEqual(expected, actual, precision);
		}
		TEST_METHOD(AllNegativeCoordinates)
		{
			POINT p1;
			p1.x = -5;
			p1.y = -7;
			POINT p2;
			p2.x = -4;
			p2.y = -9;

			double expected = sqrt(5);
			double actual = findSideLength(p1, p2);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(P1Negative)
		{
			POINT p1;
			p1.x = -5;
			p1.y = -7;
			POINT p2;
			p2.x = 4;
			p2.y = 9;

			double expected = sqrt(337);
			double actual = findSideLength(p1, p2);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(P2Negative)
		{
			POINT p1;
			p1.x = 5;
			p1.y = 7;
			POINT p2;
			p2.x = -4;
			p2.y = -9;

			double expected = sqrt(337);
			double actual = findSideLength(p1, p2);
			Assert::AreEqual(expected, actual);
		}
	};

	TEST_CLASS(AnalyzeFourPoints)
	{
	public:

		TEST_METHOD(test1)
		{
			PPOINT testArray = createPointsArray();
			setPoint(&testArray[0], 2, 2);
			setPoint(&testArray[1], 2, 4);
			setPoint(&testArray[2], 5, 2);
			setPoint(&testArray[3], 5, 4);
			/*PPOINT point1 = NULL;
			setPoint(point1, 2, 2);
			PPOINT point2 = NULL;
			setPoint(point2, 2, 4);
			PPOINT point3 = NULL;
			setPoint(point3, 5, 2);
			PPOINT point4 = NULL;
			setPoint(point4, 5, 4);*/

			bool expected = true;
			bool actual = analyze4Points(&testArray);

			Assert::AreEqual(expected, actual);
		}
	};
}
