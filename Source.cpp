#include<iostream>
#include<string>
#include"Core\FalloutCore.h"
#include"UI\FalloutUI.h"
#include"Math\FalloutMath.h"
using namespace std;
using namespace Fallout::Core;
using namespace Fallout::UI;
using namespace Fallout::Math;

int main(){
	/*FalloutEnginePtr engine = FalloutEngine::getInstance();
	engine->setup(DisplayPtr(new Display(800,600,"TestGL")),GraphicsHandle::DIRECTX);
	engine->join(true);
	engine->start();*/
	/*string line;
	while (getline(cin, line)){
		if (line == "close")
			break;
	}*/
	Vector2<float> koko(100,75);
	Vector2<float> koko2(50);

	cout << koko.negate().toString() << endl;
	return 0;
}