if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest/CMakeLists.txt")
    message(FATAL_ERROR "Initialize GoogleTest with: git submodule update --init test/lib; or use -DBUILD_TESTING=OFF")
endif()
set(gtest_force_shared_crt ON CACHE BOOL "Use the shared runtime on Windows" FORCE)
add_subdirectory(lib/googletest EXCLUDE_FROM_ALL)

add_executable(runAllTests
    runTests.cpp
    heroTest.cpp
    enemyTest.cpp
    armorTest.cpp
    weaponTest.cpp
    fightTest.cpp
    achievementTest.cpp
)
target_link_libraries(runAllTests PRIVATE gtest core)
add_test(NAME game_tests COMMAND runAllTests)
set_tests_properties(game_tests PROPERTIES WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")
