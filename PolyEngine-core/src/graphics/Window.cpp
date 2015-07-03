#include "Window.h"

namespace PolyEngine
{
	namespace Graphics
	{
		void windowResize(GLFWwindow *window, int width, int height);

		Window::~Window()
		{
			glfwTerminate();
		}

		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "Error" << std::endl;
				return false;
			}

			mWindow = glfwCreateWindow(mWidth, mHeight, mTitle, NULL, NULL);
			if (!mWindow)
			{
				std::cout << "Failed to create window" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(mWindow);
			glfwSetWindowSizeCallback(mWindow, windowResize);
			
			std::cout << "OpenGL" << glGetString(GL_VERSION) << std::endl;

			if (glewInit() != GLEW_OK)
			{
				std::cout << "Failed to init GLEW!" << std::endl;
				return false;
			}

			return true;
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update()
		{
			glfwPollEvents();
			glfwSwapBuffers(mWindow);
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(mWindow) == 1;
		}

		int Window::getWidth() const
		{
			return mWidth;
		}

		int Window::getHeight() const
		{
			return mHeight;
		}

		void windowResize(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}
	}
}