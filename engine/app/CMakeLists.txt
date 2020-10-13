add_executable(app main.cpp)

target_include_directories(app PRIVATE ${CMAKE_INSTALL_PREFIX}/include)

find_library(LittleEngineLib LittleEngine ${CMAKE_INSTALL_PREFIX}/lib)
target_link_libraries(app ${LittleEngineLib})
find_library(GLFWLib glfw3 ${CMAKE_INSTALL_PREFIX}/lib)
target_link_libraries(app ${GLFWLib})

install(
    TARGETS app 
    DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
)
