add_library(weapons)

target_sources(weapons PRIVATE
    ./weapons.cpp
    ./muskets/Springfield1835/springfield1835.cpp
)

target_sources(weapons PUBLIC
    ./weapons.cpp
    ./muskets/Springfield1835/springfield1835.hpp    
)

target_include_directories(weapons PUBLIC ./muskets)
target_link_directories(weapons PUBLIC ${CMAKE_CURRENT_LIST_DIR})