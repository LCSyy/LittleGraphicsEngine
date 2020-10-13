add_compile_definitions(LITTLE_ENGINE)

add_library(LittleEngine SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/glad/include/glad/glad.h
    ${CMAKE_CURRENT_SOURCE_DIR}/glad/src/glad.c
    engine_global.hpp
    little_engine.hpp little_engine.cpp
    renderer.hpp renderer.cpp
)

target_include_directories(LittleEngine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/glad/include)

target_include_directories(LittleEngine PRIVATE ${CMAKE_INSTALL_PREFIX}/include)
find_library(GLFWLIB glfw3 ${CMAKE_INSTALL_PREFIX}/lib)
target_link_libraries(LittleEngine ${GLFWLIB})

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
