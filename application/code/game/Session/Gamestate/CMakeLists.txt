add_library(gameSave STATIC gameSave.cpp gameSave.hpp)

target_link_libraries(gameSave PUBLIC Fmanager)