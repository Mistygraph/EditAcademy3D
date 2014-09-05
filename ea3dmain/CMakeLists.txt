
project(Ea3dMain)
# include headers
include_directories(include)

# include source files
AUX_SOURCE_DIRECTORY(src SOURCE_FILES)

# SET(BUILD_SHARED_LIBS ON)
message("-- BUILD_SHARED_LIBS: " ${BUILD_SHARED_LIBS})
message("-- SOURCE_FILES: " ${SOURCE_FILES})

add_executable(EA3D ${SOURCE_FILES})
target_link_libraries(EA3D ${LIBRARIES} )
