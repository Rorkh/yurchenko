cmake_minimum_required(VERSION 3.10)

project(yurchenko)

add_compile_options("-std=c++17")

set(SOURCE
	src/os/linux.cpp
	src/os/macos.cpp
	src/os/windows.cpp

	src/yurchenko.cpp
)

set(HEADERS
	
	src/os/linux.hpp
	src/os/macos.hpp
	src/os/windows.hpp

	src/const/keys.hpp
	src/yurchenko.hpp
)

add_library(yurchenko SHARED ${SOURCE} ${HEADERS})