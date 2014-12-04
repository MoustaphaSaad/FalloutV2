#pragma once
#include<memory>
#include"../Core/TimeStep.h"
namespace Fallout{
	namespace UI{
		class Application{
		public:
			Application();
			~Application();

			//setup function called once
			virtual void init();
			//setup scene function called once
			virtual void setupScene();
			//load Resources function called once
			virtual void loadResources();

			//functions that will be called every frame
			//input function
			virtual void input();
			//update it will take the timestep later
			virtual void update(Fallout::Core::TimeStep time);
			//render function
			virtual void render();
		};
		typedef std::shared_ptr<Application> ApplicationPtr;
	}
}