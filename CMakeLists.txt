cmake_minimum_required(VERSION 3.0.0)
project(GameOfLife VERSION 0.1.0 LANGUAGES CXX)
#EXECUTABLE SETUP
#
add_executable(Game src/main.cpp)
set_target_properties(Game PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    CXX_CLANG_TIDY "clang-tidy;-header-filter=.;-checks=cppcoreguidelines-*"
)

target_sources(Game PRIVATE src/Board.cpp src/Entity.cpp)
target_include_directories(Game PUBLIC inc)
target_link_libraries(Game PUBLIC sfml-graphics sfml-window sfml-system)
target_compile_features(Game PRIVATE cxx_std_20)
target_compile_options(Game PRIVATE -Wall -Wextra -Wpedantic)
#TESTING SETUP
#
option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(uts)
    add_executable(tests uts/tests.cpp)    
    set_target_properties(tests PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
    )
    target_sources(tests PRIVATE src/Board.cpp src/Entity.cpp)
    target_link_libraries(tests gtest gmock gtest_main sfml-graphics sfml-window sfml-system)
    target_compile_features(tests PRIVATE cxx_std_20)
    target_compile_options(tests PRIVATE -Wall -Wextra -Wpedantic)
    gtest_discover_tests(tests)
    add_test(UT, tests)
endif()