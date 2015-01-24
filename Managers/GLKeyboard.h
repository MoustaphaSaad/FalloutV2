#pragma once
#include"IKeyboard.h"
namespace Fallout{
	namespace Managers{
		class GLManager;
	}
	namespace Input{
		class GLKeyboard : public IKeyboard{
			friend class Managers::GLManager;
		private:

			/**
			 * @fn	static void GLKeyboard::keyboardDownFunc(unsigned char k, int x, int y);
			 *
			 * @brief	Keyboard down function to indicate that a key is down at this moment
			 *
			 * @author	Moustapha Saad
			 * @date	23/01/2015
			 *
			 * @param	k	The unsigned char to process.
			 * @param	x	The x coordinate.
			 * @param	y	The y coordinate.
			 */
			static void keyboardDownFunc(unsigned char k, int x, int y);

			/**
			 * @fn	static void GLKeyboard::keyboardUpFunc(unsigned char k, int x, int y);
			 *
			 * @brief	Keyboard up function to indicate that a key is up at this moment
			 *
			 * @author	Moustapha Saad
			 * @date	23/01/2015
			 *
			 * @param	k	The unsigned char to process.
			 * @param	x	The x coordinate.
			 * @param	y	The y coordinate.
			 */

			static void keyboardUpFunc(unsigned char k, int x, int y);

			/**
			 * @fn	static void GLKeyboard::keyboardSpecialDownFunc(int k, int x, int y);
			 *
			 * @brief	Keyboard special down function.
			 *
			 * @author	Moustapha Saad
			 * @date	23/01/2015
			 *
			 * @param	k	The int to process.
			 * @param	x	The x coordinate.
			 * @param	y	The y coordinate.
			 */

			static void keyboardSpecialDownFunc(int k, int x, int y);

			/**
			 * @fn	static void GLKeyboard::keyboardSpecialUpFunc(int k, int x, int y);
			 *
			 * @brief	Keyboard special up function.
			 *
			 * @author	Moustapha Saad
			 * @date	23/01/2015
			 *
			 * @param	k	The int to process.
			 * @param	x	The x coordinate.
			 * @param	y	The y coordinate.
			 */

			static void keyboardSpecialUpFunc(int k, int x, int y);

		protected:
			/**
			 * @fn	void GLKeyboard::update();
			 *
			 * @brief	Updates this object and key pressing map.
			 *
			 * @author	Moustapha Saad
			 * @date	23/01/2015
			 */
			void update();
		};
	}
}