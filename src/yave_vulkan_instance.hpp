#pragma once

#include <cstring>
#include <stdexcept>
#include <vector>
#include <vulkan/vulkan.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace yave {
class YaveVulkanInstance {

private:
  VkInstance instance;
  void createInstance();
  void destroyInstance();

  // Validation support
  bool checkLayersValidSuppport(VkInstanceCreateInfo &createInfo);
  const std::vector<const char *> validationLayers = {
      "VK_LAYER_KHRONOS_validation"};
#ifdef NDEBUG // Enable Validation in debug mode
  const bool enableValidationLayers = false;
#else
  const bool enableValidationLayers = true;
#endif

public:
  // Delete Copy constructors
  // This class should match one to one with vulkan instances
  YaveVulkanInstance(const YaveVulkanInstance &) = delete;
  YaveVulkanInstance &operator=(const YaveVulkanInstance &) = delete;

  YaveVulkanInstance();
  ~YaveVulkanInstance();
};
} // namespace yave
