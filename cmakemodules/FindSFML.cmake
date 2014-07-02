# Try to find SFML library
# Once done this will define
#  SFML_FOUND - if system found SFML library
#  SFML_INCLUDE_DIRS - The SFML include directories
#  SFML_LIBRARS - The libraries needed to use SFML
#  SFML_DEFINITIONS - Compiler switches required for using SFML

#set(sfml_lib Graphics Audio Network System Window) #OpenGL)
set(sfml_lib GRAPHICS AUDIO NETWORK SYSTEM WINDOW)
set(header_path /usr/local/include)
set(lib_path /usr/local/lib)

foreach(name ${sfml_lib})
  #header
  find_path(${name}_INCLUDE_DIRS 
    NAMES SFML/${name}
    PATH ${header_path}
    DOC "The SFML ${name} include directory")

  #lib
  #string(TOLOWER ${name} lname)
  find_library(${name}_LIBRARIES 
    NAMES sfml-${name}
    PATHS ${lib_path}
    DOC "The SFML ${name} library")

  string(TOUPPER ${name} uname)
  include(FindPackageHandleStandardArgs)
  # handle the QUIETLY and REQUIRED arguments and set LOGGING_FOUND to TRUE
  # if all listed variables are TRUE
  find_package_handle_standard_args(${name} DEFAULT_MSG ${name}_INCLUDE_DIRS ${name}_LIBRARIES)
  
  if (${name}_FOUND)
    set(SFML_LIBRARIES ${SFML_LIBRARIES} ${${name}_LIBRARIES})
    set(SFML_INCLUDE_DIRS ${SFML_INCLUDE_DIRS} ${${name}_INCLUDE_DIRS} )
    set(SFML_DEFINITIONS)
  endif()

endforeach()

find_package_handle_standard_args(SFML DEFAULT_MSG SFML_INCLUDE_DIRS SFML_LIBRARIES)

# Tell cmake GUIs to ignore the "local" variables.
mark_as_advanced(SFML_INCLUDE_DIRS SFML_LIBRARIES)