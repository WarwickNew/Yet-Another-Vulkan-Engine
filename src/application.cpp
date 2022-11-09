#include "application.hpp"
#include "yave_vulkan_instance.hpp"

namespace yave {

void Application::run() {
  yaveVulkanInstance VI = yaveVulkanInstance();

  while (!yaveWindow.shouldClose()) {
    glfwPollEvents();
  }
}

} // namespace yave
