#include<iostream>
#include"DXManager.h"
#include"../Core/FalloutEngine.h"
#include"DXKeyboard.h"
#include"DXMouse.h"

using namespace std;
using namespace Fallout::Managers;
using namespace Fallout::UI;

//linking libraries
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dx11.lib")
#pragma comment (lib, "d3dx10.lib")

DXManager::DXManager(){
	_window = NULL;
	_swapChain = NULL;
	_device = NULL;
	_deviceContext = NULL;
}

DXManager::~DXManager(){
	if (_swapChain)
		_swapChain->Release();
	if (_device)
		_device->Release();
	if (_deviceContext)
		_deviceContext->Release();
	if (_window)
		delete _window;
}

bool DXManager::init(DisplayPtr display){
	_window = WinWindow::getInstance();
	//init window for DX
	_window->init(display);
	//init the DX itself
	//swap chain desc
	DXGI_SWAP_CHAIN_DESC scd;
	ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));

	scd.BufferCount = 1;
	scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	scd.OutputWindow = _window->getHandle();
	scd.SampleDesc.Count = 4;
	scd.Windowed = TRUE;

	D3D11CreateDeviceAndSwapChain(NULL,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		NULL,
		NULL,
		NULL,
		D3D11_SDK_VERSION,
		&scd,
		&_swapChain,
		&_device,
		NULL,
		&_deviceContext);
	ID3D11Texture2D* backBuffer;
	_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBuffer);

	_device->CreateRenderTargetView(backBuffer, NULL, &_backBuffer);
	backBuffer->Release();

	_deviceContext->OMSetRenderTargets(1, &_backBuffer, NULL);
	ZeroMemory(&_viewport, sizeof(D3D11_VIEWPORT));

	_viewport.TopLeftX = 0;
	_viewport.TopLeftY = 0;
	_viewport.Width = display->_width;
	_viewport.Height = display->_height;

	_deviceContext->RSSetViewports(1, &_viewport);
	return true;
}
void DXManager::start(){
	//assigning functions
	_window->display = &DXManager::display;
	_window->reshape = &DXManager::reshape;
	_window->keyboardKeyDown = &Fallout::Input::DXKeyboard::keyboardDown;
	_window->keyboardKeyUp = &Fallout::Input::DXKeyboard::keyboardUp;
	_window->mouseButton = &Fallout::Input::DXMouse::mouseButton;
	_window->mouseMove = &Fallout::Input::DXMouse::mouseMove;
	_window->start();
	return;
}
void DXManager::display(){
	//render function
	
	Core::FalloutEngine::getInstance()->gameLoop();
	//instance->_deviceContext->ClearRenderTargetView(instance->_backBuffer, D3DXCOLOR(0, 0, 0, 0));


}
void DXManager::idle(){
	//do this when idle
}
void DXManager::reshape(int w, int h){
	// do this when the window resizes
	cout << w << "||" << h << endl;
}
void DXManager::clearBuffers(){
	_deviceContext->ClearRenderTargetView(_backBuffer, D3DXCOLOR(0, 0, 0, 0));
}
void DXManager::swapBuffers(){
	auto instance = dynamic_cast<Managers::DXManager*>(Core::FalloutEngine::getInstance()->getGraphicsDevice().get());
	instance->_swapChain->Present(0, 0);
	instance = NULL;
}

WinWindow* DXManager::getWindow() const{
	return _window;
}