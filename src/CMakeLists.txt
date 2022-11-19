file(GLOB SOURCES *.cpp)
add_library(thread_static STATIC "${SOURCES}")
set_property(TARGET thread_static PROPERTY POSITION_INDEPENDENT_CODE ON)
target_link_libraries(thread_static pthread)
set_target_properties(thread_static PROPERTIES OUTPUT_NAME thread_static)

