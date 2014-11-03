#include"FalloutEngine.h"
#include"../Managers/GLManager.h"
#include"../Managers/DXManager.h"
#include"../Managers/GLKeyboard.h"
using namespace std;
using namespace Fallout::Core;
using namespace Fallout::UI;
using namespace Fallout::Managers;
using namespace Fallout::Input;
FalloutEnginePtr FalloutEngine::_instance = nullptr;

FalloutEngine::FalloutEngine(){
	//init members
	_mainThread = NULL;
	_display = nullptr;
	_graphicsDevice = nullptr;
	_keyboard = nullptr;
	_joinable = false;
	_application = nullptr;
}
FalloutEngine::~FalloutEngine(){
	_instance = nullptr;
	if (_mainThread && !_joinable)
		_mainThread->detach();
	if (_display)
		_display = nullptr;
	if (_graphicsDevice)
		_graphicsDevice = nullptr;
	if (_application)
		_application = nullptr;
}
FalloutEnginePtr FalloutEngine::getInstance(){
	if (_instance == nullptr)
	{
		//init instance
		_instance = FalloutEnginePtr(new FalloutEngine());
	}
	return _instance;
}

void FalloutEngine::setup(DisplayPtr display, GraphicsHandle type){
	_display = display;
	_api = type;
	if (_api == GraphicsHandle::OPENGL){
		//initialize OpenGL device
		_graphicsDevice = IGXManagerPtr(new GLManager());
		_keyboard = IKeyboardPtr(new GLKeyboard());
	}
	else if (_api == GraphicsHandle::DIRECTX){
		//initialize DirectX device
		_graphicsDevice = IGXManagerPtr(new DXManager());
	}
}
bool FalloutEngine::init(){
	if (_graphicsDevice->init(_display))
		_graphicsDevice->start();
	else{
		cerr << "Cannot init Engine ... exit" << endl;
		exit(1);
	}
}
void FalloutEngine::start(){
	//init thread
	if (_graphicsDevice != nullptr)
		_mainThread = new thread(&FalloutEngine::init, this);
	//join check
	if (_mainThread && _joinable)
		_mainThread->join();
	//_graphicsDevice->start();
}

IGXManagerPtr FalloutEngine::getGraphicsDevice(){
	return _graphicsDevice;
}

void FalloutEngine::join(bool val){
	_joinable = val;
}

DisplayPtr FalloutEngine::getDisplay(){
	return _display;
}

void FalloutEngine::setApplication(ApplicationPtr app){
	_application = app;
}