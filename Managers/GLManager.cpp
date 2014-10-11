#include"GLManager.h"
#include<iostream>
using namespace Fallout::Managers;
using namespace Fallout::UI;

//linking libraries
#pragma comment(lib,"glew32.lib")
#pragma comment(lib,"freeglut.lib")

GLManager::GLManager(){

}
GLManager::~GLManager(){

}
bool GLManager::init(DisplayPtr d){
	std::cerr << "GLINIT" << std::endl;
	return true;
}
void GLManager::start(){
	std::cerr << "GLSTART" << std::endl;
	return;
}