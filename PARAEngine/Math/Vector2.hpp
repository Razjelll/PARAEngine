#ifndef __PARA_VECTOR_2_HPP__
#define __PARA_VECTOR_2_HPP__

#include <math.h>

typedef float Real;

namespace Para
{
	class Vector2
	{
	public:
		Real x;
		Real y;

	public:
		inline Vector2() {}
		inline Vector2(const Real fx, const Real fy)
			:x(fx), y(fy) {}
		inline Vector2( Real vector[2])
			: x(vector[0]), y(vector[1]) {}
		/*inline Vector2(Real* vector)
			: x(vector[0]), y(vector[1]) {}*/
		inline Vector2(const Real scalar)
			: x(scalar), y(scalar) {}

		//dodawanie - addition
		inline Vector2& operator+(const Vector2& vector) const
		{
			return Vector2(
				x + vector.x,
				y + vector.y
			);
		}

		inline Vector2& operator+=(const Vector2& vector)
		{
			x += vector.x;
			y += vector.y;
			return *this;
		}

		inline Vector2& operator-=(const Vector2& vector)
		{
			x -= vector.x;
			y -= vector.y;
			return *this;
		}

		inline Vector2& operator+=(const Real scalar)
		{
			x += scalar;
			y += scalar;
			return *this;
		}

		inline Vector2& operator-=(const Real scalar)
		{
			x -= scalar;
			y -= scalar;
			return *this;
		}

		inline Vector2& operator*=(const Real scalar)
		{
			x *= scalar;
			y *= scalar;
			return *this;
		}

		// TODO zobaczyæ jak to dzia³a
		inline Vector2& operator*=(const Vector2& vector)
		{
			x *= vector.x;
			y *= vector.y;
			return *this;
		}

		inline Vector2& operator/=(const Real scalar)
		{
			//static_assert(scalar != 0.0);
			Real inv = 1.0f / scalar;
			x *= inv;
			y *= inv;
			return *this;
		}

		inline Vector2& operator/= (const Vector2& vector)
		{
			x /= vector.x;
			y /= vector.y;
			return *this;
		}

		//odejmowanie - substraction
		inline Vector2& operator-(const Vector2& vector) const
		{
			return Vector2(
				x - vector.x,
				y - vector.y
			);
		}

		inline Vector2& operator*(const Real scalar) const
		{
			return Vector2(
				x * scalar,
				y * scalar
			);
		}

		inline Vector2& operator/(const Real scalar) const
		{
			//static_assert(scalar != 0.0);
			Real inv = 1.0f / scalar; //mno¿enie jest szybsze ni¿ dzielenie
			return Vector2(
				x * inv,
				y * inv
			);
		}

		inline Vector2& operator=(const Vector2& vector) 
		{
			
			x = vector.x;
			y = vector.y;

			return *this;
		}

		inline Vector2& operator=(const Real scalar) 
		{
			x = scalar;
			y = scalar;

			return *this;
		}

		inline bool operator==(const Vector2& vector) const
		{
			return (x == vector.x && y == vector.y);
		}

		inline bool operator!=(const Vector2& vector) const
		{
			return (x != vector.x || y != vector.y);
		}

		//d³ugoœæ wektora
		inline Real length() const
		{
			return sqrt(x*x + y*y);
		}

		//dot product
		inline Real dot(const Vector2& vector) const
		{
			return x * vector.x + y * vector.y;
		}

		//cross product
		inline Real cross(const Vector2& vector) const
		{
			return x * vector.y - y * vector.x;
		}

		
	};
}
#endif //__PARA_VECTOR_2_HPP__