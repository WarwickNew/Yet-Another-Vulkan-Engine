#include "yave_window.hpp"

namespace yave {

YaveWindow::YaveWindow(int w, int h, std::string name)
    : width{w}, height{h}, windowName{name} {
  initWindow();
}

YaveWindow::~YaveWindow() {
  glfwDestroyWindow(window);
  glfwTerminate();
}

void YaveWindow::initWindow() {
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // Don't use OpenGL
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE); // Vulkan doesn't like to be resized

  // Create window with no OpenGL context
  window =
      glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
}

} // namespace yave
