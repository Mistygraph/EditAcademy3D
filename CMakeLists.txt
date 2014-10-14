cmake_minimum_required(VERSION 2.8)

project(EA3D)
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmakemodules)

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()
## macro - global scope

macro(include_module name)
	find_package(${name} 
				REQUIRED)
	if (NOT ${name}_FOUND)
		message(FATAL_ERROR "Package ${name} not found")
	endif (NOT ${name}_FOUND)

	# -D
	add_definitions(${${name}_DEFINITIONS}) 
	include_directories(${${name}_INCLUDE_DIRS})
	# message("include is " ${name}${${name}_INCLUDE_DIRS})
	# message("lib is " ${${name}_LIBRARY_DIRS})
	# set(LIBRARIES ${LIBRARIES} ${${name}_LIBRARY_DIRS})
	set(LIBRARIES ${LIBRARIES} ${${name}_LIBRARIES})
	# message("libs is " ${${name}_LIBRARIES})
	# message("libdir is " ${${name}_LIBRARY_DIRS})
endmacro()

macro(include_modules)
	#find OpenGL
	include_module("GLEW")
	#find OpenGL
	include_module("OPENGL")
	#find glfw3
	include_module("GLFW")
	#find jsoncpp
	include_module("JSONCPP")
	#find glm
	include_module("GLM")

endmacro()
# -----------------------------------------------------------------------------
macro(include_Boost)
	find_package(Boost
		COMPONENTS filesystem
		system
		log
		log_setup
		program_options
	REQUIRED)
	if(Boost_FOUND)
		# add_definitions(${${name}_DEFINITIONS})
		# message("boost include = " ${Boost_INCLUDE_DIR})
		# message("boost lib = " ${Boost_LIBRARIES})
		include_directories(${Boost_INCLUDE_DIR})
		set(LIBRARIES ${LIBRARIES} ${Boost_LIBRARIES})
	endif()
endmacro()
# -----------------------------------------------------------------------------

# ==== main =====
# system check
IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") # check apple
	MATH( EXPR bits " ${CMAKE_SIZEOF_VOID_P}*8 " ) 
	message("-- This environment is ${bits} bits")
endif()

message("-- Generator is " ${CMAKE_GENERATOR})
message("-- Cmake system Type: " ${CMAKE_SYSTEM_NAME})
message("-- Project binaray dir: " ${PROJECT_BINARY_DIR})

# include basic modules
include_modules()
include_Boost()

# SET( CMAKE_VERBOSE_MAKEFILE on )  # make debug flag
set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++ -Wall")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++")

# set paths
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

add_subdirectory(Ea3dMain)