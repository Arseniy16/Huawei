cmake_minimum_required(VERSION 3.14)

project(QueueTest)

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


# set(EXEC_FILE queue_test)

enable_testing()

# add_executable(${EXEC_FILE} ${PROJECT_TEST})

# target_link_libraries(${EXEC_FILE} queue gtest_main)

# add_dependencies(run_${EXEC_FILE} queue)



option(TEST_LIST_QUEUE "Activate list_queue testing" ON)
option(TEST_STACK_QUEUE "Activate stack_queue testing" ON)
# option(ADD_SANITIZERS "Activate stack_queue testing" ON)

set(PROJECT_TEST test.cpp)

# if(TEST_LIST_QUEUE)
#     # message("Testing list_queue ON")
#     set(EXEC_FILE queue_list)
#     add_executable(${EXEC_FILE} ${PROJECT_TEST})
#     target_link_libraries(${EXEC_FILE} queue gtest_main)

#     include(GoogleTest)
#     gtest_discover_tests(${EXEC_FILE})

#     add_custom_target(
#         run_${EXEC_FILE}
#         COMMENT "Running ${EXEC_FILE}"
#         COMMAND ./${EXEC_FILE}
#     )
#     add_dependencies(run_${EXEC_FILE} ${EXEC_FILE})

#     if(ADD_SANITIZERS)
#         message("Build with sanitizers")
#         target_compile_options(${EXEC_FILE} PUBLIC -fsanitize=address -g)
#         set_target_properties(${EXEC_FILE} PROPERTIES LINK_FLAGS "-fsanitize=address")
#     endif()
# endif()



if(TEST_STACK_QUEUE)
    # message("Testing stack_queue ON")
    set(EXEC_FILE queue_stack)
    add_executable(${EXEC_FILE} ${PROJECT_TEST})
    target_link_libraries(${EXEC_FILE} queue gtest_main)

    include(GoogleTest)
    gtest_discover_tests(${EXEC_FILE})

    add_custom_target(
        run_${EXEC_FILE}
        COMMENT "Running ${EXEC_FILE}"
        COMMAND ./${EXEC_FILE}
    )
    add_dependencies(run_${EXEC_FILE} queue)

    if(ADD_SANITIZERS)
        message("Build with sanitizers")
        target_compile_options(${EXEC_FILE} PUBLIC -fsanitize=address -g)
        set_target_properties(${EXEC_FILE} PROPERTIES LINK_FLAGS "-fsanitize=address")
    endif()
endif()

