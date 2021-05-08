cmake_minimum_required(VERSION 3.14)
project(Metamod-P)

# Set path to engine SDK
set(OGS_SDK_PATH ${CMAKE_SOURCE_DIR}/../ogs-sdk/goldsrc
	CACHE PATH
	"Path to engine SDK"
)

include_directories(
	${OGS_SDK_PATH}/common
	${OGS_SDK_PATH}/engine
	${OGS_SDK_PATH}/pm_shared
	${CMAKE_CURRENT_SOURCE_DIR}/hlsdk/dlls
	${CMAKE_CURRENT_SOURCE_DIR}/metamod
)

# Remove prefixes from shared libs
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_SHARED_MODULE_PREFIX "")

# main module
add_subdirectory(metamod)

# sample plugins
add_subdirectory(stub_plugin)
#add_subdirectory(trace_plugin)
add_subdirectory(wdmisc_plugin)