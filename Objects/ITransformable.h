#pragma once
#include "Transform.h"
namespace Fallout{
	namespace Objects{
		class ITransformable{
		public:
			Transform transform;

			ITransformable(const Transform& tr){
				transform = tr;
			}
			ITransformable(){

			}

		};
	}
}