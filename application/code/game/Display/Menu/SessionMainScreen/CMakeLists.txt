add_library(SessionMainScreen "")

target_sources(SessionMainScreen
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/SessionMainScreen.cpp
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/SessionMainScreen.hpp
)

target_include_directories(SessionMainScreen
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(SessionMainScreen PUBLIC Display)
target_link_libraries(SessionMainScreen PUBLIC Menu)
target_link_libraries(SessionMainScreen PUBLIC InputCheck)
target_link_libraries(SessionMainScreen PUBLIC ${CURSES_LIBRARIES})
target_link_libraries(SessionMainScreen PUBLIC Town)