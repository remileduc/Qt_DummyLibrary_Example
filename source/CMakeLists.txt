cmake_minimum_required(VERSION 3.10)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#########################
# C++
enable_language("CXX")
include(CheckIncludeFileCXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	add_compile_options(
		# generic
		"-Wall" "-Wextra" "-pedantic"
	)
	# debug
	if ("${CMAKE_BUILD_TYPE}" STREQUAL "DEBUG")
		add_compile_options("-g" "-O0")
	# release
	else()
		add_compile_options("-O3")
	endif()
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	include(ProcessorCount)
	ProcessorCount(N)
	add_compile_options(
		# generic
		"/Zc:__cplusplus" "/cgthreads${N}" "/W4"
		# debug
		"$<$<CONFIG:debug>:/DEBUG>"
		"$<$<CONFIG:debug>:/Od>"
		# release
		"$<$<CONFIG:release>:/O2>"
	)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:CONSOLE")
endif()

#########################
# Qt setup
if(WIN32)
	set(QT_ROOT_PATH "C:/Qt/5.11.1/msvc2017_64")
	set(CMAKE_PREFIX_PATH ${QT_ROOT_PATH})
endif()
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#########################
# Project
project(DummyApp CXX)

#########################
# DummyStatic
add_subdirectory("dummy_static")

#########################
# DummyLib
add_subdirectory("dummy_lib")

#########################
# DummyApp
add_subdirectory("dummy_app")

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT DummyApp)
