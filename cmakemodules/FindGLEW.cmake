# Try to find GLEW library
# Once done this will define
#  GLEW_FOUND - if system found GLEW library
#  GLEW_INCLUDE_DIRS - The GLEW include directories
#  GLEW_LIBRARS - The libraries needed to use GLEW
#  GLEW_DEFINITIONS - Compiler switches required for using GLEW


find_path(GLEW_INCLUDE_DIRS 
  NAMES GL/glew.h
  PATH /usr/local/include
  DOC "The GLEW include directory")

find_library(GLEW_LIBRARIES 
  NAMES glew GLEW
  PATHS /usr/local/lib
  DOC "The GLEW library")


include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LOGGING_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(GLEW DEFAULT_MSG GLEW_INCLUDE_DIRS GLEW_LIBRARIES)

if (GLEW_FOUND)
  set(GLEW_LIBRARIES ${GLEW_LIBRARIES} )
  set(GLEW_INCLUDE_DIRS ${GLEW_INCLUDE_DIRS} )
  set(GLEW_DEFINITIONS)
endif()

# Tell cmake GUIs to ignore the "local" variables.
mark_as_advanced(GLEW_INCLUDE_DIRS GLEW_LIBRARIES)