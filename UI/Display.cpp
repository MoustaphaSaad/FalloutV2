#include"Display.h"
using namespace Fallout::UI;
Display::Display(){
	_width = 800;
	_height = 600;
	_title = "FalloutEngineV2.0";
}
Display::Display(int x, int y, std::string t){
	_width = x;
	_height = y;
	_title = t;
}
Display::~Display(){
	_title.clear();
}
float Display::getAspectRatio(){
	return _width / _height;
}

