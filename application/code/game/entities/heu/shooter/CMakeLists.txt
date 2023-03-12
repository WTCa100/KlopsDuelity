add_library(shooter STATIC ".")

target_sources(shooter
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/shooter.cpp
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/shooter.hpp
)

target_include_directories(shooter
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)