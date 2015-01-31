#include"FirstSample.h"
#include<iostream>
#include"../Managers/FalloutInput.h"
using namespace std;
using namespace Fallout::Samples;
using namespace Fallout::Input;
FirstSample::FirstSample():Application(){
}
FirstSample::~FirstSample(){
	cerr << "destructor" << endl;
}

void FirstSample::init(){
	Time::setFrameLimit(10);
}
void FirstSample::loadResources(){
}
void FirstSample::setupScene(){
}

void FirstSample::input(){
	glm::uvec2 pos = IMouse::getPosition();
	if(pos.x>100 && pos.y >100){
		IMouse::setPosition(glm::uvec2(50,50));
	}
	if(IMouse::getButton(IMouse::Right_Button)== IMouse::State_Down)
		cout<<"Left"<<endl;
	if(IMouse::getButton(IMouse::Right_Button)== IMouse::State_Up)
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