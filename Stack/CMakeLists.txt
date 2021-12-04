cmake_minimum_required(VERSION 3.14)

project(Stack)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  
set(CMAKE_CXX_EXTINSION OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wextra -Wall  -Wshadow ") # -Werror
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-exceptions")

option(TIDY "Activate clang-tidy" ON)
option(FORMAT "Activate clang-format" ON)

set(APP_INCLUDES include)

add_library(stack INTERFACE)

target_include_directories(stack INTERFACE ${APP_INCLUDES})

if(TIDY)
    set(CLANG_TIDY_FLAGS
        clang-tidy;
        --checks=*;
        --header-filter=.;
        --warning-as-errors=*;
        --format-style=file;    
    )
    message(STATUS "clang-tidy ON")
endif()

if(FORMAT)
    file(GLOB_RECURSE ALL_SOURCE_FILES *.cpp *.hpp)
    add_custom_target(
        format
        COMMAND clang-format
        -style=file
        -i
        ${ALL_SOURCE_FILES}
    )
    message(STATUS "clang-format ON")
endif()

add_subdirectory(tests)
add_subdirectory(benchmark)
