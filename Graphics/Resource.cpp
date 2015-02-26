#include "Resource.h"
using namespace Fallout::Graphics;
using namespace std;

Resource::Resource(){
	type = Type::UNKNOWN;
}
Resource::~Resource(){

}

Resource::Type Resource::getType(){
	return type;
}