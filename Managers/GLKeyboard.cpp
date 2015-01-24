#include"GLKeyboard.h"
#include<GL\freeglut.h>
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
		_data.insert(make_pair(Keys::A, KeyState::State_Down));
		break;
	case 'b':
		_data.insert(make_pair(Keys::B, KeyState::State_Down));
		break;
	case 'c':
		_data.insert(make_pair(Keys::C, KeyState::State_Down));
		break;
	case 'd':
		_data.insert(make_pair(Keys::D, KeyState::State_Down));
		break;
	case 'e':
		_data.insert(make_pair(Keys::E, KeyState::State_Down));
		break;
	case 'f':
		_data.insert(make_pair(Keys::F, KeyState::State_Down));
		break;
	case 'g':
		_data.insert(make_pair(Keys::G, KeyState::State_Down));
		break;
	case 'h':
		_data.insert(make_pair(Keys::H, KeyState::State_Down));
		break;
	case 'i':
		_data.insert(make_pair(Keys::I, KeyState::State_Down));
		break;
	case 'j':
		_data.insert(make_pair(Keys::J, KeyState::State_Down));
		break;
	case 'k':
		_data.insert(make_pair(Keys::K, KeyState::State_Down));
		break;
	case 'l':
		_data.insert(make_pair(Keys::L, KeyState::State_Down));
		break;
	case 'm':
		_data.insert(make_pair(Keys::M, KeyState::State_Down));
		break;
	case 'n':
		_data.insert(make_pair(Keys::N, KeyState::State_Down));
		break;
	case 'o':
		_data.insert(make_pair(Keys::O, KeyState::State_Down));
		break;
	case 'p':
		_data.insert(make_pair(Keys::P, KeyState::State_Down));
		break;
	case 'q':
		_data.insert(make_pair(Keys::Q, KeyState::State_Down));
		break;
	case 'r':
		_data.insert(make_pair(Keys::R, KeyState::State_Down));
		break;
	case 's':
		_data.insert(make_pair(Keys::S, KeyState::State_Down));
		break;
	case 't':
		_data.insert(make_pair(Keys::T, KeyState::State_Down));
		break;
	case 'u':
		_data.insert(make_pair(Keys::U, KeyState::State_Down));
		break;
	case 'v':
		_data.insert(make_pair(Keys::V, KeyState::State_Down));
		break;
	case 'w':
		_data.insert(make_pair(Keys::W, KeyState::State_Down));
		break;
	case 'x':
		_data.insert(make_pair(Keys::X, KeyState::State_Down));
		break;
	case 'y':
		_data.insert(make_pair(Keys::Y, KeyState::State_Down));
		break;
	case 'z':
		_data.insert(make_pair(Keys::Z, KeyState::State_Down));
		break;
	case '0':
		_data.insert(make_pair(Keys::Num_0, KeyState::State_Down));
		break;
	case '1':
		_data.insert(make_pair(Keys::Num_1, KeyState::State_Down));
		break;
	case '2':
		_data.insert(make_pair(Keys::Num_2, KeyState::State_Down));
		break;
	case '3':
		_data.insert(make_pair(Keys::Num_3, KeyState::State_Down));
		break;
	case '4':
		_data.insert(make_pair(Keys::Num_4, KeyState::State_Down));
		break;
	case '5':
		_data.insert(make_pair(Keys::Num_5, KeyState::State_Down));
		break;
	case '6':
		_data.insert(make_pair(Keys::Num_6, KeyState::State_Down));
		break;
	case '7':
		_data.insert(make_pair(Keys::Num_7, KeyState::State_Down));
		break;
	case '8':
		_data.insert(make_pair(Keys::Num_8, KeyState::State_Down));
		break;
	case '9':
		_data.insert(make_pair(Keys::Num_9, KeyState::State_Down));
		break;
	case 27:
		_data.insert(make_pair(Keys::Esc, KeyState::State_Down));
		break;
	case '-':
		_data.insert(make_pair(Keys::Minus, KeyState::State_Down));
		break;
	case '+':
		_data.insert(make_pair(Keys::Plus, KeyState::State_Down));
		break;
	case '.':
		_data.insert(make_pair(Keys::Period, KeyState::State_Down));
		break;
	case ' ':
		_data.insert(make_pair(Keys::Space, KeyState::State_Down));
		break;
	case 13:
		_data.insert(make_pair(Keys::Enter, KeyState::State_Down));
		break;
	case 8:
		_data.insert(make_pair(Keys::Backspace, KeyState::State_Down));
		break;
	case 9:
		_data.insert(make_pair(Keys::Tab, KeyState::State_Down));
		break;
	case '=':
		_data.insert(make_pair(Keys::Equals, KeyState::State_Down));
		break;
	case '>':
		_data.insert(make_pair(Keys::Greater, KeyState::State_Down));
		break;
	case '<':
		_data.insert(make_pair(Keys::Less, KeyState::State_Down));
		break;
	case ':':
		_data.insert(make_pair(Keys::Colon, KeyState::State_Down));
		break;
	case ';':
		_data.insert(make_pair(Keys::SemiColon, KeyState::State_Down));
		break;
	case '?':
		_data.insert(make_pair(Keys::Question, KeyState::State_Down));
		break;
	case '\\':
		_data.insert(make_pair(Keys::Backslash, KeyState::State_Down));
		break;
	case '_':
		_data.insert(make_pair(Keys::Underscore, KeyState::State_Down));
		break;
	case 127:
		_data.insert(make_pair(Keys::Delete, KeyState::State_Down));
		break;
	default:
		break;
	}
}

