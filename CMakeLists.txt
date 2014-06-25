cmake_minimum_required(VERSION 2.8)

project(EA3D)
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/CMake)

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()
## macro - global scope

macro(include_module name)
  find_package(${name} REQUIRED)
  if (NOT ${name}_FOUND)
    message(FATAL_ERROR "Package ${name} not found")
  endif (NOT ${name}_FOUND)
  add_definitions(${${name}_DEFINITIONS})
  include_directories(${${name}_INCLUDE_DIRS})
  set(LIBRARIES ${LIBRARIES} ${${name}_LIBRARIES})
endmacro()

macro(include_modules)
  #find OpenGL
  include_module("OPENGL")
  #find glfw3
  include_module("GLFW")
  #find glew
  include_module("GLEW")
  #finde SFML
  include_module("SFML")
endmacro()

#include modules
include_modules()

set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
add_executable(EA3D main.cpp)

target_link_libraries(EA3D ${LIBRARIES})