#pragma once

#include <cstring>
#include <optional>
#include <stdexcept>
#include <vector>
#include <vulkan/vulkan.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace yave {

struct QueueFamilyIndices {
  std::optional<uint32_t> graphicsFamily;

  bool isComplete() { return graphicsFamily.has_value(); }
};

class YaveVulkanInstance {

private:
  VkInstance instance;
  VkPhysicalDevice physicalDevice;
  VkDevice device;
  VkQueue graphicsQueue;

  // Vulkan instance
  void createInstance();
  void destroyInstance();

  // TODO: Move Physical device code to it's own class
  // Physical device
  void pickPhysicalDevice();
  bool isDeviceSuitable(VkPhysicalDevice device);
  QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

  // TODO: Move Logical device code to it's own class
  // Logical device
  void createLogicalDevice();
  void destroyLogicalDevice();

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

  VkInstance *getVkInstance(){return &instance;}
  YaveVulkanInstance();
  ~YaveVulkanInstance();
};
} // namespace yave
