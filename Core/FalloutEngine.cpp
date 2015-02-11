#include"FalloutEngine.h"
#include"../Managers/DXManager.h"
#include"../Managers/GLKeyboard.h"
#include"../Managers/DXKeyboard.h"
#include"../Managers/GLMouse.h"
#include"../Managers/DXMouse.h"
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
	_renderer = nullptr;
	_mouse = nullptr;
	_cleaningUp = false;
}
FalloutEngine::~FalloutEngine(){
	_cleaningUp = true;
	if (_mainThread && !_joinable)
		_mainThread->detach();
	if (_display)
		_display = nullptr;
	if (_graphicsDevice)
		_graphicsDevice = nullptr;
	if (_application){
		_application->cleanUp();
		_application = nullptr;
	}
	if(_keyboard)
		_keyboard = nullptr;
	if(_mouse)
		_mouse = nullptr;
	if(_renderer)
		_renderer = nullptr;
	//_instance = nullptr;
}
FalloutEnginePtr FalloutEngine::getInstance(){
	if (_instance == nullptr)
	{
		//init instance
		_instance = FalloutEnginePtr(new FalloutEngine());
	}
	return _instance;
}

void FalloutEngine::setup(DisplayPtr display, GraphicsHandle type, IRendererPtr renderer){
	_display = display;
	_api = type;
	_renderer = renderer;
	if (_api == GraphicsHandle::OPENGL){
		//initialize OpenGL device
		_graphicsDevice = IGXManagerPtr(new GLManager());
		_keyboard = IKeyboardPtr(new GLKeyboard());
		_mouse = IMousePtr(new GLMouse());
	}
	else if (_api == GraphicsHandle::DIRECTX){
		//initialize DirectX device
		_graphicsDevice = IGXManagerPtr(new DXManager());
		_keyboard = IKeyboardPtr(new DXKeyboard());
		_mouse = IMousePtr(new DXMouse());
	}
}
bool FalloutEngine::init(){
	if (_graphicsDevice->init(_display))
		_graphicsDevice->start();
	else{
		cerr << "Cannot init Engine ... exit" << endl;
		exit(1);
	}
	_application->init();
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
	_renderer->setApplication(_application);
	_application->init();
	_application->loadResources();
	_application->setupScene();
}
void FalloutEngine::gameLoop(){
	if(_cleaningUp)
		return;
	//calculate delta
	double current = Time::getTime();
	double delta = current - Time::_lastTime;
	Time::_lastTime = current;
	Time::_totalElapsedTime += delta;
	//increase the counter by the delta time
	Time::_counter += delta;
	Time::_secondTick += delta;
	//bool to indicate whether to render or not
	bool needRender = false;

	//check if a second passed
	if (Time::_secondTick >= 1){
		//reset second tick
		Time::_secondTick = 0;
		//reset frame counter
		Time::_frameCounter = 0;
	}
	if (Time::_type == TimeType::LIMITED){
		//check if counter reached the frame limit in milliseconds
		if (Time::_counter > 1.0/Time::_frameLimit ){
			//set counter to 0 and 
			Time::_counter = 0;
			needRender = true;
		}
	}
	else if (Time::_type == TimeType::UNLIMITED){
		//doesn't matter we always render as much as possible
		needRender = true;
	}
	//calling the processing fucntions every loop
	input();
	update(TimeStep(delta, Time::_totalElapsedTime));
	//if need redner then render the scene
	if (needRender)
	{
		//increase frame count by one
		Time::_frameCounter++;
		render();
	}
}

void FalloutEngine::input(){
	if (_renderer)
		_renderer->input();
	if (_keyboard)
		_keyboard->update();
	if(_mouse)
		_mouse->update();
}
void FalloutEngine::update(TimeStep time){
	_renderer->update(time);
}
void FalloutEngine::render(){
	_renderer->render();
}