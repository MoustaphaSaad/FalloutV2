#include"FirstSample.h"
#include<iostream>
using namespace std;
using namespace Fallout::Samples;
FirstSample::FirstSample():Application(){
	cerr << "constructor" << endl;
}
FirstSample::~FirstSample(){
	cerr << "destructor" << endl;
}

void FirstSample::init(){
	cerr << "init" << endl;
}
void FirstSample::loadResources(){
	cerr << "load resources" << endl;
}
void FirstSample::setupScene(){
	cerr << "setup scene" << endl;
}

void FirstSample::input(){
	cerr << "input" << endl;
}
void FirstSample::update(){
	cerr << "update" << endl;
}
void FirstSample::render(){
	cerr << "render" << endl;
}