# include(FetchContent)
# FetchContent_Declare(
#     glfw3
#     GIT_REPOSITORY "https://gitee.com/MkJzCode/glfw.git"
#     GIT_TAG "3.3.2"
# )
# FetchContent_MakeAvailable(glfw3)

add_library(LittleEngine SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/glad/include/glad/glad.h
    ${CMAKE_CURRENT_SOURCE_DIR}/glad/src/glad.c
    little_engine.hpp
    little_engine.cpp
)

target_include_directories(LittleEngine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/glad/include)
target_include_directories(LittleEngine PRIVATE ${CMAKE_INSTALL_PREFIX}/include)

find_library(GLFWLIB glfw3 ${CMAKE_INSTALL_PREFIX}/lib)
target_link_libraries(LittleEngine ${GLFWLIB})

install(
    TARGETS LittleEngine
    DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
)

install(
    FILES
        little_engine.hpp
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include/engine
)

