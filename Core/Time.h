#pragma once
#include"FalloutEngine.h"
namespace Fallout{
	namespace Core{
		enum TimeType{UNLIMITED, LIMITED};
		class Time{
			friend class FalloutEngine;
		private:
			// to get time from windows api
			static double _freq;
			//to check if timer is initialized
			static bool _init;
			//to determine the number of frames per second
			static int _frameLimit;
			//double to register last time;
			static double _lastTime;
			//to count time between frames
			static double _counter;
			//frame counter to count number of frames per second
			static int _frameCounter;
			//second tick to count every second
			static double _secondTick;
			//counter to indicate the elapsed time
			static double _totalElapsedTime;
		public:
			static TimeType _type;
			static double getTime();
			static void setFrameLimit(int limit);
			static int getFrameLimit();
			static void setTimeType(TimeType val);
		};
	}
}