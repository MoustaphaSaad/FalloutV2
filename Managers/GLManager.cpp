#include"GLManager.h"
#include<iostream>
#include<GL\glew.h>
#include<GL\freeglut.h>
using namespace Fallout::Managers;
using namespace Fallout::UI;

//linking libraries
#pragma comment(lib,"glew32.lib")
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")
#pragma comment(lib,"freeglut.lib")


GLManager::GLManager(){

}
GLManager::~GLManager(){

}
bool GLManager::init(DisplayPtr d){
	//initialize GLUT and OpenGL
	//init window
	int tmp = 0;
	glutInit(&tmp, NULL);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_RGBA | GLUT_DOUBLE | GLUT_STENCIL);
	glutInitWindowSize(d->_width, d->_height);
	glutCreateWindow(d->_title.c_str());
	//init GL
	glutInitContextVersion(4, 1);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	GLenum err = glewInit();
	if (err != GLEW_OK){
		std::cerr << "GLEW error : " << glewGetErrorString(err) << std::endl;
		return false;
	}
	return true;
}
void GLManager::start(){
	return;
}

void GLManager::display(){
	//render function
}
void GLManager::idle(){
	//do this when idle
}
void GLManager::reshape(){
	// do this when the window resizes
}