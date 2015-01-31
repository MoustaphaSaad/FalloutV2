#pragma once
#include "IMouse.h"
namespace Fallout{
	namespace Managers{
		class GLManager;
	}
	namespace Input{
		class GLMouse : public IMouse{
			friend class Managers::GLManager;
		private:

			/**
			 * @fn	static void GLMouse::mouseButton(int button, int state, int x, int y);
			 *
			 * @brief	Mouse button.
			 *
			 * @author	Moustapha Saad
			 * @date	24/01/2015
			 *
			 * @param	button	The button.
			 * @param	state 	The state.
			 * @param	x	  	The x coordinate.
			 * @param	y	  	The y coordinate.
			 */

			static void mouseButton(int button, int state, int x, int y);

			static void mouseMove(int x, int y);
		protected:

			/**
			 * @fn	void GLMouse::update();
			 *
			 * @brief	Updates this object.
			 *
			 * @author	Moustapha Saad
			 * @date	24/01/2015
			 */

			void update();

			/**
			 * @fn	void GLMouse::setMousePosition(glm::uvec2 val);
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