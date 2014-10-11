#include"FalloutEngine.h"
#include"../Managers/GLManager.h"
#include"../Managers/DXManager.h"
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
	_joinable = false;
}
FalloutEngine::~FalloutEngine(){
	_instance = nullptr;
	if (_mainThread && !_joinable)
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
	_display = display;
	_api = type;
	if (_api == GraphicsHandle::OPENGL){
		//initialize OpenGL device
		_graphicsDevice = IGXManagerPtr(new GLManager());
		_graphicsDevice->init(_display);
	}
	else if (_api == GraphicsHandle::DIRECTX){
		//initialize DirectX device
		_graphicsDevice = IGXManagerPtr(new DXManager());
		_graphicsDevice->init(_display);
	}
	return true;
}

void FalloutEngine::start(){
	//init thread
	if (_api == GraphicsHandle::OPENGL)
		_mainThread = new thread(&Fallout::Managers::GLManager::start,(GLManager*)_graphicsDevice.get());
	else if (_api == GraphicsHandle::DIRECTX)
		_mainThread = new thread(&Fallout::Managers::DXManager::start, (DXManager*)_graphicsDevice.get());
	//join check
	if (_mainThread && _joinable)
		_mainThread->join();
}

IGXManagerPtr FalloutEngine::getGraphicsDevice(){
	return _graphicsDevice;
}

void FalloutEngine::join(bool val){
	_joinable = val;
}