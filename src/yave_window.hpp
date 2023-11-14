#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace yave {

class YaveWindow {
private:
  GLFWwindow *window;

  void initWindow();

  const int width;
  const int height;
  std::string windowName;

public:
  // Delete Copy constructors 
  // This class should match one to one with glfw window instances
  YaveWindow(const YaveWindow &) = delete;
  YaveWindow &operator=(const YaveWindow &) = delete;

  // Initialiser and destructor
  YaveWindow(int w, int h, std::string name);
  ~YaveWindow();

  // Tell apllicaton that the user has attempted to close the window
  bool shouldClose() { return glfwWindowShouldClose(window); }
};

} // namespace yave
