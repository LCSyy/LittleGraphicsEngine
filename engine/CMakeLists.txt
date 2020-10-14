cmake_minimum_required(VERSION 3.15)

include(FetchContent)
FetchContent_Declare(
    glfw3
    GIT_REPOSITORY "https://gitee.com/MkJzCode/glfw.git"
    GIT_TAG "3.3.2"
)

set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)

FetchContent_MakeAvailable(glfw3)
FetchContent_GetProperties(glfw3 SOURCE_DIR glfw3_SOURCE_DIR BINARY_DIR glfw3_BINARY_DIR)

project(LittleEngine VERSION 0.0.1)

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/dist)

add_subdirectory(engine)
add_subdirectory(app)