void GLKeyboard::keyboardUpFunc(unsigned char key, int x, int y){
	switch (key)
	{
	case 'a':
		_data.insert(make_pair(Keys::A, KeyState::State_Up));
		break;
	case 'b':
		_data.insert(make_pair(Keys::B, KeyState::State_Up));
		break;
	case 'c':
		_data.insert(make_pair(Keys::C, KeyState::State_Up));
		break;
	case 'd':
		_data.insert(make_pair(Keys::D, KeyState::State_Up));
		break;
	case 'e':
		_data.insert(make_pair(Keys::E, KeyState::State_Up));
		break;
	case 'f':
		_data.insert(make_pair(Keys::F, KeyState::State_Up));
		break;
	case 'g':
		_data.insert(make_pair(Keys::G, KeyState::State_Up));
		break;
	case 'h':
		_data.insert(make_pair(Keys::H, KeyState::State_Up));
		break;
	case 'i':
		_data.insert(make_pair(Keys::I, KeyState::State_Up));
		break;
	case 'j':
		_data.insert(make_pair(Keys::J, KeyState::State_Up));
		break;
	case 'k':
		_data.insert(make_pair(Keys::K, KeyState::State_Up));
		break;
	case 'l':
		_data.insert(make_pair(Keys::L, KeyState::State_Up));
		break;
	case 'm':
		_data.insert(make_pair(Keys::M, KeyState::State_Up));
		break;
	case 'n':
		_data.insert(make_pair(Keys::N, KeyState::State_Up));
		break;
	case 'o':
		_data.insert(make_pair(Keys::O, KeyState::State_Up));
		break;
	case 'p':
		_data.insert(make_pair(Keys::P, KeyState::State_Up));
		break;
	case 'q':
		_data.insert(make_pair(Keys::Q, KeyState::State_Up));
		break;
	case 'r':
		_data.insert(make_pair(Keys::R, KeyState::State_Up));
		break;
	case 's':
		_data.insert(make_pair(Keys::S, KeyState::State_Up));
		break;
	case 't':
		_data.insert(make_pair(Keys::T, KeyState::State_Up));
		break;
	case 'u':
		_data.insert(make_pair(Keys::U, KeyState::State_Up));
		break;
	case 'v':
		_data.insert(make_pair(Keys::V, KeyState::State_Up));
		break;
	case 'w':
		_data.insert(make_pair(Keys::W, KeyState::State_Up));
		break;
	case 'x':
		_data.insert(make_pair(Keys::X, KeyState::State_Up));
		break;
	case 'y':
		_data.insert(make_pair(Keys::Y, KeyState::State_Up));
		break;
	case 'z':
		_data.insert(make_pair(Keys::Z, KeyState::State_Up));
		break;
	case '0':
		_data.insert(make_pair(Keys::Num_0, KeyState::State_Up));
		break;
	case '1':
		_data.insert(make_pair(Keys::Num_1, KeyState::State_Up));
		break;
	case '2':
		_data.insert(make_pair(Keys::Num_2, KeyState::State_Up));
		break;
	case '3':
		_data.insert(make_pair(Keys::Num_3, KeyState::State_Up));
		break;
	case '4':
		_data.insert(make_pair(Keys::Num_4, KeyState::State_Up));
		break;
	case '5':
		_data.insert(make_pair(Keys::Num_5, KeyState::State_Up));
		break;
	case '6':
		_data.insert(make_pair(Keys::Num_6, KeyState::State_Up));
		break;
	case '7':
		_data.insert(make_pair(Keys::Num_7, KeyState::State_Up));
		break;
	case '8':
		_data.insert(make_pair(Keys::Num_8, KeyState::State_Up));
		break;
	case '9':
		_data.insert(make_pair(Keys::Num_9, KeyState::State_Up));
		break;
	case 27:
		_data.insert(make_pair(Keys::Esc, KeyState::State_Up));
		break;
	case '-':
		_data.insert(make_pair(Keys::Minus, KeyState::State_Up));
		break;
	case '+':
		_data.insert(make_pair(Keys::Plus, KeyState::State_Up));
		break;
	case '.':
		_data.insert(make_pair(Keys::Period, KeyState::State_Up));
		break;
	case ',':
		_data.insert(make_pair(Keys::Comma, KeyState::State_Up));
		break;
	case ' ':
		_data.insert(make_pair(Keys::Space, KeyState::State_Up));
		break;
	case 13:
		_data.insert(make_pair(Keys::Enter, KeyState::State_Up));
		break;
	case 8:
		_data.insert(make_pair(Keys::Backspace, KeyState::State_Up));
		break;
	case 9:
		_data.insert(make_pair(Keys::Tab, KeyState::State_Up));
		break;
	case '=':
		_data.insert(make_pair(Keys::Equals, KeyState::State_Up));
		break;
	case '>':
		_data.insert(make_pair(Keys::Greater, KeyState::State_Up));
		break;
	case '<':
		_data.insert(make_pair(Keys::Less, KeyState::State_Up));
		break;
	case ':':
		_data.insert(make_pair(Keys::Colon, KeyState::State_Up));
		break;
	case ';':
		_data.insert(make_pair(Keys::SemiColon, KeyState::State_Up));
		break;
	case '?':
		_data.insert(make_pair(Keys::Question, KeyState::State_Up));
		break;
	case '\\':
		_data.insert(make_pair(Keys::Backslash, KeyState::State_Up));
		break;
	case '_':
		_data.insert(make_pair(Keys::Underscore, KeyState::State_Up));
		break;
	case 127:
		_data.insert(make_pair(Keys::Delete, KeyState::State_Up));
		break;
	default:
		break;
	}
}

