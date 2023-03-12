#include "./weapons.hpp"

uint32_t Weapon::wIdGlobal_ = 0;

Weapon::Weapon()
{
    std::cout << "Creating weapon with ID: " << wIdGlobal_ << std::endl;
    wId_ = wIdGlobal_;
    wIdGlobal_++;
}

Weapon::~Weapon()
{
    std::cout << "Deleting weapon with ID: " << wId_ << std::endl; 
}