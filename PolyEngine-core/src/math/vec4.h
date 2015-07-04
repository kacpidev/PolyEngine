#ifndef __VEC4_H__
#define __VEC4_H__

#include <iostream>
namespace PE
{
	namespace Math
	{
		struct vec3;

		struct vec4
		{
			float x{ 0.0f }, y{ 0.0f }, z{0.0f}, w{0.0f};
			vec4(){};
			vec4(const vec3& vector);
			vec4(const float& var);
			vec4(const float &x, const float &y, const float &z, const float &w) : x(x), y(y), z(z), w(w)	{};

			vec4& add(const vec4& other);
			vec4& subtract(const vec4& other);
			vec4& multiply(const vec4& other);
			vec4& divide(const vec4& other);

			friend vec4 operator+ (vec4 left, const vec4& right);
			friend vec4 operator- (vec4 left, const vec4& right);
			friend vec4 operator* (vec4 left, const vec4& right);
			friend vec4 operator/ (vec4 left, const vec4& right);

			vec4& operator+=(const vec4& other);
			vec4& operator-=(const vec4& other);
			vec4& operator*=(const vec4& other);
			vec4& operator/=(const vec4& other);

			friend std::ostream& operator<< (std::ostream &stream, vec4& vector);

			friend bool operator== (const vec4& left, const vec4& right);
			friend bool operator!= (const vec4& left, const vec4& right);

			float magnitude();
			void normalize();
			vec4 normalized();
		};
	}
}
#endif