cmake_minimum_required(VERSION 3.12)

set( CMAKE_VERBOSE_MAKEFILE off )

project(image-tools
	VERSION 0.1
	LANGUAGES CXX
)

find_package( OpenCV REQUIRED )

add_executable(image-tools
	    src/main.cpp
		src/Panaroma.cpp src/Panaroma.h src/ErrHandl.h)

set_target_properties(image-tools
		PROPERTIES CXX_STANDARD 17
		CXX_STANDARD_REQUIRED ON
		CXX_EXTENSIONS OFF
		)


target_include_directories(image-tools
		PRIVATE ${OpenCV_INCLUDE_DIRS}
		PRIVATE thirdparty
		)

add_subdirectory(thirdparty/fmt)

target_link_libraries(image-tools
		${OpenCV_LIBS}
    	fmt::fmt
)

