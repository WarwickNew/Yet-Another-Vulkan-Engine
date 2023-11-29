# Yet Another Vulkan Engine.
This project has been created with the sole purpose of teaching me how Vulkan
works.

# Installing Dependancies.
To build the project on redhat based distros these dependancies or their
equivelents are required.
'''
sudo dnf install vulkan-tools vulkan-loader-devel vulkan-validation-layers-devel
glfw-devel glm-devel glslc
'''

# Dev corner
## Rules of development
- Use RAII as much as physically possible.
- Try to keep the game engine space as separate from the application space as possible.
## TODO: road to 0.0.1
- [X] Create a management class for the GLFW window
- [X] Create and validate vulkan instance.
- [ ] Create a debug messaging system.
- [ ] Manage Physical Devices
- [ ] Manage logical Devices if necessary
- [ ] Create Vulkan pipeline
- [ ] Draw triangle
