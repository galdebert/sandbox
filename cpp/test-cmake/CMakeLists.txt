cmake_minimum_required(VERSION 3.8)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../../../galdebert-scripts/cmake")
include("pm_init")

project("test_cmake_${PM_BUILD}")
pm_init("debug;release")

set(sources "${PM_ROOT}/src/main.cpp")
set(include_dirs "${PM_ROOT}/src/private")
#pm_print_list("sources" "${sources}")
#pm_print_list("include_dirs" "${include_dirs}")
pm_exe("test_cmake_exe" "${sources}" "${include_dirs}" "")



