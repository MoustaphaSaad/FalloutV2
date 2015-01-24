#include "GLMouse.h"
#include<GL/freeglut.h>
using namespace Fallout::Input;
using namespace std;

void GLMouse::mouseButton(int button, int state, int x, int y){
	if(state == GLUT_DOWN)
		_data.insert(make_pair((Buttons)button,ButtonState::State_Down));
	else if(state == GLUT_UP)
		_data.insert(make_pair((Buttons)button,ButtonState::State_Up));
	else
		_data.insert(make_pair((Buttons)button,ButtonState::State_None));
}

void GLMouse::update(){
	_data.clear();
}