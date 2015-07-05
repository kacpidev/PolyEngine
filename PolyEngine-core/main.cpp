#include "src/graphics/Window.h"
#include "src/math/vec2.h"
#include "src/math/mat4.h"


int main()
{
	PE::Graphics::Window window("PolyEngine!", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	
	std::cout << glGetString(GL_VERSION) << std::endl;

	PE::Math::mat4 matrix(1.0f);

	std::cout << matrix;

	while (!window.closed())
	{
		window.clear();
		

		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		window.update();
	}

	return 0;
}