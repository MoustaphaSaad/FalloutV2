#pragma once
#include "ITransformable.h"
#include "Component.h"
#include <memory>
namespace Fallout{
	namespace Objects{
		class GameObject;
		typedef std::shared_ptr<GameObject> GameObjectPtr;

		class GameObject:public ITransformable, public Component{
		public:

			/**
			 * @fn	GameObject::GameObject();
			 *
			 * @brief	Default constructor.
			 *
			 * @author	Moustapha Saad
			 * @date	13/02/2015
			 */

			GameObject();

			/**
			 * @fn	GameObject::GameObject(const GameObject&);
			 *
			 * @brief	Copy constructor.
			 *
			 * @author	Moustapha Saad
			 * @date	13/02/2015
			 *
			 * @param	parameter1	The first parameter.
			 */

			GameObject(const GameObject&);
			~GameObject();

			/**
			 * @fn	virtual void GameObject::input();
			 *
			 * @brief	Inputs this object.
			 *
			 * @author	Moustapha Saad
			 * @date	13/02/2015
			 */

			virtual void input();

			/**
			 * @fn	virtual void GameObject::update(Core::TimeStep);
			 *
			 * @brief	Updates the given parameter1.
			 *
			 * @author	Moustapha Saad
			 * @date	13/02/2015
			 *
			 * @param	parameter1	The first parameter.
			 */

			virtual void update(Core::TimeStep);

			/**
			 * @fn	virtual void GameObject::render();
			 *
			 * @brief	Renders this object.
			 *
			 * @author	Moustapha Saad
			 * @date	13/02/2015
			 */

			virtual void render();
		};
	}
}