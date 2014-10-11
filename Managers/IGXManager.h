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
		};
		typedef std::shared_ptr<IGXManager> IGXManagerPtr;
	}
}