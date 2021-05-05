project(metamod)

option(METAMOD_STATIC "Build as a static library (for integration with other projects)" OFF)

set(METAMOD_BUILD_TYPE MODULE)

if(METAMOD_STATIC)
	set(METAMOD_BUILD_TYPE STATIC)
endif()

add_library(${PROJECT_NAME} ${METAMOD_BUILD_TYPE})

target_compile_definitions(${PROJECT_NAME}
	PRIVATE __METAMOD_BUILD__
)

target_include_directories(${PROJECT_NAME}
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} PROJECT_SOURCES)

if(WIN32)
	aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/win PROJECT_SOURCES_PLATFORM)
elseif(UNIX)
	aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/linux PROJECT_SOURCES_PLATFORM)
endif()

target_sources(${PROJECT_NAME}
	PRIVATE ${PROJECT_SOURCES}
	PRIVATE ${PROJECT_SOURCES_PLATFORM}
)