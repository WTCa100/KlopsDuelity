add_library(heu STATIC ".")

target_sources(heu
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/heu.cpp
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/heu.hpp)

    target_include_directories(heu
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )

add_subdirectory(./shooter)