#include<iostream>
#include"Core\FalloutCore.h"
#include"UI\FalloutUI.h"
using namespace std;
using namespace Fallout::Core;
using namespace Fallout::UI;

int main(){
	FalloutEnginePtr engine = FalloutEngine::getInstance();
	bool initOk = engine->init(DisplayPtr(new Display(800,600,"Test")),GraphicsHandle::OPENGL);
	if (initOk){
		engine->join(true);
		engine->start();
	}

	return 0;
}