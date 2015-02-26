#pragma once
#include<iostream>
#include<memory>
#include<thread>
#include"../UI/Display.h"
#include"../Managers/IGXManager.h"
#include"../Managers/GLManager.h"
#include"../Managers/DXManager.h"
#include"../Managers/IKeyboard.h"
#include"../UI/Application.h"
#include"../Managers/IMouse.h"
#include"IRenderer.h"
#include"TimeStep.h"

namespace Fallout{
	namespace Core{
		enum GraphicsHandle{ OPENGL, DIRECTX };
		class FalloutEngine{
			friend class Fallout::Managers::GLManager;
			friend class Fallout::Managers::DXManager;
			friend class Fallout::Input::IMouse;
		public: 
			~FalloutEngine();
			//init function takes display, Graphics handle, and you can pass a custom renderer or it will be the default one
			void setup(UI::DisplayPtr display,GraphicsHandle type, IRendererPtr renderer = IRendererPtr(new IRenderer()));
			//will take an application
			void start();
			//graphics device getter
			Managers::IGXManagerPtr getGraphicsDevice();
			//_joinable setter to decide whether to make thread joinable or not
			void join(bool val);
			//display getter
			UI::DisplayPtr getDisplay();
			//get instance
			static std::shared_ptr<FalloutEngine> getInstance();
			//application setter
			void setApplication(UI::ApplicationPtr app);
		private:
			//this is a private constructor
			FalloutEngine();
			//private init function for the thread to run, in winAPI Window is attached to the thread that made it
			bool init();
			//gameloop gate function
			void gameLoop();
			//private function that handles gameloop
			void input();
			void update(TimeStep step);
			void render();

			
			/** @brief	The instance pointer for the engine. */
			static std::shared_ptr<FalloutEngine> _instance;

			
			/** @brief	The main working thread to init. */
			std::thread* _mainThread;

			/** @brief	The display window. */
			UI::DisplayPtr _display;
			
			/** @brief	The Graphics API. */
			GraphicsHandle _api;

			
			/** @brief	The graphics device. */
			Managers::IGXManagerPtr _graphicsDevice;

			
			/** @brief	true if thread joinable. */
			bool _joinable;

			
			/** @brief	The keyboard pointer that holds the keyboard. */
			Input::IKeyboardPtr _keyboard;

			/** @brief	The mouse pointer that holds the mouse class. */
			Input::IMousePtr _mouse;

			
			/** @brief	The application pointer that holds your app. */
			UI::ApplicationPtr _application;
			
			/** @brief	The renderer to be used in the engine. */
			IRendererPtr _renderer;

			/** @brief	true to cleaning up for closing the engine. */
			bool _cleaningUp;
		};
		typedef std::shared_ptr<FalloutEngine> FalloutEnginePtr;
	}
}