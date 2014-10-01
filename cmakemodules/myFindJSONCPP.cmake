# Try to find JSONCPP library
# Once done this will define
#  JSONCPP_FOUND - if system found JSONCPP library
#  JSONCPP_INCLUDE_DIRS - The JSONCPP include directories
#  JSONCPP_LIBRARS - The libraries needed to use JSONCPP
#  JSONCPP_DEFINITIONS - Compiler switches required for using JSONCPP


find_path(JSONCPP_INCLUDE_DIRS 
  NAMES json/json.h
  PATH /usr/local/include
  DOC "The JSONCPP include directory")

find_library(JSONCPP_LIBRARIES 
  NAMES json 
  PATHS /usr/local/lib
  DOC "The JSONCPP library")


include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LOGGING_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(JSONCPP DEFAULT_MSG JSONCPP_INCLUDE_DIRS JSONCPP_LIBRARIES)

if (JSONCPP_FOUND)
  set(JSONCPP_LIBRARIES ${JSONCPP_LIBRARIES} )
  set(JSONCPP_INCLUDE_DIRS ${JSONCPP_INCLUDE_DIRS} )
  set(JSONCPP_DEFINITIONS)
endif()

# Tell cmake GUIs to ignore the "local" variables.
mark_as_advanced(JSONCPP_INCLUDE_DIRS JSONCPP_LIBRARIES)

