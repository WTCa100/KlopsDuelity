# Add source and header file into library
add_library(player STATIC player.cpp player.hpp)

# Link parent with child
target_link_libraries(player PUBLIC shooter)
target_link_libraries(player PUBLIC HEU)
