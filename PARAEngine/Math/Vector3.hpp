#ifndef __PARA_VECTOR_3_HPP
#define __PARA_VECTOR_3_HPP

typedef float Real;


namespace Para
{
	class Vector3
	{
	public:
		Real x;
		Real y;
		Real z;

	public:
		inline Vector3() {}
		inline Vector3(const Real fx, const Real fy, const Real fz) : x(fx), y(fy), z(fz) {}
		inline Vector3(const Real vector[3]) : x(vector[0]), y(vector[1]), z(vector[2]) {}
		//inline Vector3(const Real* vector) : x(vector[0]), y(vector[1]), z(vector[2]) {}
		inline Vector3(const Real scalar) : x(scalar), y(scalar), z(scalar) {}
	};
}


#endif __PARA_VECTOR_3_HPP