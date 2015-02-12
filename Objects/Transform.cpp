#include "Transform.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
using namespace Fallout::Objects;
using namespace std;
using namespace glm;

Transform::Transform(const Transform& tr){
	position = tr.position;
	rotation = tr.rotation;
	scale = tr.scale;
}

Transform::Transform(glm::vec3 pos /* = glm::vec3(0 ,0,0)*/, glm::quat rot /* = glm::quat(0,0,0,0)*/, glm::vec3 scl /* = glm::vec3(0,0,0)*/){
	position = pos;
	rotation = rot;
	scale = scl;
}

mat4 Transform::getMatrix(){
	mat4 trns= glm::translate(mat4(1.0f),position);
	mat4 rot = glm::toMat4(rotation);
	mat4 scl = glm::scale(mat4(1.0f),scale);

	return trns * rot * scl ;
}