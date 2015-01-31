#include"WinWindow.h"
#include"../Managers/DXManager.h"
#include<iostream>
#include <windowsx.h>
using namespace std;
using namespace Fallout::UI;
WinWindow* WinWindow::_instance = NULL;
WinWindow::WinWindow(){
	_handle = NULL;
	display = NULL;
	reshape = NULL;
	keyboardKeyDown = NULL;
	keyboardKeyUp = NULL;
	mouseButton = NULL;
}
HWND WinWindow::getHandle(){
	return _handle;
}
LRESULT CALLBACK WinWindow::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// sort through and find what code to run for the message given
	switch (message)
	{
		// this message is read when the window is closed
	case WM_DESTROY:
		// close the application entirely
		PostQuitMessage(0);
		return 0;
		break;
	//resize event
	case WM_SIZE:
		if (_instance->reshape)
			_instance->reshape(LOWORD(lParam), HIWORD(lParam));
		break;
	//keyboard key down event
	case WM_KEYDOWN:
		if (_instance->keyboardKeyDown)
			_instance->keyboardKeyDown(wParam);
		break;
	case WM_KEYUP:
		if(_instance->keyboardKeyUp)
			_instance->keyboardKeyUp(wParam);
		break;
	case WM_LBUTTONDOWN:
		if(_instance->mouseButton)
			_instance->mouseButton(0,0);
		break;
	case WM_LBUTTONUP:
		if(_instance->mouseButton)
			_instance->mouseButton(0,1);
		break;
	case WM_RBUTTONDOWN:
		if(_instance->mouseButton)
			_instance->mouseButton(2,0);
		break;
	case WM_RBUTTONUP:
		if(_instance->mouseButton)
			_instance->mouseButton(2,1);
		break;
	case WM_MBUTTONDOWN:
		if(_instance->mouseButton)
			_instance->mouseButton(1,0);
		break;
	case WM_MBUTTONUP:
		if(_instance->mouseButton)
			_instance->mouseButton(1,1);
		break;
	case WM_MOUSEMOVE:
		if(_instance->mouseMove)
			_instance->mouseMove(GET_X_LPARAM(lParam),GET_Y_LPARAM(lParam));
		break;
	default:
		break;
	}

	// Handle any messages the switch statement didn't
	return DefWindowProc(hWnd, message, wParam, lParam);
}
WinWindow* WinWindow::getInstance(){
	if (_instance == NULL){
		_instance = new WinWindow();
	}
	return _instance;
}
std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}
bool WinWindow::init(DisplayPtr display){
	//window info
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = _instance->WindowProc;
	wc.hInstance = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = L"WindowClass1";

	RegisterClassEx(&wc);

	RECT wr = { 0, 0, display->_width, display->_height };    // set the size, but not the position
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);    // adjust the size

	this->_handle = CreateWindowEx(NULL,
		L"WindowClass1",
		s2ws(display->_title).c_str(),
		WS_OVERLAPPEDWINDOW,
		100,
		100,
		wr.right - wr.left,
		wr.bottom - wr.top,
		NULL,
		NULL,
		NULL,
		NULL);
	ShowWindow(_handle, SW_SHOW);
	_instance->_handle = _handle;
	return true;
}
void WinWindow::start(){
	MSG msg;

	// wait for the next message in the queue, store the result in 'msg'
	while (true)
	{
		if (PeekMessage(&msg,_handle, 0, 0, PM_REMOVE)){
			// translate keystroke messages into the right format
			TranslateMessage(&msg);

			// send the message to the WindowProc function
			DispatchMessage(&msg);
			if (msg.message == WM_QUIT || msg.message == WM_DESTROY)
				break;
		}
		else{
			if (_instance->display)
				_instance->display();
			//call engine functions
		}
	}
}