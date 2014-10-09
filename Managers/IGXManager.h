#pragma once
#include<memory>
#include"../UI/Display.h"

namespace Fallout{
	namespace Managers{
		//Graphics Manager Class that will handle APIs
		class IGXManager{
		public:
			//init function
			virtual bool init(UI::DisplayPtr display);
			virtual void start();
		private:
			//private constructor to prevent instances of this class
			IGXManager();
		};
		typedef std::shared_ptr<IGXManager> IGXManagerPtr;
	}
}