#ifndef __MAT4_H__
#define __MAT4_H__

#include "math.h"

namespace PE
{
	namespace Math
	{
		struct mat4
		{
			union
			{
				float elements[16];
				vec4 columns[4];
			};
			mat4();
			mat4(float diagonal);

			static mat4 identity();

			mat4& multiply(const mat4& other);
			friend mat4 operator*(mat4 left, const mat4& right);
			mat4& operator*=(const mat4& other);
		
			//PROJECTION MATRICIES
			static mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
			static mat4 perspective(int fov, float aspectRatio, float near, float far);

			//TRANSLATION
			static mat4 translation(const vec3 &vector);
			static mat4 rotation(float angle, const vec3 &vector);
			static mat4 scale(const vec3 &scale);

			friend std::ostream& operator<<(std::ostream &stream, mat4 &mat);
		};
	}
}

#endif