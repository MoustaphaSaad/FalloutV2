#include "GameObject.h"
#include "../Core/Time.h"
#include <iostream>
using namespace Fallout::Objects;
using namespace std;

GameObject::GameObject(const GameObject& other){
	transform = other.transform;
}

GameObject::GameObject():ITransformable(){
	cerr<<"Constructor"<<endl;
}

GameObject::~GameObject()
{
	cerr<<"Destructor"<<endl;
}

void GameObject::input(){
	cerr<<"Input"<<endl;
}

void GameObject::update(Fallout::Core::TimeStep time){
	cerr<<"Update = "<<time._elapsedTime<<endl;
}

void GameObject::render(){
	cerr<<"Render"<<endl;
}