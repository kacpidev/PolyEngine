#include "vec3.h"
#include "vec2.h"

namespace PE
{
	namespace Math
	{
		vec3::vec3(const vec2& vector)
		{
			x = vector.x;
			y = vector.y;
		}

		vec3::vec3(const float& var): x(var), y(var), z(var)
		{
			
		}

		vec3& vec3::add(const vec3& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;

			return *this;
		}

		vec3& vec3::subtract(const vec3& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;

			return *this;
		}

		vec3& vec3::multiply(const vec3& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;

			return *this;
		}

		vec3& vec3::divide(const vec3& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;

			return *this;
		}

		vec3& vec3::operator+=(const vec3& other)
		{
			return add(other);
		}

		vec3& vec3::operator-=(const vec3& other)
		{
			return subtract(other);
		}

		vec3& vec3::operator*=(const vec3& other)
		{
			return multiply(other);
		}

		vec3& vec3::operator/=(const vec3& other)
		{
			return divide(other);
		}

		vec3 operator+(vec3 left, const vec3& right)
		{
			return left.add(right);
		}

		vec3 operator-(vec3 left, const vec3& right)
		{
			return left.subtract(right);
		}

		vec3 operator*(vec3 left, const vec3& right)
		{
			return left.multiply(right);
		}

		vec3 operator/(vec3 left, const vec3& right)
		{
			return left.divide(right);
		}

		bool operator==(const vec3& left, const vec3& right)
		{
			return left.x == right.x && left.y == right.y && left.z == right.z;
		}

		bool operator!=(const vec3& left, const vec3& right)
		{
			return left.x != right.x || left.y != right.y || left.z != right.z;
		}

		std::ostream& operator<<(std::ostream& stream, vec3& vector)
		{
			stream << "vec3: (" << vector.x << ", " << vector.y << ", " << vector.z <<  ")";
			return stream;
		}
	
		float vec3::magnitude()
		{
			return std::sqrt(pow(x, 2) + pow(y, 2) + pow(z,2));
		}

		void vec3::normalize()
		{
			auto length = magnitude();
			x /= length;
			y /= length;
			z /= length;
		}

		vec3 vec3::normalized()
		{
			auto length = magnitude();
			return *this / length;
		}
	}
}