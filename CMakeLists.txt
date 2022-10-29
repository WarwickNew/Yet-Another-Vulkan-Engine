cmake_minimum_required(VERSION 3.16)
project(yave) #Yet Another Vulkan Engine

set(CMAKE_CXX_STANDARD 17)

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)
set(GLFW_LIBRARIES glfw)
find_package(glm REQUIRED)

include_directories(
    ${Vulkan_INCLUDE_DIRS}
    ${GLFW_INCLUDE_DIRS}
    ${GLM_INCLUDE_DIRS}
    )

add_executable(${PROJECT_NAME} VulkanTest.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC
    ${GLFW_LIBRARIES}
    ${Vulkan_LIBRARIES}
    ${GLM_LIBRARY_DIRS})
