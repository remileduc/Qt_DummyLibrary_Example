cmake_minimum_required(VERSION 3.10)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

add_library(DummyLib SHARED
	DummyLib.hpp
	DummyLib.cpp
	DummyLibStatic.cpp
)
target_compile_definitions(DummyLib PRIVATE
	DummyLib_EXPORT
)
target_include_directories(DummyLib PRIVATE
	${CMAKE_CURRENT_BINARY_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}
	../dummy_static/
)
target_link_libraries(DummyLib
	# Qt
	Qt5::Core
	Qt5::Gui
	Qt5::Widgets
	# DummyStatic
	DummyStatic
)
