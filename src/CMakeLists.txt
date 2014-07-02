
##---------------
IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") # check apple
  message(${CMAKE_SIZEOF_VOID_P})
  message(${CMAKE_GENERATOR})
endif()


#set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++ -Wall")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++")
#add_definitions(-D__gl_h_ -DGL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED)
add_executable(EA3D main.cpp)
target_link_libraries(EA3D ${LIBRARIES})

#set_target_properties(EA3D PROPERTIES COMPILE_FLAGS "-arch x86_64" LINK_FLAGS "-arch x86_64")
