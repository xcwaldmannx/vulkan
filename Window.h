#pragma once

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

class Window {
public:
	void run();
	GLFWwindow* get();

private:
	void create();
	void update();
	void destroy();

	static void framebufferResizeCallback(GLFWwindow* window, int width, int height);

private:
	int m_windowWidth = 0;
	int m_windowHeight = 0;
	float m_windowRatio = 0;
	bool m_framebufferResized = false;

	GLFWwindow* mp_window;
};

