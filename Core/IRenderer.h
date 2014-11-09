#pragma once
#include"../UI/Application.h"
namespace Fallout{
	namespace Core{
		class IRenderer{
		private:
			//current application that the engine runs
			UI::ApplicationPtr _application;
		public:
			IRenderer();
			~IRenderer();
			//main four function that will run the engine
			virtual void gameLoop();
			virtual void input();
			virtual void update();
			virtual void render();
		};
		typedef std::shared_ptr<IRenderer> IRendererPtr;
	}
}