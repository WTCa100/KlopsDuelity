#pragma once
#include <iostream>

namespace entities
{
    class Weapon
    {
    private:
        static uint32_t wIdGlobal_;
    protected:
        uint32_t wId_;
    public:
        Weapon(/* args */);
        virtual void present() = 0;
        virtual ~Weapon();
    };

}
