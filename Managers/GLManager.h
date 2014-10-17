#pragma once
#include"IGXManager.h"
namespace Fallout{
	namespace Managers{
		class GLManager : public IGXManager{
		public:
			GLManager();
			~GLManager();
			//static function to power glut
			static void display();
			static void reshape(int w, int h);
			static void idle();
			//overriding init function
			bool init(UI::DisplayPtr display);
			//overriding start function
			void start();
		};
	}
}