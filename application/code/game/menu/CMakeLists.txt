add_library(menu "")

target_sources(menu
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/Menu.cpp
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Menu.hpp
)

target_include_directories(menu
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)    