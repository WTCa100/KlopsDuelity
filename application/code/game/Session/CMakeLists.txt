add_subdirectory(./Duel)

add_library(Session STATIC session.cpp session.hpp)

# Add gamestate later, it will be used to save the game