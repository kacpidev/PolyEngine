#include "src/graphics/Window.h"
#include "src/math/math.h"
#include "src/graphics/Shader.h"


using namespace PE::Math;

int main(){
	PE::Graphics::Window window("PolyEngine!", 960, 540);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	std::cout << glGetString(GL_VERSION) << std::endl;


	GLfloat vertices[] =
	{
		4, 3, 0,
		12, 3, 0,
		4, 6, 0,
		4, 6, 0,
		12, 6, 0,
		12, 3, 0
	};

	GLuint vbo;

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	PE::Graphics::Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniform2f("light_pos", vec2(4.0f, 3.5f));
	shader.setUniform4f("colour", vec4(1.0f, 0.3f, 0.4f, 1.0f));

	while (!window.closed())
	{
		window.clear();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		window.update();
	}

	return 0;
}