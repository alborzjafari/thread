file(GLOB SOURCES *.cpp)
add_library(thread_static STATIC "${SOURCES}")
target_link_libraries(thread_static pthread)
set_target_properties(thread_static PROPERTIES OUTPUT_NAME thread_static)
