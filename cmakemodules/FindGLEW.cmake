# Try to find GLEW library
# Once done this will define
#  GLEW_FOUND - if system found GLEW library
#  GLEW_INCLUDE_DIRS - The GLEW include directories
#  GLEW_LIBRARS - The libraries needed to use GLEW
#  GLEW_DEFINITIONS - Compiler switches required for using GLEW


IF (WIN32)
	#message("-- " $ENV{PROGRAMFILES})
	FIND_PATH( GLEW_INCLUDE_DIRS GL/glew.h
		$ENV{PROGRAMFILES}/usr/include
		${PROJECT_SOURCE_DIR}/usr/include
		DOC "The directory where GL/glew.h resides")
	FIND_LIBRARY( GLEW_LIBRARIES
		NAMES glew GLEW glew32 glew32s
		PATHS
		$ENV{PROGRAMFILES}/usr/lib
		${PROJECT_SOURCE_DIR}/usr/bin
		${PROJECT_SOURCE_DIR}/usr/lib
		DOC "The GLEW library")
		
ELSE (WIN32)
	find_path(GLEW_INCLUDE_DIRS 
	  NAMES GL/glew.h
	  PATH /usr/local/include
	  DOC "The GLEW include directory")

	find_library(GLEW_LIBRARIES 
	  NAMES glew GLEW
	  PATHS /usr/local/lib
	  DOC "The GLEW library")

ENDIF (WIN32)
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