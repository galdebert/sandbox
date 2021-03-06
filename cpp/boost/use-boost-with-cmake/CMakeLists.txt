cmake_minimum_required(VERSION 3.8)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "$ENV{GA_SCRIPTS}/cmake")
include(belit_utils)
include(belit_debug)

project("use_boost")
set(CMAKE_CONFIGURATION_TYPES "Debug;Release") # remove MinSizeRel;RelWithDebInfo from default configs

# find_package(Boost) with cmake 3.10 and boot 1.66 does not work, because 1.66 introduced a new lib name pattern containing the arch
# find_package(Boost 1.65.1 REQUIRED COMPONENTS polygon) DOES NOT WORK because polygon is header only
# so we need to find what polygon depends on, `.\dist\bin\bcp --list-short polygon` gives some sort of anwser
# libs/chrono libs/polygon libs/system libs/test libs/timer
set(BOOST_ROOT "$ENV{GA_BOOST_ROOT}")
set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_DEBUG_LIBS         ON)
set(Boost_USE_RELEASE_LIBS       ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.65.1 REQUIRED COMPONENTS system chrono timer)

belit_assert("${Boost_FOUND}" "Boost was not found")
belit_verbose("Boost_INCLUDE_DIR=${Boost_INCLUDE_DIR}")
belit_verbose("Boost_LIBRARY_DIR_RELEASE=${Boost_LIBRARY_DIR_RELEASE}")
belit_verbose("Boost_LIBRARY_DIR_DEBUG=${Boost_LIBRARY_DIR_DEBUG}")

# let's create a header-only target for polygon, it's not required but this has advantages
add_library(boost_polygon INTERFACE) # cannot use Boost::polygon here
target_link_libraries(boost_polygon INTERFACE Boost::system Boost::chrono Boost::timer)
belit_add_sources_dir(boost_polygon INTERFACE "${Boost_INCLUDE_DIR}/boost/polygon" "boost/polygon")
belit_add_sources_dir(boost_polygon INTERFACE "${Boost_INCLUDE_DIR}/boost/system"  "boost/system")
belit_add_sources_dir(boost_polygon INTERFACE "${Boost_INCLUDE_DIR}/boost/chrono"  "boost/chrono")
belit_add_sources_dir(boost_polygon INTERFACE "${Boost_INCLUDE_DIR}/boost/timer"   "boost/timer")

# we use a function to benefit from variable scoping
function(use_boost_exe root)
    add_executable(use_boost "")
    belit_set_binaries_paths(use_boost "${root}/bin" "${root}/lib" "win64")
    belit_add_sources_dir(use_boost PRIVATE "${root}/src" "src")
    target_link_libraries(use_boost boost_polygon)
endfunction()
use_boost_exe("${CMAKE_CURRENT_SOURCE_DIR}")


