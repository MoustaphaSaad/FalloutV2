#pragma once
#include"IGXManager.h"
namespace Fallout{
	namespace Managers{
		class GLManager : public IGXManager{
		public:
			GLManager();
			~GLManager();
			//overriding init function
			bool init(UI::DisplayPtr display);
			//overriding start function
			void start();
		};
	}
}