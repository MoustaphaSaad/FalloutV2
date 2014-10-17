#pragma once
#include"IGXManager.h"
#include"../UI/WinWindow.h"
namespace Fallout{
	namespace Managers{
		class DXManager : public IGXManager{
		private:
			//windows window
			UI::WinWindow _window;
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