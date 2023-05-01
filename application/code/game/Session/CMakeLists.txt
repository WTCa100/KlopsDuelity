add_subdirectory(./Duel)
add_subdirectory(./Gamestate)

add_library(Session STATIC session.cpp session.hpp)

# Add gamestate later, it will be used to save the game

target_link_libraries(springfield1835 PUBLIC weapon)
target_link_libraries(moukahla PUBLIC weapon)