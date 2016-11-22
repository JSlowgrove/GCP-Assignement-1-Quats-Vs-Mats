#pragma once
#include <windows.h>

/**
@brief The namespace for all core code.
*/
namespace Core
{
	/**
	@brief Contains details and functions for use with testing performance.
	@author Jamie Slowgrove
	*/
	class PerformanceTest
	{
	public:
		/**
		@brief Constructs PerformanceTest.
		*/
		PerformanceTest();

		/**
		@brief Destructs PerformanceTest.
		*/
		~PerformanceTest();

		/**
		@brief A function to start the performance test. 
		This is to be called when the test is to be started.
		*/
		void testStart();

		/**
		@brief A function to stop the performance test.
		This is to be called when the test is to be stopped.
		*/
		void testFinish();

		/**
		@brief A function to get the results of the performance test. 
		This returns the time taken in microseconds.
		@returns The time taken in microseconds.
		*/
		unsigned long testResultsMicroseconds();

		/**
		@brief A function to get the results of the performance test.
		This returns the time taken in milliseconds.
		@returns The time taken in milliseconds.
		*/
		unsigned long testResultsMilliseconds();

		/**
		@brief A function to get the results of the performance test.
		This returns the time taken in seconds.
		@returns The time taken in seconds.
		*/
		unsigned long testResultsSeconds();
	private:
		///The elapsed number of ticks
		LARGE_INTEGER startingTime, endingTime, elapsedTime;
		///The number of ticks-per-second
		LARGE_INTEGER frequency;
	};

}//End of Core namespace