#pragma once
#include<iostream>
#include<memory>
#include<thread>
#include"../UI/Display.h"
#include"../Managers/IGXManager.h"

namespace Fallout{
	namespace Core{
		enum GraphicsHandle{ OPENGL, DIRECTX };
		class FalloutEngine{
		public: 
			~FalloutEngine();
			//init function takes display, Graphics handle
			bool init(UI::DisplayPtr display,GraphicsHandle type);
			//will take an application 
			void start();
			//get instance
			static std::shared_ptr<FalloutEngine> getInstance();
		private:
			//this is a private constructor
			FalloutEngine();
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
		};
		typedef std::shared_ptr<FalloutEngine> FalloutEnginePtr;
	}
}