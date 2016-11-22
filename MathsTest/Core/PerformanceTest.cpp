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
		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&startingTime);
	}

	void PerformanceTest::testFinish()
	{
		QueryPerformanceCounter(&endingTime);
		elapsedTime.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
	}

	unsigned long PerformanceTest::testResultsMicroseconds()
	{
		// To guard against loss-of-precision, we convert to microseconds before dividing by ticks-per-second.
		elapsedTime.QuadPart *= 1000000;
		elapsedTime.QuadPart /= frequency.QuadPart;
	}

	unsigned long PerformanceTest::PerformanceTest::testResultsMilliseconds()
	{
		// To guard against loss-of-precision, we convert to milliseconds before dividing by ticks-per-second.
		elapsedTime.QuadPart *= 1000;
		elapsedTime.QuadPart /= frequency.QuadPart;
	}

	unsigned long PerformanceTest::testResultsSeconds()
	{
		elapsedTime.QuadPart /= frequency.QuadPart;
	}

}//End of Core namespace