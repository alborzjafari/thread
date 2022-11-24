cmake_minimum_required (VERSION 3.0)
project (Thread)

set (CMAKE_CXX_STANDARD 14)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

include_directories(${PROJECT_SOURCE_DIR} include)
add_subdirectory(src)

add_executable(thread_example example.cpp )
target_link_libraries(thread_example thread_static)
