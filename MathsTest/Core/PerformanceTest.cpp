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

	uint64_t PerformanceTest::testFinish()
	{
		LARGE_INTEGER elapsedTime;

		QueryPerformanceCounter(&elapsedTime);
		elapsedTime.QuadPart -= startingTime.QuadPart;

		// To guard against loss-of-precision, we convert to microseconds before dividing by ticks-per-second.
		elapsedTime.QuadPart *= 1000000;
		elapsedTime.QuadPart /= frequency.QuadPart;

		return uint64_t(elapsedTime.QuadPart);
	}

}//End of Core namespace