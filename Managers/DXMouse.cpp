#include "DXMouse.h"
#include<windows.h>
#include <../Core/FalloutEngine.h>
using namespace Fallout::Input;
using namespace std;

void DXMouse::mouseButton(int button, int state){
	if(state == 0)
		_data.insert(make_pair((Buttons)button,ButtonState::State_Down));
	else if(state == 1)
		_data[(Buttons)button] = ButtonState::State_Up;
	else
		_data.insert(make_pair((Buttons)button,ButtonState::State_None));
}

void DXMouse::update(){
	_data.clear();
}
void DXMouse::setMousePosition(glm::uvec2 val){
	Managers::DXManager* koko = (Managers::DXManager*)Core::FalloutEngine::getInstance()->getGraphicsDevice().get();
	HWND hnd = koko->getWindow()->getHandle();
	POINT pt;
	pt.x = val.x;
	pt.y = val.y;
	if(hnd){
		ClientToScreen(hnd,&pt);
		SetCursorPos(pt.x,pt.y);
	}
}
void DXMouse::mouseMove(int x, int y){
	_position.x = x;
	_position.y = y;
}