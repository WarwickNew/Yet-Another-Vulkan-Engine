#include "application.hpp"

namespace yave {

void Application::run() {
  while (!yaveWindow.shouldClose()) {
    glfwPollEvents();
  }
}

} // namespace yave
