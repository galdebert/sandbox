cmake_minimum_required(VERSION 3.8)

#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../../../galdebert-scripts/cmake")
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")

# https://stackoverflow.com/questions/43746829/how-to-create-a-cmake-configuration-type-that-inherits-from-release
get_directory_property(_vars VARIABLES)
foreach(_var IN LISTS _vars)
    if (_var MATCHES "_RELEASE$")
        string(REPLACE "_RELEASE" "_MYRELEASE" _var_new "${_var}")
        set(${_var_new} "${${_var}}")
    endif()
endforeach()

set(CMAKE_CONFIGURATION_TYPES "Debug;Release;MyDebug;MyRelease")
set(CMAKE_CXX_FLAGS_MYDEBUG          ${CMAKE_CXX_FLAGS_DEBUG})
set(CMAKE_EXE_LINKER_FLAGS_MYDEBUG   ${CMAKE_EXE_LINKER_FLAGS_DEBUG})
set(CMAKE_CXX_FLAGS_MYRELEASE        ${CMAKE_CXX_FLAGS_RELEASE})
set(CMAKE_EXE_LINKER_FLAGS_MYRELEASE ${CMAKE_EXE_LINKER_FLAGS_RELEASE})

project("use_boost")

# set(CMAKE_CONFIGURATION_TYPES "MyDebug;MyRelease")
# set(CMAKE_CXX_FLAGS_MYDEBUG          ${CMAKE_CXX_FLAGS_DEBUG})
# set(CMAKE_EXE_LINKER_FLAGS_MYDEBUG   ${CMAKE_EXE_LINKER_FLAGS_DEBUG})
# set(CMAKE_CXX_FLAGS_MYRELEASE        ${CMAKE_CXX_FLAGS_RELEASE})
# set(CMAKE_EXE_LINKER_FLAGS_MYRELEASE ${CMAKE_EXE_LINKER_FLAGS_RELEASE})


# Imported Libraries or Interface Libraries ?
# add_library(myboost STATIC IMPORTED)
# set_property(myboost IMPORTED_LOCATION_DEBUG)
# An IMPORTED library target references a library file located outside the project.
# properties:
# IMPORTED_ and INTERFACE_.
# IMPORTED_LOCATION location of the main library file on disk.
# IMPORTED_LOCATION_DEBUG
# IMPORTED_LOCATION_RELEASE


# find_package(Boost) with cmake 3.10 and boot 1.66 does not work
set(BOOST_ROOT "C:/Dev/boost")
set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_DEBUG_LIBS         ON)
set(Boost_USE_RELEASE_LIBS       ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

#find_package(Boost 1.65.1 REQUIRED COMPONENTS polygon) DOES NOT WORK because polygon is header only
# so we need to find what polygon depends on, `.\dist\bin\bcp --list-short polygon` gives some sort of anwser
# libs/chrono libs/polygon libs/system libs/test libs/timer
find_package(Boost 1.65.1 REQUIRED COMPONENTS system chrono timer)

message(STATUS "Boost_INCLUDE_DIR=${Boost_INCLUDE_DIR}")
message(STATUS "Boost_LIBRARY_DIR=${Boost_LIBRARY_DIR}")
message(STATUS "Boost_LIBRARY_DIR_RELEASE=${Boost_LIBRARY_DIR_RELEASE}")
message(STATUS "Boost_LIBRARY_DIR_DEBUG=${Boost_LIBRARY_DIR_DEBUG}")
message(STATUS "Boost_LIBRARIES=${Boost_LIBRARIES}")
message(STATUS "CMAKE_CONFIGURATION_TYPES=${CMAKE_CONFIGURATION_TYPES}")

# imported configurations from Boost
get_property(imported_configs TARGET Boost::system PROPERTY IMPORTED_CONFIGURATIONS)
message(STATUS "boost imported_configs=${imported_configs}")

# map configuration
# add_library(imported_target STATIC IMPORTED)
# set_property(TARGET imported_target APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
# set_property(TARGET imported_target PROPERTY IMPORTED_LOCATION_DEBUG "${imported_target_debug_location}")
# set_property(TARGET imported_target PROPERTY MAP_IMPORTED_CONFIG_MINSIZEREL Release)
# set_property(TARGET imported_target PROPERTY MAP_IMPORTED_CONFIG_RELWITHDEBINFO Release)

#message(STATUS "MAP_IMPORTED_CONFIG_DEBUG=${MAP_IMPORTED_CONFIG_DEBUG}")

add_executable(use_boost "main.cpp")

# map configs: MYDEBUG uses boost DEBUG, MYRELEASE uses boost RELEASE
set_property(TARGET use_boost PROPERTY MAP_IMPORTED_CONFIG_MYDEBUG DEBUG)
set_property(TARGET use_boost PROPERTY MAP_IMPORTED_CONFIG_MYRELEASE RELEASE)

target_link_libraries(use_boost Boost::boost Boost::system Boost::chrono Boost::timer)
