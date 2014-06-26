# Try to find SFML library
# Once done this will define
#  SFML_FOUND - if system found SFML library
#  SFML_INCLUDE_DIRS - The SFML include directories
#  SFML_LIBRARS - The libraries needed to use SFML
#  SFML_DEFINITIONS - Compiler switches required for using SFML


find_path(SFML_INCLUDE_DIRS 
  NAMES SFML/Graphics.hpp #SFML/Audio.hpp SFML/Network.hpp SFML/System.hpp SFML/Window.hpp SFML/OpenGL.hpp
  PATH /usr/local/include
  DOC "The SFML include directory")

find_library(SFML_LIBRARIES 
  NAMES sfml-graphics # sfml-audio sfml-network sfml-system sfml-window
  PATHS /usr/local/lib
  DOC "The SFML library")


include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LOGGING_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(SFML DEFAULT_MSG SFML_INCLUDE_DIRS SFML_LIBRARIES)

if (SFML_FOUND)
  set(SFML_LIBRARIES ${SFML_LIBRARIES} )
  set(SFML_INCLUDE_DIRS ${SFML_INCLUDE_DIRS} )
  set(SFML_DEFINITIONS)
endif()

# Tell cmake GUIs to ignore the "local" variables.
mark_as_advanced(SFML_INCLUDE_DIRS SFML_LIBRARIES)