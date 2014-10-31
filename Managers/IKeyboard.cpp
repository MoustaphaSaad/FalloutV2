#include"IKeyboard.h"
using namespace Fallout::Input;
using namespace std;
//init keyboard
map<IKeyboard::Keys, IKeyboard::KeyState> IKeyboard::_data = map<IKeyboard::Keys, IKeyboard::KeyState>();

IKeyboard::IKeyboard(){
	_data.clear();
}
IKeyboard::~IKeyboard(){
	_data.clear();
}
IKeyboard::KeyState IKeyboard::getKey(IKeyboard::Keys key){
	map<IKeyboard::Keys, IKeyboard::KeyState>::iterator it;
	it = _data.find(key);
	if (it == _data.end())
		return IKeyboard::KeyState::None;
	return it->second;
}

void IKeyboard::update(){

}