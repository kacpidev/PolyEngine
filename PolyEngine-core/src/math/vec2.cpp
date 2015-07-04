#include "vec2.h"
namespace PE
{
	namespace Math
	{
		vec2::vec2(const float& other): x(other), y(other)
		{
			
		}

		vec2& vec2::add(const vec2& other)
		{
			x += other.x;
			y += other.y;

			return *this;
		}

		vec2& vec2::subtract(const vec2& other)
		{
			x -= other.x;
			y -= other.y;

			return *this;
		}

		vec2& vec2::multiply(const vec2& other)
		{
			x *= other.x;
			y *= other.y;

			return *this;
		}

		vec2& vec2::divide(const vec2& other)
		{
			x /= other.x;
			y /= other.y;

			return *this;
		}

		vec2& vec2::operator+=(const vec2& other)
		{
			return add(other);
		}

		vec2& vec2::operator-=(const vec2& other)
		{
			return subtract(other);
		}

		vec2& vec2::operator*=(const vec2& other)
		{
			return multiply(other);
		}

		vec2& vec2::operator/=(const vec2& other)
		{
			return divide(other);
		}

		vec2 operator+(vec2 left, const vec2& right)
		{
			return left.add(right);
		}

		vec2 operator-(vec2 left, const vec2& right)
		{
			return left.subtract(right);
		}

		vec2 operator*(vec2 left, const vec2& right)
		{
			return left.multiply(right);
		}
		vec2 operator/(vec2 left, const vec2& right)
		{
			return left.divide(right);
		}

		bool operator==(const vec2& left, const vec2& right)
		{
			return left.x == right.x && left.y == right.y;
		}

		bool operator!=(const vec2& left, const vec2& right)
		{
			return left.x != right.x || left.y != right.y;
		}

		std::ostream& operator<<(std::ostream& stream, vec2& vector)
		{
			stream << "vec2: (" << vector.x << ", " << vector.y << ")";
			return stream;
		}
	
		float vec2::magnitude()
		{
			return std::sqrt(pow(x, 2) + pow(y, 2));
		}

		void vec2::normalize()
		{
			auto length = magnitude();
			x /= length;
			y /= length;
		}

		vec2 vec2::normalized()
		{
			auto length = magnitude();
			return *this / length;
		}
	}
}