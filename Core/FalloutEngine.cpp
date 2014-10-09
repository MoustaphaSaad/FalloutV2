#include"FalloutEngine.h"
using namespace std;
using namespace Fallout::Core;
using namespace Fallout::UI;
using namespace Fallout::Managers;
FalloutEnginePtr FalloutEngine::_instance = nullptr;

FalloutEngine::FalloutEngine(){
	//init members
	_mainThread = NULL;
	_display = nullptr;
	_graphicsDevice = nullptr;
}
FalloutEngine::~FalloutEngine(){
	cout << "detruct" << endl;
	_instance = nullptr;
	if (_mainThread)
		_mainThread->detach();
	if (_display)
		_display = nullptr;
	if (_graphicsDevice)
		_graphicsDevice = nullptr;
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
	if (_api == GraphicsHandle::OPENGL){
		//initialize OpenGL device
	}
	else if (_api == GraphicsHandle::DIRECTX){
		//initialize DirectX device
	}
	return true;
}

void FalloutEngine::start(){
	cout << "start" << endl;
	return;
}