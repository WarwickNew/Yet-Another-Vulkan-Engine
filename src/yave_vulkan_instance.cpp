#include "yave_vulkan_instance.hpp"
#include <vulkan/vulkan_core.h>

namespace yave {

YaveVulkanInstance::YaveVulkanInstance() { createInstance(); }
YaveVulkanInstance::~YaveVulkanInstance() { destroyInstance(); }

void YaveVulkanInstance::createInstance() {
  VkApplicationInfo appInfo{};
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pApplicationName = "Hello Triangle";
  appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.pEngineName = "Yave";
  appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.apiVersion = VK_API_VERSION_1_0;

  VkInstanceCreateInfo createInfo{};
  createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  createInfo.pApplicationInfo = &appInfo;

  uint32_t glfwExtensionCount = 0;
  const char **glfwExtensions;

  glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

  createInfo.enabledExtensionCount = glfwExtensionCount;
  createInfo.ppEnabledExtensionNames = glfwExtensions;

  checkLayersValidSuppport(createInfo);

  if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
    throw std::runtime_error("failed to create vulkan instance!");
  }
}

void YaveVulkanInstance::destroyInstance() {
  vkDestroyInstance(this->instance, nullptr);
}

bool YaveVulkanInstance::checkLayersValidSuppport(
    VkInstanceCreateInfo &createInfo) {
  // Finish if validation is disabled (Release mode)
  if (!this->enableValidationLayers) {
    createInfo.enabledLayerCount = 0;
    return true;
  }
  // Get layers
  uint32_t layerCount;
  vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
  std::vector<VkLayerProperties> availableLayers(layerCount);
  vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

  // Validate layers
  for (const char *layerName : validationLayers) {
    bool layerFound = false;

    for (const auto &layerProperties : availableLayers) {
      if (strcmp(layerName, layerProperties.layerName) == 0) {
        layerFound = true;
        break;
      }
    }

    if (!layerFound) {
      return false;
    }
  }

  return true;

  createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
  createInfo.ppEnabledLayerNames = validationLayers.data();
  return true;
}

} // namespace yave
