cmake_minimum_required(VERSION 3.10)

# Quotes are required when your project name contains spaces
project("Arena Prototype" C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# The target executable name should not have spaces. 
# Matching it to your folder name is the standard convention.
add_executable(arena_project src/main.c)

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