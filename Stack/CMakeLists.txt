cmake_minimum_required(VERSION 3.14)

project(Stack)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  
set(CMAKE_CXX_EXTINSION OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wextra -Wall  -Wshadow ") # -Werror
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-exceptions")

option(ADD_TIDY "Activate clang-tidy" ON)
option(ADD_FORMAT "Activate clang-format" ON)
option(ADD_BENCHMARK "Activate benchmarks" ON)
option(ADD_TESTING "Activate google-testing" ON)

set(INCLUDES include)

add_library(stack INTERFACE)

target_include_directories(stack INTERFACE ${INCLUDES})

if(ADD_TIDY)
    set(CLANG_TIDY_FLAGS
        clang-tidy;
        --checks=*;
        --header-filter=.;
        --warning-as-errors=*;
        --format-style=file;    
    )
    message(STATUS "clang-tidy ON")
endif()

if(ADD_FORMAT)
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

if(ADD_BENCHMARK)
    message(STATUS "benchmark ON")
    add_subdirectory(benchmark)
endif()

if(ADD_TESTING)
    message(STATUS "testing ON")
    add_subdirectory(tests)
endif()