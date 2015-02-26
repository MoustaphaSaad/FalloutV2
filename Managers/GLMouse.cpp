#include "GLMouse.h"
#include "GLManager.h"
#include<GLFW/glfw3.h>
using namespace Fallout::Input;
using namespace std;

void GLMouse::mouseButton(int button, int state, int x, int y){
	if(state == GLFW_PRESS)
		_data.insert(make_pair((Buttons)button,ButtonState::State_Down));
	else if(state == GLFW_RELEASE)
		_data.insert(make_pair((Buttons)button,ButtonState::State_Up));
	else
		_data.insert(make_pair((Buttons)button,ButtonState::State_None));
}

void GLMouse::update(){
	_data.clear();
}

void GLMouse::setMousePosition(glm::uvec2 val){
	glfwSetCursorPos(Managers::GLManager::getGLFWWindow(),val.x,val.y);
}

void GLMouse::mouseMove(int x, int y){
	_position.x = x;
	_position.y = y;
}