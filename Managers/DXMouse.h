#pragma once
#include "IMouse.h"
namespace Fallout{
	namespace Managers{
		class DXManager;
	}
	namespace Input{
		class DXMouse : public IMouse{
			friend class Managers::DXManager;
		private:

			/**
			 * @fn	static void DXMouse::mouseButton(int button, int state);
			 *
			 * @brief	Mouse button.
			 *
			 * @author	Moustapha Saad
			 * @date	29/01/2015
			 *
			 * @param	button	The button.
			 * @param	state 	The state.
			 */

			static void mouseButton(int button, int state);

			/**
			 * @fn	static void DXMouse::mouseMove(int x, int y);
			 *
			 * @brief	Mouse move.
			 *
			 * @author	Moustapha Saad
			 * @date	29/01/2015
			 *
			 * @param	x	The x coordinate.
			 * @param	y	The y coordinate.
			 */

			static void mouseMove(int x, int y);

		protected:

			/**
			 * @fn	void DXMouse::update();
			 *
			 * @brief	Updates this object.
			 *
			 * @author	Moustapha Saad
			 * @date	29/01/2015
			 */

			void update();

			/**
			 * @fn	void DXMouse::setMousePosition(glm::uvec2 val);
			 *
			 * @brief	Sets mouse position.
			 *
			 * @author	Moustapha Saad
			 * @date	29/01/2015
			 *
			 * @param	val	The value.
			 */

			void setMousePosition(glm::uvec2 val);
		};
	}
}