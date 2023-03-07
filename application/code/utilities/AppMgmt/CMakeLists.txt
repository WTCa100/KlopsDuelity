add_library(AppMgmt "")

target_sources(AppMgmt
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/Application.cpp
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Application.hpp
)

target_include_directories(AppMgmt
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)    