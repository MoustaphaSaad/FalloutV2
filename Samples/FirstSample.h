#include"../Core/FalloutCore.h"
#include"../UI/FalloutUI.h"
using namespace Fallout::Core;
using namespace Fallout::UI;
namespace Fallout{
	namespace Samples{
		class FirstSample : public Application{
		public:
			FirstSample();
			~FirstSample();

			void init();
			void loadResources();
			void setupScene();

			void input();
			void update(TimeStep time);
			void render();
		};
	}
}