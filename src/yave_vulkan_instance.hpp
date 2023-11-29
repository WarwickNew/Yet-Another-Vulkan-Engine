#pragma once

#include <stdexcept>
#include <vulkan/vulkan.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace yave {
class YaveVulkanInstance {

private:
  VkInstance instance;

  void createInstance();

  void destroyInstance();

public:
  // Delete Copy constructors
  // This class should match one to one with vulkan instances
  YaveVulkanInstance(const YaveVulkanInstance&) = delete;
  YaveVulkanInstance &operator=(const YaveVulkanInstance &) = delete;

  YaveVulkanInstance();
  ~YaveVulkanInstance();
};
} // namespace yave
