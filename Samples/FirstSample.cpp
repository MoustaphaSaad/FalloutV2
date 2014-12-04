#include"FirstSample.h"
#include<iostream>
using namespace std;
using namespace Fallout::Samples;
FirstSample::FirstSample():Application(){
}
FirstSample::~FirstSample(){
	cerr << "destructor" << endl;
}

void FirstSample::init(){
	Time::setFrameLimit(10);
}
void FirstSample::loadResources(){
}
void FirstSample::setupScene(){
}

void FirstSample::input(){
}
void FirstSample::update(TimeStep time){

}
void FirstSample::render(){
}