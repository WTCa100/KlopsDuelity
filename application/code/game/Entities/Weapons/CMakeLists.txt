add_subdirectory(./Muskets)

add_library(weapon STATIC weapons.cpp weapons.hpp)
target_link_libraries(weapon PUBLIC modifiers)