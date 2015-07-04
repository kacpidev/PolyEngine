#include "Window.h"

namespace PE
{
	namespace Graphics
	{
		void windowResize(GLFWwindow *window, int width, int height);
		void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
		void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
		void mousePositionCallback(GLFWwindow *window, double xpos, double ypos);

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
			glfwSetWindowUserPointer(mWindow, this);
			glfwSetWindowSizeCallback(mWindow, windowResize);
			glfwSetKeyCallback(mWindow, keyCallback);
			glfwSetMouseButtonCallback(mWindow, mouseButtonCallback);
			glfwSetCursorPosCallback(mWindow, mousePositionCallback);
			
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

		void windowResize(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
		{
			auto win = static_cast<Window*>(glfwGetWindowUserPointer(window));
			win->mKeys[key] = action != GLFW_RELEASE;
		}

		void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
		{
			auto win = static_cast<Window*>(glfwGetWindowUserPointer(window));
			win->mButtons[button] = action != GLFW_RELEASE;
		}

		void mousePositionCallback(GLFWwindow *window, double xpos, double ypos)
		{
			auto win = static_cast<Window*>(glfwGetWindowUserPointer(window));
			win->mMouseX = xpos;
			win->mMouseY = ypos;
		}

		bool Window::isKeyPressed(unsigned int keyCode) const
		{
			//TODO: Log this
			if (keyCode >= MAX_KEYS)
			{
				return false;
			}
			return mKeys[keyCode];
		}

		bool Window::isMouseButtonPressed(unsigned int button) const 
		{
			//TODO: Log this
			if (button >= MAX_BUTTONS)
			{
				return false;
			}
			return mButtons[button];
		}
	}
}