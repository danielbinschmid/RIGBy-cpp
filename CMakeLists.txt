# Basic sources
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/* ${CMAKE_CURRENT_SOURCE_DIR}/include/*)

find_package(Threads REQUIRED)


################################
########## Library ##########
################################
add_library(${RIGBYCPP} STATIC ${SRC_FILES})


target_include_directories(${RIGBYCPP} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
                                                      "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
                                                      "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/boost_1_74_0")



# link
target_link_libraries(${RIGBYCPP} PRIVATE Threads::Threads)
target_link_libraries(${RIGBYCPP} LINK_PUBLIC ${EIGEN})