# Try to find ASSIMP library
# Once done this will define
#  ASSIMP_FOUND - if system found ASSIMP library
#  ASSIMP_INCLUDE_DIRS - The ASSIMP include directories
#  ASSIMP_LIBRARS - Link these to use Assimp
#  ASSIMP_DEFINITIONS - Compiler switches required for using ASSIMP


find_path(ASSIMP_INCLUDE_DIRS 
  NAMES assimp/ai_assert.h
  PATH /usr/local/include
  DOC "The Assimp include directory")

find_library(ASSIMP_LIBRARIES 
  NAMES ASSIMP assimp
  PATHS /usr/local/lib
  DOC "The Assimp library")


include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LOGGING_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(ASSIMP DEFAULT_MSG ASSIMP_INCLUDE_DIRS ASSIMP_LIBRARIES)

if (ASSIMP_FOUND)
  set(ASSIMP_LIBRARIES ${ASSIMP_LIBRARIES} )
  set(ASSIMP_INCLUDE_DIRS ${ASSIMP_INCLUDE_DIRS} )
  set(ASSIMP_DEFINITIONS)
endif()

# Tell cmake GUIs to ignore the "local" variables.
mark_as_advanced(ASSIMP_INCLUDE_DIRS ASSIMP_LIBRARIES)