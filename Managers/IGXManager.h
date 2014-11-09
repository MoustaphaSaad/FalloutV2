#pragma once
#include<memory>
#include"../UI/Display.h"

namespace Fallout{
	namespace Managers{
		//Graphics Manager Class that will handle APIs
		class IGXManager{
		public:
			//private constructor to prevent instances of this class
			IGXManager();
			~IGXManager();
			//init function
			virtual bool init(UI::DisplayPtr display);
			virtual void start();
			//this function meant to clear the buffers 
			virtual void clearBuffers();
			//swapBuffer
			virtual void swapBuffers();
		};
		typedef std::shared_ptr<IGXManager> IGXManagerPtr;
	}
}