add_executable(${PROJECT_NAME} ./main.cpp)

add_subdirectory(./code)
include_directories(./code)

#include every new library here0
target_link_libraries(${PROJECT_NAME}
    Application
    NIO
    InputCheck    
    Session
    modifiers
    Duels
    OriginStories    
    player
    Display
    Town
    Arena
    Logo
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
    BSSP
    HarpersFerry1805
)