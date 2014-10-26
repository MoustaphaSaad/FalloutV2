#pragma once
#include<string>
#include"MiscMath.h"
namespace Fallout{
	namespace Math{
		template<typename T>
		class Matrix{
		public:
			//consts
			static Matrix<T> identity(){
				Matrix<T> mat;
				for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
				if (i == j)
					mat._data[i][j] = 1;
				return mat;
			}
			//data
			T _data[4][4];

			Matrix(){
				for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					_data[i][j] = 0;
			}
			Matrix(Matrix<T> mat){
				for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					_data[i][j] = mat._data[i][j];
			}

			Matrix<T> operator +(const Matrix<T> &mat){
				Matrix<T> res(*this);
				for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					res._data[i][j] += mat._data[i][j];
				return res;
			}
			Matrix<T> operator +=(const Matrix<T> &mat){
				for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					this->_data[i][j] += mat._data[i][j];
			}
			Matrix<T> operator +(const T &mat){
				Matrix<T> res(*this);
				for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					res._data[i][j] += mat;
				return res;
			}
			Matrix<T> operator +=(const T &mat){
				for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					this->_data[i][j] += mat;
			}



		};
		typedef Matrix<float> mat4f;
	}
}