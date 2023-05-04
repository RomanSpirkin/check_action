
cmake_minimum_required(VERSION 3.10)
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})
project(check_cicd)

configure_file(version.h.in version.h)

add_executable(check_cicd main.cpp)
add_library(check_cicd_lib lib.cpp)
add_executable(test_check_cicd test_lib.cpp)

target_link_libraries(check_cicd PRIVATE check_cicd_lib)
# target_include_directories(test_check_cicd PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(test_check_cicd PRIVATE check_cicd_lib)
target_link_libraries(test_check_cicd PRIVATE GTest::GTest)
target_link_libraries(test_check_cicd PRIVATE GTest::Main)

install(TARGETS check_cicd RUNTIME DESTINATION bin)

set(CPACK_GENERATOR "DEB")

set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION})
set(CPACK_PACKAGE_VERSION_PATCH ${PATCH_VERSION})

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)