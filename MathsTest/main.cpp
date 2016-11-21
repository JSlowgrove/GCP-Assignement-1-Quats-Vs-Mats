#include "Core/PerformanceTest.h"

Core::PerformanceTest* test = new Core::PerformanceTest();

int main()
{
	test->testStart();
	///Algorithm 1
	unsigned long test1Milliseconds = test->testResultsMilliseconds();

	test->testStart();
	///Algorithm 2
	unsigned long test2Milliseconds = test->testResultsMilliseconds();

	///Algorithm compare
	if (test2Milliseconds > test1Milliseconds)
	{
		///Algorithm 1 is quicker
	}
	else if (test2Milliseconds < test1Milliseconds)
	{
		///Algorithm 2 is quicker
	}
	else
	{
		///Algorithm are the same
	}

	delete test;

	return 0;
}


unsigned long timerStart()
{
	DWORD startTime = GetTickCount();
	return unsigned long(startTime);
}

unsigned long timerFinish()
{
	DWORD finishTime = GetTickCount();
	return unsigned long(finishTime);
}

unsigned long timerResults(unsigned long startTime)
{
	return timerFinish() - startTime;
}