
project(Ea3dMain)

# -----------------------------------------------------------------------------
# include headers
include_directories(include)
file(GLOB HEADER_FILES "include/*.h*")

# include source files
AUX_SOURCE_DIRECTORY(src SOURCE_FILES)

# include shader files
file(GLOB SHADER_FILES "shaders/*")

# SET(BUILD_SHARED_LIBS ON)
message("-- BUILD_SHARED_LIBS: " ${BUILD_SHARED_LIBS})
message("-- HEADER_FILES: " ${HEADER_FILES})
message("-- SOURCE_FILES: " ${SOURCE_FILES})
message("-- SHADER_FILES: " ${SHADER_FILES})
# -----------------------------------------------------------------------------

# copy configuration file
# IDE specific
SET(OBJ_PATH "${Ea3dMain_SOURCE_DIR}/resources/obj")
SET(DAE_PATH "${Ea3dMain_SOURCE_DIR}/resources/dae")
SET(3DS_PATH "${Ea3dMain_SOURCE_DIR}/resources/3ds")
SET(SAMPLE_PATH "${Ea3dMain_SOURCE_DIR}/resources/sample")
SET(SETTING_PATH "${Ea3dMain_SOURCE_DIR}/setting.json")

IF(${CMAKE_GENERATOR} STREQUAL "Unix Makefiles")
	message("-- Generate a configure file to ${EA3D_BINARY_DIR}/setting.json")
	configure_file(${SETTING_PATH} "${EA3D_BINARY_DIR}/setting.json" @ONLY)
	
ELSEIF(${CMAKE_GENERATOR} STREQUAL "Xcode")
	message("-- Generate a configure file to ${EA3D_BINARY_DIR}/Debug/setting.json")
	configure_file(${SETTING_PATH} "${EA3D_BINARY_DIR}/Debug/setting.json" @ONLY)
	
	# Copy clang-format
	SET(clang-format "${EA3D_SOURCE_DIR}/.clang-format")
	message("-- Copy .clang-format file to ${EA3D_BINARY_DIR}/.clang-format")
	configure_file(${clang-format} "${EA3D_BINARY_DIR}/.clang-format")
ENDIF()





add_executable(EA3D ${SOURCE_FILES} ${HEADER_FILES} ${SHADER_FILES})
target_link_libraries(EA3D ${LIBRARIES})
