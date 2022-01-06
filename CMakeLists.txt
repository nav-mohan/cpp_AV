cmake_minimum_required(VERSION 3.14)
project(cpp_AV C CXX)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(libs/FFmpeg)

if(APPLE)
	list(APPEND EXTRA_LIBS "-framework OpenGL")
endif()

add_executable(${PROJECT_NAME} main.cpp read_md.hpp read_md.cpp)

#include_directories("${PROJECT_SOURCE_DIR}/src/")

target_link_libraries(${PROJECT_NAME} ${EXTRA_LIBS} FFmpeg)
