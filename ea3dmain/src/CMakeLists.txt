
##---------------
IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") # check apple
  message("size of void = " ${CMAKE_SIZEOF_VOID_P})
  message("Generator = " ${CMAKE_GENERATOR})
endif()

add_executable(EA3D main.cpp)
target_link_libraries(EA3D ${LIBRARIES})

