#pragma once
#include "IMouse.h"
namespace Fallout{
	namespace Managers{
		class DXManager;
	}
	namespace Input{
		class DXMouse : public IMouse{
			friend class Managers::DXManager;
		private:
			static void mouseButton(int button, int state);
		protected:
			void update();
		};
	}
}