#pragma once
#include<string>
#include<algorithm>
#include"MiscMath.h"
namespace Fallout{
	namespace Math{
		template<typename T>
		class Vector2{
		public:
			//components
			T x, y;

			//static const values
			//zero
			//unit
			//unitX
			//unitY

			//constructors
			Vector2(T x, T y){
				this->x = x;
				this->y = y;
			}
			Vector2(T val){
				this->x = val;
				this->y = val;
			}
			Vector2(){
				this->x = 0;
				this->y = 0;
			}

			//operator overloading
			//adding
			Vector2<T> operator +(const Vector2<T> &vec){
				return Vector2<T>(x + vec.x, y + vec.y);
			}
			Vector2<T> operator +(const T &val){
				return Vector2<T>(x + val, y + val);
			}
			void operator +=(const Vector2<T> &vec){
				x += vec.x;
				y += vec.y;
			}
			void operator +=(const T &vec){
				x += vec;
				y += vec;
			}

			//subtracting
			Vector2<T> operator -(const Vector2<T> &vec){
				return Vector2<T>(x - vec.x, y - vec.y);
			}
			Vector2<T> operator -(const T &val){
				return Vector2<T>(x - val, y - val);
			}
			void operator -=(const Vector2<T> &vec){
				x -= vec.x;
				y -= vec.y;
			}
			void operator -=(const T &val){
				x -= val;
				y -= val;
			}

			//multiplying 
			Vector2<T> operator *(const Vector2<T> &vec){
				return Vector2<T>(x*vec.x, y*vec.y);
			}
			Vector2<T> operator *(const T &val){
				return Vector2<T>(x*val, y*val);
			}
			void operator *=(const Vector2<T> &vec){
				x *= vec.x;
				y *= vec.y;
			}
			void operator *=(const T &val){
				x *= val;
				y *= val;
			}

			//devide
			Vector2<T> operator /(const Vector2<T> &vec){
				return Vector2<T>(x / vec.x, y / vec.y);
			}
			Vector2<T> operator /(const T &val){
				return Vector2<T>(x / val, y / val);
			}
			void operator /=(const Vector2<T> &vec){
				x /= vec.x;
				y /= vec.y;
			}
			void operator /=(const T &val){
				x /= val;
				y /= val;
			}

			//equals
			bool operator ==(const Vector2<T> &val){
				if (x == val.x && y = val.y)
					return true;
				else
					return false;
			}
			bool operator !=(const Vector2<T> &val){
				if (x == val.x && y = val.y)
					return false;
				else
					return true;
			}
			void operator =(const Vector2<T> &val){
				x = val.x;
				y = val.y;
			}

			//other functions
			Vector2<T> clamp(Vector2<T> minV, Vector2<T> maxV){
				Vector2<T> res(x, y);
				res.x = Fallout::Math::clamp(res.x, minV.x, maxV.x);
				res.y = Fallout::Math::clamp(res.y, minV.y, maxV.y);
				return res;
			}
			float length(){
				return (float)(std::sqrt((x*x)+(y*y)));
			}
			float lengthSquared(){
				return (x*x) + (y*y);
			}

			float distance(const Vector2<T> &vec){
				float v1 = x - vec.x, v2 = y - vec.y;
				return (float)std::sqrt((v1*v1) + (v2*v2));
			}
			float distanceSquared(const Vector2<T> &vec){
				float v1 = x - vec.x, v2 = y - vec.y;
				return (v1*v1) + (v2*v2);
			}
			Vector2<T> lerp(const Vector2<T> &vec, T factor){
				return (vec - *this) * factor + *this;
			}
			T max(){
				return std::max(x, y);
			}
			T min(){
				return std::min(x, y);
			}
			Vector2<T> negate(){
				return Vector2<T>(-x, -y);
			}
			Vector2<T> normalize(){
				float val = 1.0f / (float)(std::sqrt((x*x)+(y*y)));
				return Vector2<T>(x, y)*val;
			}


			//helper functions
			std::string toString(){
				return "X = " + std::to_string(x) + ", Y = " + std::to_string(y) + ".";
			}

		};
	}
}