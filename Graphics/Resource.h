#pragma once
#include <string>
#include <memory>
namespace Fallout{
	namespace Graphics{
		class Resource{
		public:

			enum Type{ UNKNOWN };
			/** @brief ID of the resource. */
			std::string ID;

			Resource::Type getType();

			Resource();
			~Resource();

			/**
			 * @fn	template<class T> static T Resource::load(std::string path)
			 *
			 * @brief	Loads the given file.
			 *
			 * @author	Moustapha Saad
			 * @date	13/02/2015
			 *
			 * @tparam	T	Generic type parameter.
			 * @param	path	Full pathname of the file.
			 *
			 * @return	A T.
			 */

			template<class T>
			static std::shared_ptr<T> load(std::string path){
				return NULL;
			}
		protected:
			/** @brief	The type of this resource. */
			Type type;
		};
		typedef std::shared_ptr<Resource> ResourcePtr;
	}
}