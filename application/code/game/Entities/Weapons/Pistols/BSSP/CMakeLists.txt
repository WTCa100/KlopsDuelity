# Add source and header file into library
add_library(BSSP STATIC BSSP.cpp BSSP.hpp)

# Link parent with child
target_link_libraries(BSSP PUBLIC weapon)
