# Add source and header file into library
add_library(springfield1835 STATIC springfield1835.cpp springfield1835.hpp)

# Link parent with child
target_link_libraries(springfield1835 PUBLIC weapon)
