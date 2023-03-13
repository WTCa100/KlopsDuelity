#include "./player.hpp"

Player::Player(std::string name) : Shooter(true, name)
{
    std::cout << "Player created\n";
}

Player::~Player()
{
    std::cout << "Player despawned\n";
}