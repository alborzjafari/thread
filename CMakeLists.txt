cmake_minimum_required (VERSION 2.6)
project (Thread)

include_directories(${PROJECT_SOURCE_DIR} include)
add_subdirectory(src)

add_executable(thread_example example.cpp )
target_link_libraries(thread_example thread_static pthread)
