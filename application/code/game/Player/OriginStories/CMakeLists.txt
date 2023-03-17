# Add source and header file into library
add_library(OriginStories STATIC originStories.cpp originStories.hpp)

target_link_libraries(OriginStories PUBLIC InputCheck)