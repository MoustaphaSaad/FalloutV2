#include<iostream>
#include<string>
#include"Core\FalloutCore.h"
#include"UI\FalloutUI.h"
using namespace std;
using namespace Fallout::Core;
using namespace Fallout::UI;

int main(){
	FalloutEnginePtr engine = FalloutEngine::getInstance();
	engine->setup(DisplayPtr(new Display(800,600,"TestGL")),GraphicsHandle::DIRECTX);
	engine->join(false);
	engine->start();
	string line;
	while (getline(cin, line)){
		if (line == "close")
			break;
	}

	return 0;
}