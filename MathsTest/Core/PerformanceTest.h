#pragma once
#include <windows.h>

namespace Core
{

	class PerformanceTest
	{
	public:
		PerformanceTest();
		~PerformanceTest();
		void testStart();
		void testFinish();
		unsigned long testResultsMicroseconds();
		unsigned long testResultsMilliseconds();
		unsigned long testResultsSeconds();
	private:
		///The elapsed number of ticks
		LARGE_INTEGER StartingTime, EndingTime, ElapsedTime;
		///The number of ticks-per-second
		LARGE_INTEGER Frequency;
	};

}///End of Core namespace