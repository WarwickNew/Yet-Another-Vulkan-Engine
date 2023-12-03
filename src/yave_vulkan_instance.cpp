#include "yave_vulkan_instance.hpp"
#include <cstdint>
#include <vulkan/vulkan_core.h>

namespace yave {

YaveVulkanInstance::YaveVulkanInstance() {
  createInstance();
  pickPhysicalDevice();
}
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

  createInfo.enabledLayerCount = 0;

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

// TODO: Create way to pick the most powerful and feature rich device
//(maybe use a suitability score rather than bool)
// Right now we're settling for the first device with queue family support
bool YaveVulkanInstance::isDeviceSuitable(VkPhysicalDevice device) {
  QueueFamilyIndices indices = findQueueFamilies(device);

  return indices.isComplete();
}

void YaveVulkanInstance::pickPhysicalDevice() {
  physicalDevice = VK_NULL_HANDLE;

  // Get number of vulken enabled devices on system
  uint32_t deviceCount = 0;
  vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

  // No point in running vulkan if it's not supported on any devices
  if (deviceCount == 0) {
    throw std::runtime_error("failed to find GPUs with Vulkan support!");
  }

  // Now we have the number of devices we can create a vector to store them for
  // evaluation
  std::vector<VkPhysicalDevice> devices(deviceCount);
  vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

  // Use our suitability function to see if a device is suitable
  for (const auto &device : devices) {
    if (isDeviceSuitable(device)) {
      physicalDevice = device;
      break;
    }
  }

  // If we couldn't select a device throw an error
  if (physicalDevice == VK_NULL_HANDLE) {
    throw std::runtime_error("failed to find a suitable GPU!");
  }
}

QueueFamilyIndices
YaveVulkanInstance::findQueueFamilies(VkPhysicalDevice device) {
  // Get number of queues
  QueueFamilyIndices indices;
  uint32_t queueFamilyCount = 0;
  vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

  // Put queues into vector
  std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
  vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount,
                                           queueFamilies.data());

  // iterate over the devices ques and see if it has a graphics bit
  int i = 0;
  for (const auto &queueFamily : queueFamilies) {
    if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
      indices.graphicsFamily = i;
    }
    // If we know we have support we don't need to look for anything more
    if(indices.isComplete()){
      break;
    }
    i++;
  }
  return indices;
}

} // namespace yave
