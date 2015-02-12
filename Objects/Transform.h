#pragma once
#include<glm/glm.hpp>
#include<glm/gtc/quaternion.hpp>
#include<memory>
namespace Fallout{
	namespace Objects{
		class Transform{
		public:

			/** @brief	The position. */
			glm::vec3 position;

			/** @brief	The rotation. */
			glm::quat rotation;

			/** @brief	The scale. */
			glm::vec3 scale;

			/**
			 * @fn	Transform::Transform(glm::vec3 pos = glm::vec3(0,0,0), glm::quat rot = glm::quat(0,0,0,0), glm::vec3 scl = glm::vec3(0,0,0));
			 *
			 * @brief	Constructor.
			 *
			 * @author	Moustapha Saad
			 * @date	12/02/2015
			 *
			 * @param	pos	The position.
			 * @param	rot	The rotation.
			 * @param	scl	The scale.
			 */

			Transform(glm::vec3 pos = glm::vec3(0,0,0),
					  glm::quat rot = glm::quat(0,0,0,0),
					  glm::vec3 scl = glm::vec3(0,0,0));

			/**
			 * @fn	Transform::Transform(const Transform&);
			 *
			 * @brief	Copy constructor.
			 *
			 * @author	Moustapha Saad
			 * @date	13/02/2015
			 *
			 * @param	parameter1	The first parameter.
			 */

			Transform(const Transform&);

			/**
			 * @fn	glm::mat4 Transform::getMatrix();
			 *
			 * @brief	Gets the matrix.
			 *
			 * @author	Moustapha Saad
			 * @date	12/02/2015
			 *
			 * @return	The transformation matrix.
			 */

			glm::mat4 getMatrix();
		};
		typedef std::shared_ptr<Transform> TransformPtr;
	}
}