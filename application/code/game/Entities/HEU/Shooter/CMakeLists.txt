# Add source and header file into library
add_library(shooter STATIC shooter.cpp shooter.hpp)

# Link parent with child
target_link_libraries(shooter PUBLIC HEU)
