add_library(springfield1835 STATIC ".")

target_sources(springfield1835
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/springfield1835.cpp
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/springfield1835.hpp)

target_include_directories(springfield1835
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/..
)