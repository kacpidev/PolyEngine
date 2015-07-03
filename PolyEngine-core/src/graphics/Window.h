/*
Main Window class
*/

#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace PolyEngine
{
	namespace Graphics
	{
#define MAX_KEYS		1024
#define MAX_BUTTONS 32

		class Window
		{
		private: 
			const char *mTitle;
			int mWidth, mHeight;
			GLFWwindow *mWindow;
			bool mClosed;

			bool mKeys[MAX_KEYS];
			bool mButtons[MAX_BUTTONS];
			double mMouseX, mMouseY;
		public:
			Window(const char* title, int width, int height) : mTitle(title), mHeight(height), mWidth(width)
			{
				if (!init())
				{
					glfwTerminate();
				}

				for (auto key : mKeys)
				{
					key = false;
				}

			};
			
			~Window();
			bool closed() const;
			void update();
			void clear() const;

			inline int getWidth() const { return mWidth; };
			inline int getHeight() const{ return mHeight; };
			inline int getMouseX() const  { return mMouseX; };
			inline int getMouseY() const { return mMouseY; };

			bool isKeyPressed(unsigned int keyCode) const;
			bool isMouseButtonPressed(unsigned int button) const;
		private:
			bool init();
			friend static void windowResize(GLFWwindow *window, int width, int height);
			friend static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
			friend static void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
			friend static void mousePositionCallback(GLFWwindow *window, double xpos, double ypos);
		};

	}
}

#endif