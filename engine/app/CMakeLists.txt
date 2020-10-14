add_executable(app main.cpp)

target_include_directories(app PRIVATE ${CMAKE_INSTALL_PREFIX}/include)

find_library(LittleEngineLib LittleEngine ${CMAKE_INSTALL_PREFIX}/bin)
target_link_libraries(app ${LittleEngineLib})

install(
    TARGETS app 
    DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
)
