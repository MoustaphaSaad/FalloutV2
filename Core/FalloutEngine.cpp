#include"FalloutEngine.h"
using namespace std;
using namespace Fallout::Core;
using namespace Fallout::UI;
FalloutEnginePtr FalloutEngine::_instance = nullptr;

FalloutEngine::FalloutEngine(){
	//init members
	_mainThread = NULL;
}
FalloutEngine::~FalloutEngine(){
	cout << "detruct" << endl;
	_instance = nullptr;
	if (_mainThread)
		_mainThread->detach();
}
FalloutEnginePtr FalloutEngine::getInstance(){
	if (_instance == nullptr)
	{
		//init instance
		_instance = FalloutEnginePtr(new FalloutEngine());
	}
	return _instance;
}

bool FalloutEngine::init(DisplayPtr display, GraphicsHandle type){
	cout << "init" << endl;
	_display = display;
	_api = type;
	return true;
}

void FalloutEngine::start(){
	cout << "start" << endl;
	return;
}