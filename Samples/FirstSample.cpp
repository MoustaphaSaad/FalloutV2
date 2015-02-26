#include"FirstSample.h"
#include<iostream>
#include"../Managers/FalloutInput.h"
#include"../Objects/FalloutObjects.h"
#include"../Graphics/FalloutGraphics.h"
using namespace std;
using namespace Fallout::Samples;
using namespace Fallout::Input;
using namespace Fallout::Graphics;
FirstSample::FirstSample():Application(){
	
}
FirstSample::~FirstSample(){
	
}

void FirstSample::cleanUp(){
	
}

void FirstSample::init(){
	//Time::setFrameLimit(10);
	Time::setTimeType(Time::Type::UNLIMITED);
}
void FirstSample::loadResources(){
	ResourcePtr moka = Graphics::Resource::load<Graphics::Resource>("moka");
	if(moka == NULL)
		cout<<"Cannot Load"<<endl;
}
void FirstSample::setupScene(){
	
}

void FirstSample::input(){
	//cout<< "FPS = "<<Time::getFPS()<<endl;
	auto mps = IMouse::getPosition();
	if(mps.x>100||mps.y>100)
		IMouse::setPosition(glm::uvec2(100,100));
	if(IMouse::getButton(IMouse::Left_Button)== IMouse::State_Down)
		cout<<"Left"<<endl;
	if(IMouse::getButton(IMouse::Left_Button)== IMouse::State_Up)
		cout<<"Left UP"<<endl;
	if (IKeyboard::getKey(IKeyboard::Keys::A) == IKeyboard::KeyState::State_Down){
		cout << "A" << endl;
	}
	if (IKeyboard::getKey(IKeyboard::Keys::A) == IKeyboard::KeyState::State_Up){
		cout << "A up" << endl;
	}
	if (IKeyboard::getKey(IKeyboard::Keys::End) == IKeyboard::KeyState::State_Down){
		cout << "End" << endl;
	}
	if (IKeyboard::getKey(IKeyboard::Keys::End) == IKeyboard::KeyState::State_Up){
		cout << "End up" << endl;
	}
	if (IKeyboard::getKey(IKeyboard::Keys::Up) == IKeyboard::KeyState::State_Down){
		cout << "Up" << endl;
	}
	if (IKeyboard::getKey(IKeyboard::Keys::Up) == IKeyboard::KeyState::State_Up){
		cout << "Up up" << endl;
	}
	if (IKeyboard::getKey(IKeyboard::Keys::F4) == IKeyboard::KeyState::State_Down){
		cout << "F4" << endl;
	}
	if (IKeyboard::getKey(IKeyboard::Keys::F4) == IKeyboard::KeyState::State_Up){
		cout << "F4 up" << endl;
	}
}
void FirstSample::update(TimeStep time){
}
void FirstSample::render(){
}