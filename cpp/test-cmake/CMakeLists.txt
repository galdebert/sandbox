cmake_minimum_required(VERSION 3.8)

project("test_zmq") # project() must be called otherwise (at least) CMAKE_SYSTEM_NAME is not set
# we call project("test_zmq${pm_build_name}") later that superseeds this command

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../../script/cmake")
include("pm_platform")

project(test_zmq)
set(sources "src/main.cpp")
add_executable(test_zmq ${sources})
