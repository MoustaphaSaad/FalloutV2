#include<iostream>
#include<string>
#include"Core\FalloutCore.h"
#include"UI\FalloutUI.h"
#include<glm\glm.hpp>
#include<glm\gtc\quaternion.hpp>
#include<glm\matrix.hpp>

using namespace glm;
using namespace std;
using namespace Fallout::Core;
using namespace Fallout::UI;

int main(){
	FalloutEnginePtr engine = FalloutEngine::getInstance();
	engine->init(DisplayPtr(new Display(800,600,"Test")),GraphicsHandle::DIRECTX);
	engine->join(true);
	engine->start();
	//quat e(1, 2, 3, 4);
	//mat4 p = glm::mat4_cast(e);

	return 0;
}