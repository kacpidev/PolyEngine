#ifndef __VEC2_H__
#define __VEC2_H__

#include <iostream>
namespace PE
{
	namespace Math
	{
		struct vec2
		{
			float x{ 0.0f }, y{ 0.0f };
			vec2() { };
			vec2(const float& other);
			vec2(const float &x, const float &y) : x(x), y(y) { };

			vec2& add(const vec2& other);
			vec2& subtract(const vec2& other);
			vec2& multiply(const vec2& other);
			vec2& divide(const vec2& other);

			friend vec2 operator+ (vec2 left, const vec2& right);
			friend vec2 operator- (vec2 left, const vec2& right);
			friend vec2 operator* (vec2 left, const vec2& right);
			friend vec2 operator/ (vec2 left, const vec2& right);

			vec2& operator+=(const vec2& other);
			vec2& operator-=(const vec2& other);
			vec2& operator*=(const vec2& other);
			vec2& operator/=(const vec2& other);

			friend std::ostream& operator<< (std::ostream &stream, vec2& vector);

			friend bool operator== (const vec2& left, const vec2& right);
			friend bool operator!= (const vec2& left, const vec2& right);

			float magnitude();
			void normalize();
			vec2 normalized();
		};
	}
}
#endif