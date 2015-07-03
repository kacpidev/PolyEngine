#pragma once
#include <GLFW/glfw3.h>
#include <iostream>

namespace PolyEngine
{
	namespace Graphics
	{
		class Window
		{
		private: 
			const char *mTitle;
			int mWidth, mHeight;
			GLFWwindow *mWindow;
			bool mClosed;
		public:
			Window(const char* title, int width, int height) : mTitle(title), mHeight(height), mWidth(width)
			{ 
				if (!init())
				{
					glfwTerminate();
				}
			};
			
			~Window();
			bool closed() const;
			void update();
			void clear() const;

			int getWidth() const;
			int getHeight() const;
		private:
			bool init();
		};

	}
}