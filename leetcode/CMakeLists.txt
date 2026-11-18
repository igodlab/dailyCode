cmake_minimum_required(VERSION 3.20)
project(leetcode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)   # for clangd / IDE tooling

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# --- helpers: header-only INTERFACE library ---------------------------------
add_library(lc_utils INTERFACE)
target_include_directories(lc_utils INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Warnings + sanitizers in Debug, propagated to every problem that links lc_utils
# Turn off with -DLC_SANITIZE=OFF if your toolchain lacks the sanitizer runtime.
option(LC_SANITIZE "Enable ASan + UBSan in Debug builds" ON)

set(IS_GNU_LIKE "$<CXX_COMPILER_ID:GNU,Clang,AppleClang>")
if(LC_SANITIZE)
    set(SANITIZE "$<AND:${IS_GNU_LIKE},$<CONFIG:Debug>>")
else()
    set(SANITIZE "0")
endif()

target_compile_options(lc_utils INTERFACE
    $<${IS_GNU_LIKE}:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive->
    $<${SANITIZE}:-fsanitize=address,undefined -fno-omit-frame-pointer>
)
target_link_options(lc_utils INTERFACE
    $<${SANITIZE}:-fsanitize=address,undefined>
)

# --- one executable per problem, discovered automatically --------------------
# problems/0001-0099/lc0016.cpp  ->  target lc0016  ->  build/bin/0001-0099/lc0016
set(PROBLEMS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/problems)
file(GLOB_RECURSE PROBLEM_SOURCES CONFIGURE_DEPENDS ${PROBLEMS_DIR}/lc*.cpp)

foreach(src IN LISTS PROBLEM_SOURCES)
    get_filename_component(name ${src} NAME_WE)       # lc0016
    get_filename_component(src_dir ${src} DIRECTORY)
    file(RELATIVE_PATH bucket ${PROBLEMS_DIR} ${src_dir})   # 0001-0099

    # Target names are global, so the same problem in two folders would clash.
    if(TARGET ${name})
        message(FATAL_ERROR "Duplicate problem '${name}': ${src}")
    endif()

    add_executable(${name} ${src})
    target_link_libraries(${name} PRIVATE lc_utils)
    # The (empty) generator expression stops multi-config generators
    # (Visual Studio, Ninja Multi-Config) from appending a Debug/ subfolder.
    set_target_properties(${name} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${bucket}$<0:>)
endforeach()
