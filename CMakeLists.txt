project(mayaCommand)
cmake_minimum_required(VERSION 2.8)

# Find Package **************************************************************************************************
# need maya python
SET(MAYA_LOCATION "C:/tools/Autodesk/Maya2017" )
SET(MAYA_INCLUDE_DIR "C:/Users/zhangxuqiang/Desktop/maya_sdk_2017/devkitBase/include")
SET(MAYA_LIB_DIR ${MAYA_LOCATION}/lib)
SET(MAYA_PYTHON_INCLUDE ${MAYA_INCLUDE_DIR}/python2.7)
# set(MAYA_PYTHON_LIB,${MAYA_LIB_DIR}/python27.lib)
message("mayalib:" ${MAYA_LIB_DIR})
message("mayapythoninclude:" ${MAYA_PYTHON_INCLUDE})

# Include **************************************************************************************************
include_directories(${MAYA_PYTHON_INCLUDE} ${MAYA_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../pybind11/include ${CMAKE_CURRENT_SOURCE_DIR})


# Set source **************************************************************************************************
SET(SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/mayaCommand.cpp

)

# Set compiler **************************************************************************************************
SET(CMAKE_CXX_FLAGS "-std=c++11 -Wall -O3 -fPIC")


# Linker **************************************************************************************************
LINK_DIRECTORIES(
  ${MAYA_LIB_DIR}
)


# Make configuration 

add_library(mayaCommand SHARED ${SOURCES})
target_link_libraries(mayaCommand python27.lib OpenMaya.lib)
SET_TARGET_PROPERTIES(mayaCommand PROPERTIES PREFIX "")
SET_TARGET_PROPERTIES(mayaCommand PROPERTIES SUFFIX .pyd)

install(TARGETS mayaCommand DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/mayaCommand)
