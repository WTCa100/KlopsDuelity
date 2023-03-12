#pragma once

#include <iostream>

#include "../../weapons.hpp"

class springfield1835 : public Weapon
{   
private:
    /* data */
public:
    springfield1835();
    void present() override;
    ~springfield1835();
};  
