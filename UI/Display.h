#pragma once
#include<string>
#include<memory>
namespace Fallout{
	namespace UI{
		class Display{
		public:
			//window size
			int _width, _height;
			//title
			std::string _title;

			Display();
			Display(int x, int y, std::string t);
			~Display();

			float getAspectRatio();
		};
		typedef std::shared_ptr<Display> DisplayPtr;
	}
}