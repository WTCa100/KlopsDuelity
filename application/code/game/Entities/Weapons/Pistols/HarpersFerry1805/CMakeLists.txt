# Add source and header file into library
add_library(HarpersFerry1805 STATIC HarpersFerry1805.cpp HarpersFerry1805.hpp)

# Link parent with child
target_link_libraries(HarpersFerry1805 PUBLIC weapon)
