#ifndef __SHADER_H__
#define __SHADER_H__

#include <GL/glew.h>
#include "../math/math.h"

namespace PE
{
	namespace Graphics
	{
		class Shader
		{
		private:
			GLuint mShader;
			const char* mVertPath;
			const char* mFragPath;
		public:
			Shader(const char* vertPath, const char* fragPath);
			~Shader();

			void setUniform1f(const GLchar* name, float value);
			void setUniform1i(const GLchar* name, int value);
			void setUniform2f(const GLchar* name, const Math::vec2& vector);
			void setUniform3f(const GLchar* name, const Math::vec3& vector);
			void setUniform4f(const GLchar* name, const Math::vec4& vector);

			void setUniformMat4(const GLchar * name, const Math::mat4& matrix);

			void enable() const;
			void disable() const;

		private:
			GLuint load();
			GLint getUniformLocation(const GLchar* name);
		};
	}
}
#endif