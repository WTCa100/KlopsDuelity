#pragma once

#include <iostream>

#include "../../weapons.hpp"

namespace entities::weapons::muskets
{

    class Springfield1835 : public Weapon
    {   
        public:
        Springfield1835();
        void present() override;
        ~Springfield1835();
    };  
    

} // namespace entities::weapons::muskets


