# Try to find GLFW library
# Once done this will define
#  GLFW_FOUND - if system found GLFW library
#  GLFW_INCLUDE_DIRS - The GLFW include directories
#  GLFW_LIBRARS - The libraries needed to use GLFW
#  GLFW_DEFINITIONS - Compiler switches required for using GLFW


find_path(GLFW_INCLUDE_DIRS 
  NAMES GLFW/glfw3.h
  PATH /usr/local/include
  DOC "The boost include directory")

find_library(GLFW_LIBRARIES
  NAMES glfw3.3
  PATHS /usr/local/lib 
  DOC "The GLFW library")


include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LOGGING_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(GLFW DEFAULT_MSG GLFW_INCLUDE_DIRS GLFW_LIBRARIES)

if (GLFW_FOUND)
  set(GLFW_LIBRARIES ${GLFW_LIBRARIES} )
  set(GLFW_INCLUDE_DIRS ${GLFW_INCLUDE_DIRS} )
  set(GLFW_DEFINITIONS)
endif()

# Tell cmake GUIs to ignore the "local" variables.
mark_as_advanced(GLFW_INCLUDE_DIRS GLFW_LIBRARIES)