
project(Ea3dMain)
# include headers
include_directories(include)
file(GLOB HEADER_FILES "include/*.h*")


# include source files
AUX_SOURCE_DIRECTORY(src SOURCE_FILES)

# SET(BUILD_SHARED_LIBS ON)
message("-- BUILD_SHARED_LIBS: " ${BUILD_SHARED_LIBS})
message("-- HEADER_FILES: " ${HEADER_FILES})
message("-- SOURCE_FILES: " ${SOURCE_FILES})


# copy configuration file
SET(OBJ_PATH "${Ea3dMain_SOURCE_DIR}/resources/obj")
SET(DAE_PATH "${Ea3dMain_SOURCE_DIR}/resources/dae")
SET(SAMPLE_PATH "${Ea3dMain_SOURCE_DIR}/resources/sample")

SET(SETTING_PATH "${Ea3dMain_SOURCE_DIR}/setting.ini")
IF(${CMAKE_GENERATOR} STREQUAL "Unix Makefiles")
	configure_file(${SETTING_PATH} "${EA3D_BINARY_DIR}/setting.ini" @ONLY)
	message("-- configure file generated at ${EA3D_BINARY_DIR}/setting.ini")
	
ELSEIF(${CMAKE_GENERATOR} STREQUAL "Xcode")
	configure_file(${SETTING_PATH} "${EA3D_BINARY_DIR}/Debug/setting.ini" @ONLY)
	message("-- configure file generated at ${EA3D_BINARY_DIR}/Debug/setting.ini")
	
ENDIF()



add_executable(EA3D ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(EA3D ${LIBRARIES})
