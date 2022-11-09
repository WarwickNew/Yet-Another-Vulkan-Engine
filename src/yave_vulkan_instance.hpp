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

  public:
    YaveVulkanInstance();

};
} // namespace yave
