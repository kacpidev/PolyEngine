#ifndef __VEC3_H__
#define __VEC3_H__

#include <iostream>
namespace PE
{
	namespace Math
	{
		struct vec2;

		struct vec3
		{
			float x{ 0.0f }, y{ 0.0f }, z{0.0f};
			vec3(){};
			vec3(const vec2& vector);
			vec3(const float& var);
			vec3(const float &x, const float &y, const float &z) : x(x), y(y), z(z)	{};

			vec3& add(const vec3& other);
			vec3& subtract(const vec3& other);
			vec3& multiply(const vec3& other);
			vec3& divide(const vec3& other);

			friend vec3 operator+ (vec3 left, const vec3& right);
			friend vec3 operator- (vec3 left, const vec3& right);
			friend vec3 operator* (vec3 left, const vec3& right);
			friend vec3 operator/ (vec3 left, const vec3& right);

			vec3& operator+=(const vec3& other);
			vec3& operator-=(const vec3& other);
			vec3& operator*=(const vec3& other);
			vec3& operator/=(const vec3& other);

			friend std::ostream& operator<< (std::ostream &stream, vec3& vector);

			friend bool operator== (const vec3& left, const vec3& right);
			friend bool operator!= (const vec3& left, const vec3& right);

			float magnitude();
			void normalize();
			vec3 normalized();
		};
	}
}
#endif