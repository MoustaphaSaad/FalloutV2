#include "GameObject.h"
#include "../Core/Time.h"
#include <iostream>
using namespace Fallout::Objects;
using namespace std;

GameObject::GameObject(const GameObject& other){
	transform = other.transform;
}

GameObject::GameObject():ITransformable(){
}

GameObject::~GameObject()
{
}

void GameObject::input(){
}

void GameObject::update(Fallout::Core::TimeStep time){
}

void GameObject::render(){
}