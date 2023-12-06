#include "application.hpp"
#include "yave_vulkan_instance.hpp"
#include "yave_vulkan_surface.hpp"

namespace yave {

void Application::run() {
  YaveVulkanInstance VI = YaveVulkanInstance();
  YaveVulkanSurface VS = YaveVulkanSurface(VI, yaveWindow);

  while (!yaveWindow.shouldClose()) {
    glfwPollEvents();
  }
}

} // namespace yave
