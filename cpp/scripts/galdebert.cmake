cmake_minimum_required(VERSION 3.4)

# ------------------------------- get_abs_paths -------------------------------
# get_abs_paths(abs_paths "C:/dir1" "a.cpp;b.cpp") sets abs_paths="C:/dir1/a.cpp;C:/dir1/b.cpp"
# get_abs_paths(abs_paths "C:/dir1" "*.h;*.cpp")   sets abs_paths="C:/dir1/*.h;C:/dir1/*.cpp"
function(get_abs_paths out_abs_paths base_dir rel_paths)
	set(abs_paths)
	foreach(rel_path ${rel_paths})
		list(APPEND abs_paths "${base_dir}/${rel_path}")
	endforeach()
	set("${out_abs_paths}" "${abs_paths}" PARENT_SCOPE)
endfunction()

# ------------------------------- create_source_groups -------------------------------
# create_source_groups("C:/root" "dir1/a.cpp;dir2/b.cpp" "group/subgroup") will create in visual studio source explorer:
# +-group
#   +-subgroup
#     +- dir1
#        +- a.cpp (C:/root/dir1/c.cpp)
#     +- dir2
#        +- b.cpp (C:/root/dir2/e.cpp)
function(create_source_groups base_dir rel_paths base_group)
	foreach(rel_path ${rel_paths})
		set(group "${rel_path}")                         # "a/b/file.cpp"
		if(NOT "${base_group}" STREQUAL "")
			set(group "${base_group}/${rel_path}")       # "group/subgroup/a/b/file.cpp"
		endif()
		string(REPLACE "/" ";" tokens "${group}")        # "group;subgroup;a;b;file.cpp"
		list(REMOVE_AT tokens -1)                        # "group;subgroup;a;b"
		string(REPLACE ";" "\\" sourcegroup "${tokens}") # "group\\subgroup\\a\\b"
		if(NOT "${sourcegroup}" STREQUAL "")
			source_group("${sourcegroup}" FILES "${base_dir}/${rel_path}") # we create one source group per file, it's brute force but works
		endif()
		message(STATUS "source_group(${sourcegroup} FILES ${base_dir}/${rel_path})") # debug
	endforeach()
endfunction()

# ------------------------------- gather_sources_in_dir -------------------------------
# gather_sources_in_dir(abs_paths "C:/root" "group/subgroup") sets abs_paths to all .h and cpp in C:/root
#   and creates the corresponding source group in visual studio
function(gather_sources_in_dir out_abs_paths base_dir base_group)
	# glob *.h and *.cpp in base_dir recursively
	get_abs_paths(glob_filters "${base_dir}" "*.h;*.cpp")
	file(GLOB_RECURSE rel_paths RELATIVE "${base_dir}" ${glob_filters})
	
	create_source_groups("${base_dir}" "${rel_paths}" "${base_group}")
	get_abs_paths(abs_paths "${base_dir}" "${rel_paths}")
	set("${out_abs_paths}" "${abs_paths}" PARENT_SCOPE)
endfunction()

# ------------------------------- set_global_build_options -------------------------------
macro(set_global_build_options)
	if(MSVC)
		add_definitions("-DUNICODE" "-D_UNICODE") # http://utf8everywhere.org/
		add_compile_options(/W4) # Set warning level 4.
		add_compile_options(/WX) # Treat warnings as errors
	endif()
endmacro()

