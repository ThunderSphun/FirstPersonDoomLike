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

function(create_unit_test test_name test_file)
	add_executable(${test_name} ${test_file} ${SOURCE_FILES})
	target_include_directories(${test_name} PRIVATE test/include)
	target_link_libraries(${test_name} unity)
	target_link_libraries(${test_name} SDL2::SDL2)
	add_test(NAME ${test_name} COMMAND ${test_name})
endfunction()

create_unit_test(testCast test/test_cast.c)
create_unit_test(testPoint test/test_point.c)