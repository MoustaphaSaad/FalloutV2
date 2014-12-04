#include"IRenderer.h"
#include"FalloutEngine.h"
using namespace Fallout::Core;
using namespace Fallout::UI;
IRenderer::IRenderer(){
	_application = nullptr;
}
IRenderer::~IRenderer(){
	_application = nullptr;
}
void IRenderer::input(){
	if (_application)
		_application->input();
}
void IRenderer::update(TimeStep time){
	if (_application)
		_application->update(time);
}
void IRenderer::render(){
	FalloutEngine::getInstance()->getGraphicsDevice()->clearBuffers();
	if (_application)
		_application->render();
	FalloutEngine::getInstance()->getGraphicsDevice()->swapBuffers();
}
void IRenderer::setApplication(ApplicationPtr app){
	_application = app;
}