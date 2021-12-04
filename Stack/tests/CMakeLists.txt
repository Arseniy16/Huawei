cmake_minimum_required(VERSION 3.14)

project(StackTest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  

message("include testing")

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(PROJECT_TEST test.cpp)
set(EXEC_FILE stack_test)

enable_testing()

add_executable(${EXEC_FILE} ${PROJECT_TEST})

target_link_libraries(${EXEC_FILE} gtest_main)

include(GoogleTest)
gtest_discover_tests(${EXEC_FILE})

add_custom_target(
    run_${EXEC_FILE}
    COMMENT "Running ${EXEC_FILE}"
    COMMAND ./${EXEC_FILE}
)

add_dependencies(run_${EXEC_FILE} ${EXEC_FILE})

if(ADD_SANITIZERS)
    message("Build with sanitizers")
    target_compile_options(${EXEC_FILE} PUBLIC -fsanitize=address -g)
    set_target_properties(${EXEC_FILE} PROPERTIES LINK_FLAGS "-fsanitize=address")
endif()