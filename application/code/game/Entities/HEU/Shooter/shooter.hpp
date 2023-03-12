#pragma once
#include<iostream>

#include "../heu.hpp"

namespace entities::HEUTypes
{
    class Shooter : public HEU
    {
        public:
        Shooter();
        ~Shooter();
    };
    
} // namespace entities