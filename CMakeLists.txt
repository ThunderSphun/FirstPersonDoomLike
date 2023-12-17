cmake_minimum_required(VERSION 3.22)
project(FirstPersonDoomLike C)

set(CMAKE_C_STANDARD 99)

# Load SDL2
add_subdirectory(lib/SDL2)

include_directories(include)
include_directories(include/internal)
add_executable(${PROJECT_NAME} source/main.c source/screen/window.c source/screen/event/event.c source/screen/event/keyEvent.c)

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