#pragma once

#include <iostream>

#include "../../weapons.hpp"

namespace entities::weapons::muskets
{

    class springfield1835 : public Weapon
    {   
    private:
        /* data */
    public:
        springfield1835();
        void present() override;
        ~springfield1835();
    };  
    

} // namespace entities::weapons::muskets


