cmake_minimum_required(VERSION 3.12)

# Quotes are required when your project name contains spaces
project("Arena Prototype" C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Dynamically scan the src folder for any C file and track changes
file(GLOB SRC_FILES CONFIGURE_DEPENDS "src/*.c")

# The target executable now uses the variable instead of a hardcoded list
add_executable(arena_project ${SRC_FILES})

target_include_directories(arena_project PRIVATE ${CMAKE_SOURCE_DIR}/include)

if(UNIX)
    target_link_libraries(arena_project PRIVATE
        ${CMAKE_SOURCE_DIR}/lib/libraylib.a
        GL m pthread dl rt X11
    )
elseif(WIN32)
    target_link_libraries(arena_project PRIVATE
        ${CMAKE_SOURCE_DIR}/lib/libraylib_windows.a
        opengl32 gdi32 winmm
    )
endif()