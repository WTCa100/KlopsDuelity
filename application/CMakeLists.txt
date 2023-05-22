add_executable(${PROJECT_NAME} ./main.cpp)

add_subdirectory(./code)
include_directories(./code)

#include every new library here0
target_link_libraries(${PROJECT_NAME}
    Application
    NIO
    Fmanager
    InputCheck    
    Session
    gameSave
    modifiers
    Duels
    OriginStories    
    player
    Display
    Town
    Arena
    Menu
    SessionMainScreen    
    HEU
    Names
    shooter
    shopkeeper
    weapon
    springfield1835
    moukahla
    tanegashima
    Enfield1861
    Hulverin
)