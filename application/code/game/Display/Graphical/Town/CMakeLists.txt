add_library(Town STATIC Town.cpp Town.hpp)

# Link parent with child
target_link_libraries(Town PUBLIC ${CURSES_LIBRARIES})
target_link_libraries(Town PUBLIC Display)