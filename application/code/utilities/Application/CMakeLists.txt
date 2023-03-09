add_library(Application "")

target_sources(Application
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/Application.cpp
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Application.hpp
)

target_include_directories(Application
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)    
