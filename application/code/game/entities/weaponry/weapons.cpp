#include <iostream>

#include "./weapons.hpp"


Weapon::Weapon()
{
    std::cout << "Weapon created: Id assinged" << wId_ << std::endl;
    wId_++;
}

Weapon::~Weapon()
{
    std::cout << "Weapon destroyed: Freed " << wId_ << std::endl;
    --wId_;
}
