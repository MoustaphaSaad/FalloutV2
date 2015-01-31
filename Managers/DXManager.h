#pragma once
#include"IGXManager.h"
#include"../UI/WinWindow.h"
#include<D3D11.h>
#include<D3DX11.h>
#include<D3DX10.h>
#include<memory>
namespace Fallout{
	namespace Managers{
		class DXManager : public IGXManager{
			friend class UI::WinWindow;
		private:
			//windows window
			UI::WinWindow* _window;
			//swap chain pointer
			IDXGISwapChain* _swapChain;
			//device pointer
			ID3D11Device* _device;
			//device context pointer
			ID3D11DeviceContext* _deviceContext;
			//render target
			ID3D11RenderTargetView* _backBuffer;
			//viewport
			D3D11_VIEWPORT _viewport;
			//functions to power the window
			static void display();
			static void reshape(int w, int h);
			static void idle();
		public:
			DXManager();
			~DXManager();
			//overriding init function
			bool init(UI::DisplayPtr display);
			//overriding start function
			void start();
			//clear buffer function
			void clearBuffers();
			//swap chain
			void swapBuffers();

			/**
			 * @fn	WinWindow* DXManager::getWindow();
			 *
			 * @brief	Gets the window.
			 *
			 * @author	Moustapha Saad
			 * @date	29/01/2015
			 *
			 * @return	null if it fails, else the window.
			 */

			UI::WinWindow* getWindow() const;
		};
	}
}