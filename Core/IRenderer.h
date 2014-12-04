#pragma once
#include"../UI/Application.h"
#include"TimeStep.h"
namespace Fallout{
	namespace Core{
		class IRenderer{
		private:
			//current application that the engine runs
			Fallout::UI::ApplicationPtr _application;
		public:
			IRenderer();
			~IRenderer();
			//main four function that will run the engine
			virtual void input();
			virtual void update(TimeStep time);
			virtual void render();
			void setApplication(UI::ApplicationPtr app);
		};
		typedef std::shared_ptr<IRenderer> IRendererPtr;
	}
}