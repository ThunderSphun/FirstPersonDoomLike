cmake_minimum_required(VERSION 3.22)
project(FirstPersonDoomLike C)

set(CMAKE_C_STANDARD 99)

# Load SDL2
add_subdirectory(lib/SDL2)

set(SOURCE_FILES
		source/math/point.c
		source/screen/window.c
			source/screen/event/event.c source/screen/event/keyEvent.c source/screen/event/mouseEvent.c)

include_directories(include)
include_directories(include/internal)
add_executable(${PROJECT_NAME} source/main.c ${SOURCE_FILES})

# Link SDL2
target_link_libraries(${PROJECT_NAME} SDL2::SDL2)

# copy runtime dll to executable
if(WIN32)
	add_custom_command(
			TARGET ${PROJECT_NAME} POST_BUILD
			COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:SDL2::SDL2>" ${CMAKE_BINARY_DIR}
			VERBATIM
	)
endif()

enable_testing()

add_subdirectory(lib/unity)

add_executable(testCast test/test_cast.c ${SOURCE_FILES})
target_link_libraries(testCast unity)
target_link_libraries(testCast SDL2::SDL2)
add_test(NAME testCast COMMAND testCast)