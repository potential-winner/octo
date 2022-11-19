cmake_minimum_required(VERSION 3.16)

set(CATCH_BUILD_TESTING off)
AddExternalProject(Catch2 3 https://github.com/catchorg/Catch2.git v3.2.0)

add_subdirectory(test_core)
