#ifndef __MATH_H__
#define __MATH_H__

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"
#define _USE_MATH_DEFINES
#include <math.h>

namespace PE
{
	namespace Math
	{
		inline float toRadians(float degrees)
		{
			return degrees * (M_PI / 180.0f);
		}
	}
}
#endif __MATH_H__