cmake_minimum_required(VERSION 2.8)

project(EA3D)
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmakemodules)

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
  # include_module("GLEW")
  #finde SFML
  #include_module("SFML")
endmacro()

# ==== main =====
# include modules
include_modules()
SET( CMAKE_VERBOSE_MAKEFILE on )
set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++ -Wall")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++")
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

# message("PROJECT_BINARY_DIR = " ${PROJECT_BINARY_DIR})

add_subdirectory(ea3dmain)

