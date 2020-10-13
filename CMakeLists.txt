cmake_minimum_required(VERSION 3.10)
project(GameOfLife)
set(CMAKE_CXX_STANDARD 17)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

SET(cmake_build_type debug)
file(GLOB_RECURSE MY_APP_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(my_app_src ${MY_APP_SRC})
target_include_directories(my_app_src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(GameOfLife ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(GameOfLife ${CONAN_LIBS})

file(GLOB_RECURSE MY_APP_TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/uts/*.cpp)
add_executable(unit-tests ${MY_APP_TEST_SRC})
target_link_libraries(unit-tests my_app_src)
target_link_libraries(unit-tests ${CONAN_LIBS})
