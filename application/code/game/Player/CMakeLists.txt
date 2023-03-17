# Add source and header file into library
add_library(player STATIC player.cpp player.hpp)

add_subdirectory(./OriginStories)

# Link parent with child
target_link_libraries(player PUBLIC shooter)
target_link_libraries(player PUBLIC HEU)
target_link_libraries(player PUBLIC OriginStories)
target_link_libraries(player PUBLIC modifiers)

