#include<iostream>
#include"DXManager.h"
#include<D3D11.h>
#include<D3DX11.h>
#include<D3DX10.h>

using namespace Fallout::Managers;
using namespace Fallout::UI;

//linking libraries
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dx11.lib")
#pragma comment (lib, "d3dx10.lib")

DXManager::DXManager(){

}

DXManager::~DXManager(){

}

bool DXManager::init(DisplayPtr display){
	std::cerr << "DXINIT" << std::endl;
	return true;
}
void DXManager::start(){
	std::cerr << "DXSTART" << std::endl;
	return;
}
