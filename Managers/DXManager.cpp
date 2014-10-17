#include<iostream>
#include"DXManager.h"
#include"../Core/FalloutEngine.h"
#include<D3D11.h>
#include<D3DX11.h>
#include<D3DX10.h>

using namespace std;
using namespace Fallout::Managers;
using namespace Fallout::UI;

//linking libraries
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dx11.lib")
#pragma comment (lib, "d3dx10.lib")

DXManager::DXManager(){
	_window = WinWindow();
}

DXManager::~DXManager(){

}

bool DXManager::init(DisplayPtr display){
	//init window for DX
	_window.init(display);
	return true;
}
void DXManager::start(){
	_window.start();
	return;
}
