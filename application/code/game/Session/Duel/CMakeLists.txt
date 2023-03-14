add_library(Duels STATIC duels.cpp duels.hpp)

target_link_libraries(Duels ${CURSES_LIBRARIES})