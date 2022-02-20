cmake_minimum_required (VERSION 3.8)
project(test_runAllTests)
set(GOOGLETEST_VERSION 1.9.0)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)

find_package(SFML 2 COMPONENTS system window graphics REQUIRED )
find_package(tinyxml2 CONFIG REQUIRED)


set(TEST_SOURCE_FILES runTests.cpp heroTest.cpp enemyTest.cpp armorTest.cpp weaponTest.cpp)

enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runAllTests ${TEST_SOURCE_FILES})

target_link_libraries(runAllTests PRIVATE gtest gtest_main core sfml-system sfml-network sfml-graphics sfml-window tinyxml2::tinyxml2)

add_test(NAME test COMMAND runAllTests)