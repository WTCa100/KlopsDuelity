add_library(Menu "")

target_sources(Menu
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/Menu.cpp
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Menu.hpp
)

target_include_directories(Menu
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

add_subdirectory(./SessionMainScreen)

target_link_libraries(Menu PUBLIC Display)
target_link_libraries(Menu PUBLIC InputCheck)
