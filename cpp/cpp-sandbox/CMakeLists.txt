cmake_minimum_required(VERSION 3.5)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../scripts")
include(galdebert)

project("cpp-sandbox")

set_global_build_options() # from galdebert.cmake

gather_sources_in_dir(sources "${CMAKE_SOURCE_DIR}/src" "") # from galdebert.cmake

add_executable("cpp-sandbox" ${sources})
set_property(TARGET "cpp-sandbox" PROPERTY CXX_STANDARD 14)
target_include_directories("cpp-sandbox" PUBLIC "${dir}")
