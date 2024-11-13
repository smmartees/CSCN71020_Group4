#include "pch.h"
#include "CppUnitTest.h"

// ***NOTE**** may need to add additional .obj files from the linker menu.
// currently linked: main.obj, triangleSolver.obj,

extern "C" {
#include "../PolygonChecker/main.h"
#include "../PolygonChecker/triangleSolver.h"
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
			int TriangleSides[3] = { 1,1,1 };
			char* ExpectedResult = "Equilateral triangle";
			char* ActualResult = analyzeTriangle(TriangleSides[0], TriangleSides[1], TriangleSides[2]);
			Assert::AreEqual(ExpectedResult, ActualResult);
		}
		TEST_METHOD(AT222)
		{
			int TriangleSides[3] = { 2,2,2 };
			char* ExpectedResult = "Equilateral triangle";
			char* ActualResult = analyzeTriangle(TriangleSides[0], TriangleSides[1], TriangleSides[2]);
			Assert::AreEqual(ExpectedResult, ActualResult);
		}
		TEST_METHOD(AT225)
		{
			int TriangleSides[3] = { 2,2,5};
			char* ExpectedResult = "Isosceles triangle";
			char* ActualResult = analyzeTriangle(TriangleSides[0], TriangleSides[1], TriangleSides[2]);
			Assert::AreEqual(ExpectedResult, ActualResult);
		}
		TEST_METHOD(AT255)		//failed: function didn't compare all sides
		{
			int TriangleSides[3] = { 2,5,5 };
			char* ExpectedResult = "Isosceles triangle";
			char* ActualResult = analyzeTriangle(TriangleSides[0], TriangleSides[1], TriangleSides[2]);
			Assert::AreEqual(ExpectedResult, ActualResult);
		}
		TEST_METHOD(AT525)
		{
			int TriangleSides[3] = { 5,2,5 };
			char* ExpectedResult = "Isosceles triangle";
			char* ActualResult = analyzeTriangle(TriangleSides[0], TriangleSides[1], TriangleSides[2]);
			Assert::AreEqual(ExpectedResult, ActualResult);
		}
		TEST_METHOD(AT123)
		{
			int TriangleSides[3] = { 1,2,3 };
			char* ExpectedResult = "Scalene triangle";
			char* ActualResult = analyzeTriangle(TriangleSides[0], TriangleSides[1], TriangleSides[2]);
			Assert::AreEqual(ExpectedResult, ActualResult);
		}
		TEST_METHOD(AT734)
		{
			int TriangleSides[3] = { 7,3,4 };
			char* ExpectedResult = "Scalene triangle";
			char* ActualResult = analyzeTriangle(TriangleSides[0], TriangleSides[1], TriangleSides[2]);
			Assert::AreEqual(ExpectedResult, ActualResult);
		}
		TEST_METHOD(ATEquilateralFloat)
		{
			int TriangleSides[3] = { 1.5,1.5,1.5 };
			char* ExpectedResult = "Equilateral triangle";
			char* ActualResult = analyzeTriangle(TriangleSides[0], TriangleSides[1], TriangleSides[2]);
			Assert::AreEqual(ExpectedResult, ActualResult);
		}
		TEST_METHOD(ATIsoscelesFloat)	//failed: function cast to int
		{
			int TriangleSides[3] = { 1.5,1.3,1.5 };
			char* ExpectedResult = "Isosceles triangle";
			char* ActualResult = analyzeTriangle(TriangleSides[0], TriangleSides[1], TriangleSides[2]);
			Assert::AreEqual(ExpectedResult, ActualResult);
		}
		TEST_METHOD(ATScaleneFloat)		//failed: function cast to int
		{
			int TriangleSides[3] = { 1.2,1.3,1.4 };
			char* ExpectedResult = "Scalene triangle";
			char* ActualResult = analyzeTriangle(TriangleSides[0], TriangleSides[1], TriangleSides[2]);
			Assert::AreEqual(ExpectedResult, ActualResult);
		}
	};
}