void GLKeyboard::keyboardSpecialUpFunc(int key, int x, int y){
	switch (key){
	case GLUT_KEY_SHIFT_L:
		_data.insert(make_pair(Keys::Left_Shift, KeyState::State_Up));
		break;
	case GLUT_KEY_SHIFT_R:
		_data.insert(make_pair(Keys::Right_Shift, KeyState::State_Up));
		break;
	case GLUT_KEY_ALT_L:
		_data.insert(make_pair(Keys::Left_Alt, KeyState::State_Up));
		break;
	case GLUT_KEY_ALT_R:
		_data.insert(make_pair(Keys::Right_Alt, KeyState::State_Up));
		break;
	case GLUT_KEY_CTRL_L:
		_data.insert(make_pair(Keys::Left_Ctrl, KeyState::State_Up));
		break;
	case GLUT_KEY_CTRL_R:
		_data.insert(make_pair(Keys::Right_Ctrl, KeyState::State_Up));
		break;
	case GLUT_KEY_END:
		_data.insert(make_pair(Keys::End, KeyState::State_Up));
		break;
	case GLUT_KEY_HOME:
		_data.insert(make_pair(Keys::Home, KeyState::State_Up));
		break;
	case GLUT_KEY_INSERT:
		_data.insert(make_pair(Keys::Insert, KeyState::State_Up));
		break;
	case GLUT_KEY_PAGE_UP:
		_data.insert(make_pair(Keys::PageUp, KeyState::State_Up));
		break;
	case GLUT_KEY_PAGE_DOWN:
		_data.insert(make_pair(Keys::PageDown, KeyState::State_Up));
		break;
	case GLUT_KEY_UP:
		_data.insert(make_pair(Keys::Up, KeyState::State_Up));
		break;
	case GLUT_KEY_DOWN:
		_data.insert(make_pair(Keys::Down, KeyState::State_Up));
		break;
	case GLUT_KEY_RIGHT:
		_data.insert(make_pair(Keys::Right, KeyState::State_Up));
		break;
	case GLUT_KEY_LEFT:
		_data.insert(make_pair(Keys::Left, KeyState::State_Up));
		break;
	case GLUT_KEY_F1:
		_data.insert(make_pair(Keys::F1, KeyState::State_Up));
		break;
	case GLUT_KEY_F2:
		_data.insert(make_pair(Keys::F2, KeyState::State_Up));
		break;
	case GLUT_KEY_F3:
		_data.insert(make_pair(Keys::F3, KeyState::State_Up));
		break;
	case GLUT_KEY_F4:
		_data.insert(make_pair(Keys::F4, KeyState::State_Up));
		break;
	case GLUT_KEY_F5:
		_data.insert(make_pair(Keys::F5, KeyState::State_Up));
		break;
	case GLUT_KEY_F6:
		_data.insert(make_pair(Keys::F6, KeyState::State_Up));
		break;
	case GLUT_KEY_F7:
		_data.insert(make_pair(Keys::F7, KeyState::State_Up));
		break;
	case GLUT_KEY_F8:
		_data.insert(make_pair(Keys::F8, KeyState::State_Up));
		break;
	case GLUT_KEY_F9:
		_data.insert(make_pair(Keys::F9, KeyState::State_Up));
		break;
	case GLUT_KEY_F10:
		_data.insert(make_pair(Keys::F10, KeyState::State_Up));
		break;
	case GLUT_KEY_F11:
		_data.insert(make_pair(Keys::F11, KeyState::State_Up));
		break;
	case GLUT_KEY_F12:
		_data.insert(make_pair(Keys::F12, KeyState::State_Up));
		break;
	default:
		break;
	}
}
void GLKeyboard::keyboardSpecialDownFunc(int key, int x, int y){
	switch (key){
	case GLUT_KEY_SHIFT_L:
		_data.insert(make_pair(Keys::Left_Shift, KeyState::State_Down));
		break;
	case GLUT_KEY_SHIFT_R:
		_data.insert(make_pair(Keys::Right_Shift, KeyState::State_Down));
		break;
	case GLUT_KEY_ALT_L:
		_data.insert(make_pair(Keys::Left_Alt, KeyState::State_Down));
		break;
	case GLUT_KEY_ALT_R:
		_data.insert(make_pair(Keys::Right_Alt, KeyState::State_Down));
		break;
	case GLUT_KEY_CTRL_L:
		_data.insert(make_pair(Keys::Left_Ctrl, KeyState::State_Down));
		break;
	case GLUT_KEY_CTRL_R:
		_data.insert(make_pair(Keys::Right_Ctrl, KeyState::State_Down));
		break;
	case GLUT_KEY_END:
		_data.insert(make_pair(Keys::End, KeyState::State_Down));
		break;
	case GLUT_KEY_HOME:
		_data.insert(make_pair(Keys::Home, KeyState::State_Down));
		break;
	case GLUT_KEY_INSERT:
		_data.insert(make_pair(Keys::Insert, KeyState::State_Down));
		break;
	case GLUT_KEY_PAGE_UP:
		_data.insert(make_pair(Keys::PageUp, KeyState::State_Down));
		break;
	case GLUT_KEY_PAGE_DOWN:
		_data.insert(make_pair(Keys::PageDown, KeyState::State_Down));
		break;
	case GLUT_KEY_UP:
		_data.insert(make_pair(Keys::Up, KeyState::State_Down));
		break;
	case GLUT_KEY_DOWN:
		_data.insert(make_pair(Keys::Down, KeyState::State_Down));
		break;
	case GLUT_KEY_RIGHT:
		_data.insert(make_pair(Keys::Right, KeyState::State_Down));
		break;
	case GLUT_KEY_LEFT:
		_data.insert(make_pair(Keys::Left, KeyState::State_Down));
		break;
	case GLUT_KEY_F1:
		_data.insert(make_pair(Keys::F1, KeyState::State_Down));
		break;
	case GLUT_KEY_F2:
		_data.insert(make_pair(Keys::F2, KeyState::State_Down));
		break;
	case GLUT_KEY_F3:
		_data.insert(make_pair(Keys::F3, KeyState::State_Down));
		break;
	case GLUT_KEY_F4:
		_data.insert(make_pair(Keys::F4, KeyState::State_Down));
		break;
	case GLUT_KEY_F5:
		_data.insert(make_pair(Keys::F5, KeyState::State_Down));
		break;
	case GLUT_KEY_F6:
		_data.insert(make_pair(Keys::F6, KeyState::State_Down));
		break;
	case GLUT_KEY_F7:
		_data.insert(make_pair(Keys::F7, KeyState::State_Down));
		break;
	case GLUT_KEY_F8:
		_data.insert(make_pair(Keys::F8, KeyState::State_Down));
		break;
	case GLUT_KEY_F9:
		_data.insert(make_pair(Keys::F9, KeyState::State_Down));
		break;
	case GLUT_KEY_F10:
		_data.insert(make_pair(Keys::F10, KeyState::State_Down));
		break;
	case GLUT_KEY_F11:
		_data.insert(make_pair(Keys::F11, KeyState::State_Down));
		break;
	case GLUT_KEY_F12:
		_data.insert(make_pair(Keys::F12, KeyState::State_Down));
		break;
	default:
		break;
	}
}