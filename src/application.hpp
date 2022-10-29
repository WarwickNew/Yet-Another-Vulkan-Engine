#pragma once

#include "yave_window.hpp"

namespace yave {
class Application {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();

    private:
        YaveWindow yaveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};

};
} // namespace yave
