#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace yave {

class YaveWindow {
    private:
        GLFWwindow *window;

        void initWindow();

        const int width;
        const int height;
        std::string windowName;

    public:
        YaveWindow(int w, int h, std::string name);
        ~YaveWindow();

        bool shouldClose() { return glfwWindowShouldClose(window); }

};

}
