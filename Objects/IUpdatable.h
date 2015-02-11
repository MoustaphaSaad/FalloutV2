#pragma once
#include"../Core/TimeStep.h"
namespace Fallout{
	namespace Objects{
		class IUpdatable{
		public:

			/**
			 * @fn	virtual void IUpdatable::input() = 0;
			 *
			 * @brief	handles input of this object.
			 *
			 * @author	Moustapha Saad
			 * @date	05/02/2015
			 */

			virtual void input() = 0;

			/**
			 * @fn	virtual void IUpdatable::update(Core::TimeStep time) = 0;
			 *
			 * @brief	Updates the given time.
			 *
			 * @author	Moustapha Saad
			 * @date	05/02/2015
			 *
			 * @param	time	The time step.
			 */

			virtual void update(Core::TimeStep time) = 0;
		};
	}
}