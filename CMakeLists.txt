
cmake_minimum_required(VERSION 3.10)
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
project(check_cicd)

find_package(GTest REQUIRED)
configure_file(version.h.in version.h)

add_executable(check_cicd main.cpp)
add_library(check_cicd_lib lib.cpp)
add_executable(test_check_cicd test_lib.cpp)

target_link_libraries(check_cicd PRIVATE check_cicd_lib)
# target_include_directories(test_check_cicd PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(test_check_cicd PRIVATE check_cicd_lib)
target_link_libraries(test_check_cicd PRIVATE GTest::GTest)
target_link_libraries(test_check_cicd PRIVATE GTest::Main)