#include<iostream>
#include"Core\FalloutCore.h"
#include"UI\FalloutUI.h"

using namespace std;
using namespace Fallout::Core;
using namespace Fallout::UI;

int main(){
	FalloutEnginePtr engine = FalloutEngine::getInstance();
	engine->init(DisplayPtr(new Display(800,600,"Test")),GraphicsHandle::OPENGL);
	engine->start();
	return 0;
}