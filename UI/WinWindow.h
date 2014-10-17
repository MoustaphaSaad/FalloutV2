#pragma once
#include<Windows.h>
#include"Display.h"
namespace Fallout{
	namespace UI{
		class WinWindow{
		private:
			//a handle to the window
			HWND _handle;
			//event handling function
			static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		public:
			WinWindow();
			//init the window
			bool init(DisplayPtr display);
			//loop
			void start();
			//handle getter
			HWND getHandle();
		};
	}
}