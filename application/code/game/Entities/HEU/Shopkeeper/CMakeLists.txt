# Add source and header file into library
add_library(shopkeeper STATIC shopkeeper.cpp shopkeeper.hpp)

# Link parent with child
target_link_libraries(shopkeeper PUBLIC HEU)
target_link_libraries(shopkeeper PUBLIC modifiers)
target_link_libraries(shopkeeper PUBLIC ${CURSES_LIBRARIES})
target_link_libraries(shopkeeper PUBLIC player)