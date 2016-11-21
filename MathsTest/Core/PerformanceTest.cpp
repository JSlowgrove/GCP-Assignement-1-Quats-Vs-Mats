#include "PerformanceTest.h"

namespace Core
{

	PerformanceTest::PerformanceTest()
	{
	}

	PerformanceTest::~PerformanceTest()
	{
	}

	void PerformanceTest::testStart()
	{
		QueryPerformanceFrequency(&Frequency);
		QueryPerformanceCounter(&StartingTime);
	}

	void PerformanceTest::testFinish()
	{
		QueryPerformanceCounter(&EndingTime);
		ElapsedTime.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;
	}

	unsigned long PerformanceTest::testResultsMicroseconds()
	{
		// To guard against loss-of-precision, we convertbto microseconds *before* dividing by ticks-per-second.
		ElapsedTime.QuadPart *= 1000000;
		ElapsedTime.QuadPart /= Frequency.QuadPart;
	}

	unsigned long PerformanceTest::PerformanceTest::testResultsMilliseconds()
	{
		// To guard against loss-of-precision, we convertbto milliseconds *before* dividing by ticks-per-second.
		ElapsedTime.QuadPart *= 1000;
		ElapsedTime.QuadPart /= Frequency.QuadPart;
	}

	unsigned long PerformanceTest::testResultsSeconds()
	{
		ElapsedTime.QuadPart /= Frequency.QuadPart;

	}

}///End of Core namespace