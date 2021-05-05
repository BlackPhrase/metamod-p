cmake_minimum_required(VERSION 3.14)
project(Metamod-P)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/hlsdk/common
	${CMAKE_CURRENT_SOURCE_DIR}/hlsdk/dlls
	${CMAKE_CURRENT_SOURCE_DIR}/hlsdk/engine
	${CMAKE_CURRENT_SOURCE_DIR}/hlsdk/pm_shared
	${CMAKE_CURRENT_SOURCE_DIR}/metamod
)

# main module
add_subdirectory(metamod)

# sample plugins
add_subdirectory(stub_plugin)
#add_subdirectory(trace_plugin)
add_subdirectory(wdmisc_plugin)