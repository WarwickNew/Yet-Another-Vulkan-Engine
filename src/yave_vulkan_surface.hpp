#pragma once

#include "yave_vulkan_instance.hpp"
#include "yave_window.hpp"
#include <vulkan/vulkan_core.h>
#include <stdexcept>

// This engine is for now Wayland only!!!
#define VK_USE_PLATFORM_WAYLAND_KHR
#include <vulkan/vulkan_wayland.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WAYLAND
#include <GLFW/glfw3native.h>

namespace yave {

class YaveVulkanSurface {

private:
  VkSurfaceKHR surface;

public:
  YaveVulkanSurface(YaveVulkanInstance &yaveVulkanInstance, YaveWindow &window);
  ~YaveVulkanSurface();
  // Delete Copy constructors
  // This class should match one to one with vulkan instances
  YaveVulkanSurface(const YaveVulkanSurface &) = delete;
  YaveVulkanSurface &operator=(const YaveVulkanSurface &) = delete;
};
} // namespace yave
