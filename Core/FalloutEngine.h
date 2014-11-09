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
#include"IRenderer.h"

namespace Fallout{
	namespace Core{
		enum GraphicsHandle{ OPENGL, DIRECTX };
		class FalloutEngine{
			friend class Fallout::Managers::GLManager;
			friend class Fallout::Managers::DXManager;
		public: 
			~FalloutEngine();
			//init function takes display, Graphics handle, and you can pass a custom renderer or it will be the defualt one
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

			//this is singelton pattern
			static std::shared_ptr<FalloutEngine> _instance;
			//working thread to init in start
			std::thread* _mainThread;
			//display window
			UI::DisplayPtr _display;
			//Graphics API
			GraphicsHandle _api;
			//Graphics Manager
			Managers::IGXManagerPtr _graphicsDevice;
			//bool to check if we'll join the thread or not
			bool _joinable;
			//keyboard manager
			Input::IKeyboardPtr _keyboard;
			//Application pointer
			UI::ApplicationPtr _application;
			//renderer this will
			IRendererPtr _renderer;
		};
		typedef std::shared_ptr<FalloutEngine> FalloutEnginePtr;
	}
}