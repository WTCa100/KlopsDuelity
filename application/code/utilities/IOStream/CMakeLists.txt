add_library(NIO STATIC NIO.cpp NIO.hpp)

target_link_libraries(NIO ${CURSES_LIBRARIES})