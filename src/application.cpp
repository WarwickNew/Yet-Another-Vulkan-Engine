#include "application.hpp"
#include "yave_vulkan_instance.hpp"

namespace yave {

void Application::run() {
  YaveVulkanInstance VI = YaveVulkanInstance();

  while (!yaveWindow.shouldClose()) {
    glfwPollEvents();
  }
}

} // namespace yave
