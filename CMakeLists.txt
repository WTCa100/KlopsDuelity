cmake_minimum_required(VERSION 3.18)

PROJECT(KlopsDuelity LANGUAGES CXX)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 11)
set(CMKAE_CXX_FLAGS "-Wall -g -lncurses")

add_subdirectory(./application)