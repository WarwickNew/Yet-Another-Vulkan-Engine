#include "yave_vulkan_surface.hpp"
#include "yave_vulkan_instance.hpp"

namespace yave {
YaveVulkanSurface::YaveVulkanSurface(YaveVulkanInstance &yaveVulkanInstance,
                                     YaveWindow &window) {
  VkWaylandSurfaceCreateInfoKHR createInfo{};
  createInfo.sType = VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR;
  createInfo.display = glfwGetWaylandDisplay();
  createInfo.surface = glfwGetWaylandWindow(window.getGLFWWindow());
  //VkInstance *vkInstance = yaveVulkanInstance.getVkInstance();
  if (vkCreateWaylandSurfaceKHR((*yaveVulkanInstance.getVkInstance()), &createInfo, nullptr, &surface)) {
    throw std::runtime_error("failed to create window surface!");
  }
}
YaveVulkanSurface::~YaveVulkanSurface() {}
} // namespace yave
