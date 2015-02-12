#include<iostream>
#include<string>
#include"Core\FalloutCore.h"
#include"UI\FalloutUI.h"
#include"Samples\FirstSample.h"
using namespace std;
using namespace Fallout::Core;
using namespace Fallout::UI;

int main(){
	FalloutEnginePtr engine = FalloutEngine::getInstance();
	engine->setup(DisplayPtr(new Display(800, 600, "TestGL")), GraphicsHandle::DIRECTX);
	engine->setApplication(ApplicationPtr(new Fallout::Samples::FirstSample()));
	engine->start();
	string line = "";
	while (getline(cin, line)){
		if (line == "close")
			break;
	}
	engine.reset();
	return 0;
}