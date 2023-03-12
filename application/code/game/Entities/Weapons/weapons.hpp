#pragma once
#include <iostream>

class Weapon
{
private:
    static uint32_t wIdGlobal_;
    uint32_t wId_;
public:
    Weapon(/* args */);
    virtual void present() = 0;
    virtual ~Weapon();
};
