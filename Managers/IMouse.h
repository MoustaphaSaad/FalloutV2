#pragma once
#include<map>
#include<memory>
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

			/** @brief	The data map. */
			static std::map<Buttons,ButtonState> _data;
		};
		typedef std::shared_ptr<IMouse> IMousePtr;
	}
}