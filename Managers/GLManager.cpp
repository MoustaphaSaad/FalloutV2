#include<GL\glew.h>
#include"GLManager.h"
#include"../Core/FalloutEngine.h"
#include"GLKeyboard.h"
#include"GLMouse.h"
#include<iostream>
#include<exception>
#include<GLFW\glfw3.h>
using namespace std;
using namespace Fallout::Managers;
using namespace Fallout::UI;
using namespace Fallout::Input;

//linking libraries
#pragma comment(lib,"glew32.lib")
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")
#pragma comment(lib,"glfw3.lib")


GLManager::GLManager(){

}
GLManager::~GLManager(){
}
bool GLManager::init(DisplayPtr d){
	//initialize GLUT and OpenGL
	//init window
	if(!glfwInit())
		throw std::exception("Cannot initialize GLFW");
	_window = glfwCreateWindow(d->_width,d->_height,d->_title.c_str(),NULL,NULL);
	if(!_window){
		glfwTerminate();
		throw std::exception("Cannot initialize a GLFW window");
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwMakeContextCurrent(_window);
	//init glew
	GLenum err = glewInit();
	if (err != GLEW_OK){
		throw std::exception((char*)glewGetErrorString(err));
	}
	return true;
}
void GLManager::start(){
	//you must implement the next three functions into the corresponding input divces
	glfwSetKeyCallback(_window,key_callback);
	glfwSetMouseButtonCallback(_window,mouse_callback);
	glfwSetCursorPosCallback(_window,mousePos_callback);
	glfwSetWindowSizeCallback(_window,reshape);

	while(!glfwWindowShouldClose(_window)){
		display();
		glfwPollEvents();
	}
	glfwDestroyWindow(_window);
	glfwTerminate();
	return;
}

void GLManager::display(){
	//render function
	Core::FalloutEngine::getInstance()->gameLoop();
	//glutSwapBuffers();
}
void GLManager::reshape(GLFWwindow* win,int w,int h){
	// do this when the window resizes
	cout<<"SIZE = "<<w<<" "<<h<<endl;
}
void GLManager::clearBuffers(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void GLManager::swapBuffers(){
	//glutPostRedisplay();
	glfwSwapBuffers(_window);
}

void GLManager::key_callback(GLFWwindow* win,int key,int scancode,int action,int mods){
	
}
void GLManager::mouse_callback(GLFWwindow* win,int button,int action,int mods){

}
void GLManager::mousePos_callback(GLFWwindow* win,double x,double y){

}
GLFWwindow* GLManager::getGLFWWindow(){
	GLFWwindow* res = NULL;
	auto instance = dynamic_cast<Managers::GLManager*>(Core::FalloutEngine::getInstance()->getGraphicsDevice().get());
	res = instance->_window;
	instance = NULL;
	return res;
}