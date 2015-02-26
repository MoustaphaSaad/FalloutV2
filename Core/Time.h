#pragma once
#include"FalloutEngine.h"
namespace Fallout{
	namespace Core{
		class Time{
			friend class FalloutEngine;
		public:
			enum Type{UNLIMITED, LIMITED};
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

			/** @brief	The FPS. */
			static int FPS;
			/** @brief	The type of FPS. */
			static Type _type;
		public:
			static double getTime();
			static void setFrameLimit(int limit);
			static int getFrameLimit();
			static Type getTimeType();
			static void setTimeType(Type val);
			static int getFPS();
		};
	}
}