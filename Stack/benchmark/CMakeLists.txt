cmake_minimum_required(VERSION 3.14)

project(Benchmark)

find_package(benchmark REQUIRED)

set(EXEC_FILE mybenchmark)
file(GLOB_RECURSE BENCH_SOURCES *.cpp)

add_executable(${EXEC_FILE} ${BENCH_SOURCES})

target_link_libraries(${EXEC_FILE} benchmark::benchmark)

add_custom_target(run_${EXEC_FILE}
		  COMMENT "Running ${EXEC_FILE}"
		  COMMAND ./${EXEC_FILE})
add_dependencies(run_${EXEC_FILE} ${EXEC_FILE})