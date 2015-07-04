#include "vec4.h"
#include "vec3.h"

namespace PE
{
	namespace Math
	{
		vec4::vec4(const vec3& vector)
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
		}

		vec4::vec4(const float& var): x(var), y(var), z(var)
		{
			
		}

		vec4& vec4::add(const vec4& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;

			return *this;
		}

		vec4& vec4::subtract(const vec4& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;

			return *this;
		}

		vec4& vec4::multiply(const vec4& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;

			return *this;
		}

		vec4& vec4::divide(const vec4& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;

			return *this;
		}

		vec4& vec4::operator+=(const vec4& other)
		{
			return add(other);
		}

		vec4& vec4::operator-=(const vec4& other)
		{
			return subtract(other);
		}

		vec4& vec4::operator*=(const vec4& other)
		{
			return multiply(other);
		}

		vec4& vec4::operator/=(const vec4& other)
		{
			return divide(other);
		}

		vec4 operator+(vec4 left, const vec4& right)
		{
			return left.add(right);
		}

		vec4 operator-(vec4 left, const vec4& right)
		{
			return left.subtract(right);
		}

		vec4 operator*(vec4 left, const vec4& right)
		{
			return left.multiply(right);
		}

		vec4 operator/(vec4 left, const vec4& right)
		{
			return left.divide(right);
		}

		bool operator==(const vec4& left, const vec4& right)
		{
			return left.x == right.x && left.y == right.y && left.z == right.z && left.w == right.w;
		}

		bool operator!=(const vec4& left, const vec4& right)
		{
			return left.x != right.x || left.y != right.y || left.z != right.z || left.w != right.w;
		}

		std::ostream& operator<<(std::ostream& stream, vec4& vector)
		{
			stream << "vec4: (" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
			return stream;
		}
	
		float vec4::magnitude()
		{
			return std::sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
		}

		void vec4::normalize()
		{
			auto length = magnitude();
			x /= length;
			y /= length;
			z /= length;
			w /= length;
		}

		vec4 vec4::normalized()
		{
			auto length = magnitude();
			return *this / length;
		}
	}
}