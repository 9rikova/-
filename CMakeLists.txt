cmake_minimum_required (VERSION 3.2)
project(Firstlab)
add_executable(main main.cpp)
set_target_properties(main PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
	)
