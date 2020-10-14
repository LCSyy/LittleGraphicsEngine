add_compile_definitions(LITTLE_ENGINE)

add_library(LittleEngine SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/glad/include/glad/glad.h
    ${CMAKE_CURRENT_SOURCE_DIR}/glad/src/glad.c
    engine_global.hpp
    little_engine.hpp little_engine.cpp
    renderer.hpp renderer.cpp
)

target_include_directories(LittleEngine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/glad/include)

target_include_directories(LittleEngine PRIVATE ${glfw3_SOURCE_DIR}/include)
# find_library(glfw3_LIB glfw3 ${glfw3_BINARY_DIR}/src)
# message("glfw3 at: ${glfw3_LIB}")
target_link_libraries(LittleEngine PRIVATE ${glfw3_BINARY_DIR}/src/libglfw3.a)

install(
    TARGETS LittleEngine
    DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
)

install(
    FILES
        engine_global.hpp
        little_engine.hpp
        renderer.hpp
    DESTINATION
        ${CMAKE_INSTALL_PREFIX}/include/engine
)
