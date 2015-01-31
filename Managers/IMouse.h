#pragma once
#include<map>
#include<memory>
#include<glm/glm.hpp>
namespace Fallout{
	namespace Core{
		class FalloutEngine;
	}
	namespace Input{
		class IMouse{
			friend class Core::FalloutEngine;
		public:

			/**
			 * @fn	IMouse::IMouse();
			 *
			 * @brief	Default constructor.
			 *
			 * @author	Moustapha Saad
			 * @date	24/01/2015
			 */

			IMouse();

			/**
			 * @fn	IMouse::~IMouse();
			 *
			 * @brief	Destructor.
			 *
			 * @author	Moustapha Saad
			 * @date	24/01/2015
			 */

			~IMouse();

			/**
			 * @enum	Buttons
			 *
			 * @brief	Values that represent buttons.
			 */

			enum Buttons{
				Left_Button=0, Right_Button=2, Middle_Button=1
			};

			/**
			 * @enum	ButtonState
			 *
			 * @brief	Values that represent button states.
			 */

			enum ButtonState{ State_Down, State_Up, State_None};

			/**
			 * @fn	static ButtonState IMouse::getButton(Buttons b);
			 *
			 * @brief	Gets a button.
			 *
			 * @author	Moustapha Saad
			 * @date	24/01/2015
			 *
			 * @param	b	The Buttons to process.
			 *
			 * @return	The button state.
			 */

			static ButtonState getButton(Buttons b);

			/**
			 * @fn	static glm::uvec2 IMouse::getPosition();
			 *
			 * @brief	Gets the position.
			 *
			 * @author	Moustapha Saad
			 * @date	29/01/2015
			 *
			 * @return	The position.
			 */

			static glm::uvec2 getPosition();

			/**
			 * @fn	static void IMouse::setPosition(glm::uvec2 val);
			 *
			 * @brief	Sets the position.
			 *
			 * @author	Moustapha Saad
			 * @date	29/01/2015
			 *
			 * @param	val	The value.
			 */

			static void setPosition(glm::uvec2 val);
		protected:

			/**
			 * @fn	virtual void IMouse::update();
			 *
			 * @brief	Updates this object.
			 *
			 * @author	Moustapha Saad
			 * @date	24/01/2015
			 */

			virtual void update();

			/**
			 * @fn	virtual void IMouse::setMousePosition(glm::uvec2 val);
			 *
			 * @brief	Sets mouse position based on API being used.
			 *
			 * @author	Moustapha Saad
			 * @date	29/01/2015
			 *
			 * @param	val	The value.
			 */

			virtual void setMousePosition(glm::uvec2 val);

			/** @brief	The data map. */
			static std::map<Buttons,ButtonState> _data;

			/** @brief	The position. */
			static glm::uvec2 _position;
		};
		typedef std::shared_ptr<IMouse> IMousePtr;
	}
}