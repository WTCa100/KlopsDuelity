# Add source and header file into library
add_library(moukahla STATIC moukahla.cpp moukahla.hpp)

# Link parent with child
target_link_libraries(moukahla PUBLIC weapon)
