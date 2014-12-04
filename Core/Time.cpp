#include"Time.h"
#include<Windows.h>
#include<iostream>
using namespace Fallout::Core;
using namespace std;

//init static variables
double Time::_freq = 0;
bool Time::_init = false;
TimeType Time::_type = TimeType::LIMITED;
int Time::_frameLimit = 60;
double Time::_lastTime = 0;
double Time::_counter = 0;
double Time::_secondTick = 0;
int Time::_frameCounter = 0;
double Time::_totalElapsedTime = 0;

double Time::getTime(){
	LARGE_INTEGER li;
	//check if initialized or not then init
	if (!_init){
		if (!QueryPerformanceFrequency(&li))
			cerr << "Can't initialize the frequency timer" << endl;
		_freq = double(li.QuadPart);
		_init = true;
	}
	//get counter
	if (!QueryPerformanceCounter(&li))
		cerr << "QueryPerformanceCounter Can't get time" << endl;
	return double(li.QuadPart) / _freq;

}
void Time::setFrameLimit(int limit){
	if (limit > 0)
		_frameLimit = limit;
}
int Time::getFrameLimit(){
	return _frameLimit;
}