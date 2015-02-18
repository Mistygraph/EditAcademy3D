# Try to find RAPIDJSON library
# Once done this will define
#  RAPIDJSON_FOUND - if system found RAPIDJSON library
#  RAPIDJSON_INCLUDE_DIRS - The RAPIDJSON include directories
#  RAPIDJSON_DEFINITIONS - Compiler switches required for using RAPIDJSON


find_path(RAPIDJSON_INCLUDE_DIRS 
  NAMES rapidjson/rapidjson.h
  PATH /usr/local/include
  DOC "The RAPIDJSON include directory")


include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LOGGING_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(RAPIDJSON DEFAULT_MSG RAPIDJSON_INCLUDE_DIRS)

if (RAPIDJSON_FOUND)
  set(RAPIDJSON_INCLUDE_DIRS ${RAPIDJSON_INCLUDE_DIRS} )
  set(RAPIDJSON_DEFINITIONS)
endif()

# Tell cmake GUIs to ignore the "local" variables.
# mark_as_advanced(RAPIDJSON_INCLUDE_DIRS RAPIDJSON_LIBRARIES)