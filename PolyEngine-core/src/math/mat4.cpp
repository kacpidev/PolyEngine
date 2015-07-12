#include "mat4.h"


namespace PE
{
	namespace Math
	{
		mat4::mat4()
		{
			for (auto element : elements)
			{
				element = 0.0f;
			}
		}

		mat4::mat4(float diagonal)
		{
			for (auto i = 0; i < 4; ++i)
			{
				for (auto j = 0; j < 4; ++j)
				{
					if ((i + 4 * j) / 4 == (i + 4 * j) % 4)
					{
						elements[i + 4 * j] = diagonal;
					}
					else
					{
						elements[i + 4 * j] = 0.0f;
					}
				}
			}
		}

		mat4 mat4::identity()
		{
			return mat4(1.0f);
		}

		mat4& mat4::multiply(const mat4& other)
		{
			float data[16];
			for (auto i = 0; i < 4; ++i)
			{
				for (auto j = 0; j < 4; ++j)
				{
					auto sum = 0.0f;
					for (auto e = 0; e < 4; ++e)
					{
						sum += elements[j + e * 4] * other.elements[e + i * 4];
					}
					elements[j + i * 4] = sum;
				}
			}
			memcpy(elements, data, 4 * 4 * sizeof(float));

			return *this;
		}

		mat4 operator*(mat4 left, const mat4& right)
		{
			return left.multiply(right);
		}

		mat4& mat4::operator*=(const mat4& other)
		{
			return multiply(other);
		}

		mat4 mat4::orthographic(float left, float right, float bottom, float top, float near, float far)
		{
			mat4 result(1.0f);

			result.elements[0 + 0 * 4] = 2.0f / (right - left);
			result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
			result.elements[2 + 2 * 4] = 2.0f / (near - far);
			
			result.elements[0 + 3 * 4] = (right + left) / (left- right);
			result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
			result.elements[2 + 3 * 4] = (far + near) / (far - near);

			return result;
		}

		mat4 mat4::perspective(int fov, float aspectRatio, float near, float far)
		{
			mat4 result(1.0f);

			auto q = 1.0f / tan(toRadians(0.5f * fov));
			auto a = q / aspectRatio;
			auto b = (near + far) / (near - far);
			auto c = 2.0f * near * far / (near - far);

			result.elements[0 + 0 * 4] = a;
			result.elements[1 + 1 * 4] = q;
			result.elements[2 + 2 * 4] = b;
			result.elements[2 + 3 * 4] = c;
			result.elements[3 + 2 * 4] = -1.0f;
			
			return result;
		}

		mat4 mat4::translation(const vec3& vector)
		{
			mat4 result(1.0f);
			result.elements[0 + 3 * 4] = vector.x;
			result.elements[1 + 3 * 4] = vector.y;
			result.elements[2 + 3 * 4] = vector.z;

			return result;
		}

		mat4 mat4::rotation(float angle, const vec3& axis)
		{
			mat4 result(1.0f);

			float r = toRadians(angle);
			float c = cos(r);
			float s = sin(r);
			float omc = 1.0f - c;

			float x = axis.x;
			float y = axis.y;
			float z = axis.z;

			result.elements[0 + 0 * 4] = x * omc + c;
			result.elements[1 + 0 * 4] = y * x * omc + z * s;
			result.elements[2 + 0 * 4] = x * z * omc - y * s;

			result.elements[0 + 1 * 4] = x * y * omc - z * s;
			result.elements[1 + 1 * 4] = y * omc + c;
			result.elements[2 + 1 * 4] = y * z * omc + x * s;

			result.elements[0 + 2 * 4] = x * z * omc + y * s;
			result.elements[1 + 2 * 4] = y * z * omc - x * s;
			result.elements[2 + 2 * 4] = z * omc + c;

			return result;
		}

		mat4 mat4::scale(const vec3& scale)
		{
			mat4 result(1.0f);

			result.elements[0 + 0 * 4] = scale.x;
			result.elements[1 + 1 * 4] = scale.y;
			result.elements[2 + 2 * 4] = scale.z;

			return result;
		}

		std::ostream& operator<<(std::ostream& stream, mat4& matrix)
		{
			stream << "Mat4" << std::endl;

			for (auto i = 0; i < 4; ++i)
			{
				for (auto j = 0; j < 4; ++j)
				{
					stream.width(8);
					stream << matrix.elements[i + 4 * j];
				}
				stream << std::endl;
			}
			return stream;
		}
	}
}
