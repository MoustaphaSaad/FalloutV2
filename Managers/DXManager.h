#pragma once
#include"IGXManager.h"
namespace Fallout{
	namespace Managers{
		class DXManager : public IGXManager{
		public:
			DXManager();
			~DXManager();
			//overriding init function
			bool init(UI::DisplayPtr display);
			//overriding start function
			void start();

		};
	}
}