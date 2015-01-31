#include"GLManager.h"
#include"../Core/FalloutEngine.h"
#include"GLKeyboard.h"
#include"GLMouse.h"
#include<iostream>
#include<GL\glew.h>
#include<GL\freeglut.h>
using namespace std;
using namespace Fallout::Managers;
using namespace Fallout::UI;
using namespace Fallout::Input;

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

	glutInitContextVersion(3, 1);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	//init glew
	GLenum err = glewInit();
	if (err != GLEW_OK){
		std::cerr << "GLEW error : " << glewGetErrorString(err) << std::endl;
		return false;
	}
	return true;
}
void GLManager::start(){
	glutDisplayFunc(&GLManager::display);
	glutIdleFunc(&GLManager::idle);
	glutReshapeFunc(&GLManager::reshape);
	glutKeyboardFunc(&GLKeyboard::keyboardDownFunc);
	glutKeyboardUpFunc(&GLKeyboard::keyboardUpFunc);
	glutSpecialFunc(&GLKeyboard::keyboardSpecialDownFunc);
	glutSpecialUpFunc(&GLKeyboard::keyboardSpecialUpFunc);
	glutMouseFunc(&GLMouse::mouseButton);
	glutMotionFunc(&GLMouse::mouseMove);
	glutPassiveMotionFunc(&GLMouse::mouseMove);

	//start loop
	glutMainLoop();
	return;
}

void GLManager::display(){
	//render function
	Core::FalloutEngine::getInstance()->gameLoop();
	glutSwapBuffers();
}
void GLManager::idle(){
	Core::FalloutEngine::getInstance()->gameLoop();
	//do this when idle
}
void GLManager::reshape(int w,int h){
	// do this when the window resizes
}
void GLManager::clearBuffers(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void GLManager::swapBuffers(){
	glutPostRedisplay();
}