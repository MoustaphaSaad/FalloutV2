#pragma once
#include"IKeyboard.h"
namespace Fallout{
	namespace Input{
		class GLKeyboard : public IKeyboard{
		public:
			static void keyboardDownFunc(unsigned char k, int x, int y);
			static void keyboardUpFunc(unsigned char k, int x, int y);
			void update();
		};
	}
}