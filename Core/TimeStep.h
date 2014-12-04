#pragma once
namespace Fallout{
	namespace Core{
		class TimeStep{
		public:
			double _delta;
			double _elapsedTime;
			TimeStep(double d, double e);
		};
	}
}