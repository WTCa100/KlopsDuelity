add_library(Logo STATIC Logo.cpp Logo.hpp)

# Link parent with child
target_link_libraries(Logo PUBLIC ${CURSES_LIBRARIES})
target_link_libraries(Logo PUBLIC Display)