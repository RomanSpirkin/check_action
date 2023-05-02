
cmake_minimum_required(VERSION 3.10)
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
project(check_cicd)

configure_file(version.h.in version.h)
add_executable(check_cicd main.cpp)