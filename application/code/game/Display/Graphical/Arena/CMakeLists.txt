add_library(Arena STATIC Arena.cpp Arena.hpp)

# Link parent with child
target_link_libraries(Arena PUBLIC ${CURSES_LIBRARIES})
target_link_libraries(Arena PUBLIC Display)