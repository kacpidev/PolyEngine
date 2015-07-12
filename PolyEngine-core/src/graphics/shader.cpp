#include "Shader.h"
#include <vector>
#include <iostream>
#include "../utils/fileutils.h"

namespace PE
{
	namespace Graphics
	{
		Shader::Shader(const char* vertPath, const char* fragPath) : mFragPath(fragPath), mVertPath(vertPath)
		{
			mShader = load();
		}

		GLuint Shader::load()
		{
			auto program = glCreateProgram();
			auto vertex = glCreateShader(GL_VERTEX_SHADER);
			auto fragment = glCreateShader(GL_FRAGMENT_SHADER);

			auto vertexSourceString = FileUtils::readFile(mVertPath);
			auto fragSourceString = FileUtils::readFile(mFragPath);

			auto vertexSource = vertexSourceString.c_str();
			auto fragSource = fragSourceString.c_str();

			glShaderSource(vertex, 1, &vertexSource, NULL);
			glCompileShader(vertex);
			
			GLint result; 
			glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);

			if (result == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);
				std::cout << "Failed to compile vertex shader: " << &error[0] << std::endl;
				glDeleteShader(vertex);
				return 0;
			}

			glShaderSource(fragment, 1, &fragSource, NULL);
			glCompileShader(fragment);

			glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);

			if (result == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);
				std::cout << "Failed to compile fragment shader: " << &error[0] << std::endl;
				glDeleteShader(fragment);
				return 0;
			}

			glAttachShader(program, vertex);
			glAttachShader(program, fragment);
			
			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vertex);
			glDeleteShader(fragment);

			return program;
		}

		GLint Shader::getUniformLocation(const GLchar* name)
		{
			return glGetUniformLocation(mShader, name);
		}

		void Shader::enable() const
		{
			glUseProgram(mShader);
		}

		void Shader::disable() const
		{
			glUseProgram(0);
		}

		void Shader::setUniform1f(const GLchar* name, float value)
		{
			glUniform1f(getUniformLocation(name), value);
		}

		void Shader::setUniform1i(const GLchar* name, int value)
		{
			glUniform1i(getUniformLocation(name), value);
		}

		void Shader::setUniform2f(const GLchar* name, const Math::vec2& vector)
		{
			glUniform2f(getUniformLocation(name), vector.x, vector.y);
		}

		void Shader::setUniform3f(const GLchar* name, const Math::vec3& vector)
		{
			glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
		}

		void Shader::setUniform4f(const GLchar* name, const Math::vec4& vector)
		{
			glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
		}

		void Shader::setUniformMat4(const GLchar* name, const Math::mat4& matrix)
		{
			glUniformMatrix4fv(getUniformLocation(name),1, GL_FALSE, matrix.elements);

		}

		Shader::~Shader()
		{
			glDeleteProgram(mShader);
		}
	}
}