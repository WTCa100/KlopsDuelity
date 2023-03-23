add_executable(${PROJECT_NAME} ./main.cpp)

add_subdirectory(./code)
include_directories(./code)

#include every new library here
target_link_libraries(${PROJECT_NAME}
    Application
    InputCheck    
    Session
    modifiers
    Duels
    OriginStories    
    player
    Display
    Town
    Menu
    SessionMainScreen    
    HEU
    shooter
    shopkeeper
    weapon
    springfield1835
)