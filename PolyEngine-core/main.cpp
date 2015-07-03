#include "src/graphics/Window.h"

int main()
{
	PolyEngine::Graphics::Window window("PolyEngine!", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	
	std::cout << glGetString(GL_VERSION) << std::endl;

	while (!window.closed())
	{
		window.clear();
		
		if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_1))
		{
			std::cout << "M1 pressed" << std::endl;
		}

		if (window.isKeyPressed(GLFW_KEY_B))
		{
			std::cout << "b pressed" << std::endl;
		}

		if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_2))
		{
			std::cout << "Mouse x: " << window.getMouseX() << " Mouse y: " << window.getMouseY() << std::endl;
		}


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