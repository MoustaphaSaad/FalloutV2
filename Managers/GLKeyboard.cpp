#include"GLKeyboard.h"
#include<utility>
using namespace std;
using namespace Fallout::Input;
void GLKeyboard::update(){
	IKeyboard::_data.clear();
}
void GLKeyboard::keyboardDownFunc(unsigned char key, int x, int y){
	switch (key)
	{
	case 'a':
		_data.insert(make_pair(Keys::A, KeyState::Down));
		break;
	case 'b':
		_data.insert(make_pair(Keys::B, KeyState::Down));
		break;
	case 'c':
		_data.insert(make_pair(Keys::C, KeyState::Down));
		break;
	default:
		break;
	}
}