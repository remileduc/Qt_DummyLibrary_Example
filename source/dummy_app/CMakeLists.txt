cmake_minimum_required(VERSION 3.10)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

add_executable(DummyApp
	main.cpp
	Dummy.hpp
)
target_include_directories(DummyApp PRIVATE
	${CMAKE_CURRENT_BINARY_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}
	# DummyLib
	../dummy_lib/
)
target_link_libraries(DummyApp
	# Qt
	Qt5::Core
	Qt5::Gui
	Qt5::Widgets
	# DummyLib
	DummyLib
)

#########################
# Copy Libraries
# copy DummyLib in DummyApp build directory
add_custom_command(TARGET DummyApp POST_BUILD
	COMMAND "${CMAKE_COMMAND}" -E copy
		"$<TARGET_FILE:DummyLib>"
		"$<TARGET_FILE_DIR:DummyApp>"
	COMMENT "Copying dlls to output directory"
)
# run windeployqt on both DummyApp and DummyLib
if(WIN32)
	add_custom_command(TARGET DummyApp POST_BUILD
		COMMAND "${QT_ROOT_PATH}/bin/windeployqt.exe"
			$<$<CONFIG:debug>:--debug>$<$<CONFIG:release>:--release>
			--verbose 0
			--no-compiler-runtime
			--dir "$<TARGET_FILE_DIR:DummyApp>"
			"$<TARGET_FILE:DummyLib>"
		COMMENT "Deploying Qt for DummyLib..."
	)
	add_custom_command(TARGET DummyApp POST_BUILD
		COMMAND "${QT_ROOT_PATH}/bin/windeployqt.exe"
			$<$<CONFIG:debug>:--debug>$<$<CONFIG:release>:--release>
			--verbose 0
			--no-compiler-runtime
			--dir "$<TARGET_FILE_DIR:DummyApp>"
			"$<TARGET_FILE:DummyApp>"
		COMMENT "Deploying Qt for DummyApp..."
	)
endif()
