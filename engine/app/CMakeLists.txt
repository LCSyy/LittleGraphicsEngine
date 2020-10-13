add_executable(app main.cpp)

target_include_directories(app PRIVATE ${CMAKE_INSTALL_PREFIX}/include)

find_library(LittleEngineLib LittleEngine ${CMAKE_INSTALL_PREFIX}/bin)
message(" The real path is: ${LittleEngineLib}")
target_link_libraries(app ${LittleEngineLib})

# find_library(GLFWLIB glfw3 ${CMAKE_INSTALL_PREFIX}/lib)
# target_link_libraries(app ${GLFWLIB})

install(
    TARGETS app 
    DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
)
