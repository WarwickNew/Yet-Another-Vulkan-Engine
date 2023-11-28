cmake_minimum_required(VERSION 3.16)
project(yave
    VERSION 0
    DESCRIPTION "Yet Another Vulkan Engine"
    HOMEPAGE_URL "https://git.warwicknew.xyz/yave/"
    LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_CLANG_TIDY)

file(GLOB_RECURSE SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/src/*.c
    ${CMAKE_SOURCE_DIR}/src/*.cpp)

file(GLOB_RECURSE HEADER_FILES
    ${CMAKE_SOURCE_DIR}/src/*.h
    ${CMAKE_SOURCE_DIR}/src/*.hpp)

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)
set(GLFW_LIBRARIES glfw)
find_package(glm REQUIRED)

include_directories(
    ${Vulkan_INCLUDE_DIRS}
    ${GLFW_INCLUDE_DIRS}
    ${GLM_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PUBLIC
    ${GLFW_LIBRARIES}
    ${Vulkan_LIBRARIES}
    ${GLM_LIBRARY_DIRS})

add_custom_command(TARGET ${PROJECT_NAME}
    PRE_BUILD
    COMMAND ./compile_shaders.sh)
