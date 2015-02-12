#pragma once
#include "IUpdatable.h"
#include "IRenderable.h"
namespace Fallout{
	namespace Objects{
		class Component:public IUpdatable,public IRenderable{
		public:
			virtual void input() override{
				
			}
			virtual void update(Core::TimeStep time) override{
				
			}
			virtual void render() override{
				
			}
		};
	}
}