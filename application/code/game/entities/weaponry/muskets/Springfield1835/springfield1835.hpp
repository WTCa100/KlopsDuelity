#pragma once
#include <iostream>

#include "../../weapons.hpp"

    class Springfield1835 : public Weapon
    {
    private:
        /* data */
    public:
        void present() override;
        bool shoot() override;
        Springfield1835();
        ~Springfield1835();
    };
