#include "Window.h"

void Window::run() {
    create();
    update();
    destroy();
}

void Window::create() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    //glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);

    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
    auto monitor = glfwGetVideoMode(primaryMonitor);

    m_windowWidth = monitor->width;
    m_windowHeight = monitor->height;
    m_windowRatio = m_windowWidth / m_windowHeight;
    mp_window = glfwCreateWindow(m_windowWidth, m_windowHeight, "Fission Engine", nullptr, nullptr);
    glfwSetWindowUserPointer(mp_window, this);
    glfwSetFramebufferSizeCallback(mp_window, framebufferResizeCallback);

    glfwMaximizeWindow(mp_window);
}

void Window::update() {
    while (!glfwWindowShouldClose(mp_window)) {
        glfwSwapBuffers(mp_window);
        glfwPollEvents();
    }

    destroy();

}

void Window::destroy() {
    glfwDestroyWindow(mp_window);
    glfwTerminate();
}

GLFWwindow* Window::get() {
    return mp_window;
}

void Window::framebufferResizeCallback(GLFWwindow* window, int width, int height) {
    auto app = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
    app->m_framebufferResized = true;
}