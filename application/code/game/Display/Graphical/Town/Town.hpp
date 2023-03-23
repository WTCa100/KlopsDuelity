#pragma once

#include "../../Display.hpp"

namespace Graphics
{
    class Town : public Display
    {
    public:
        void mainDisplay() override;
        Town()  = default;
        ~Town() = default;
    };
    
    
} // namespace Display::Graphics

