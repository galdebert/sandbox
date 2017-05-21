cmake_minimum_required(VERSION 3.5)
set(dir "${CMAKE_CURRENT_SOURCE_DIR}")

file(GLOB_RECURSE files "src/*")

add_executable("sandbox-cpp" ${files})

set_property(TARGET "sandbox-cpp" PROPERTY CXX_STANDARD 14)
target_include_directories("sandbox-cpp" PUBLIC "${dir}")
