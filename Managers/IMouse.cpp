#include "IMouse.h"
using namespace Fallout::Input;
using namespace std;

map<IMouse::Buttons,IMouse::ButtonState> IMouse::_data = map<IMouse::Buttons,IMouse::ButtonState>();

IMouse::IMouse(){
	_data.clear();
}
IMouse::~IMouse(){
	_data.clear();
}
void IMouse::update(){

}
IMouse::ButtonState IMouse::getButton(IMouse::Buttons b){
	auto it = _data.find(b);
	if(it == _data.end())
		return IMouse::ButtonState::State_None;
	return it->second;
}