#pragma once
namespace Fallout{
	namespace Objects{
		class IRenderable{
		public:

			/**
			 * @fn	virtual void IRenderable::render() = 0;
			 *
			 * @brief	Renders this object.
			 *
			 * @author	Moustapha Saad
			 * @date	05/02/2015
			 */

			virtual void render() = 0;
		};
	}
}