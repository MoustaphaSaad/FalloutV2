#pragma once
#include"IGXManager.h"
#include<GLFW\glfw3.h>
#include<memory>
namespace Fallout{
	namespace Managers{
		class GLManager : public IGXManager{
		private:
			//static function to power glut
			static void display();
			static void reshape(GLFWwindow* ,int w, int h);

			GLFWwindow* _window;
			static void key_callback(GLFWwindow*,int,int,int,int);
			static void mouse_callback(GLFWwindow*,int,int,int);
			static void mousePos_callback(GLFWwindow*,double,double);
		public:
			GLManager();
			~GLManager();
			static GLFWwindow* getGLFWWindow();
			//overriding init function
			bool init(UI::DisplayPtr display);
			//overriding start function
			void start();
			//glClear
			void clearBuffers();
			//glpostredisplay
			void swapBuffers();
		};
	}
}