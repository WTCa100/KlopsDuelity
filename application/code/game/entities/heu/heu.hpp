#include <iostream>
#pragma once

namespace entity
{
    /**
     * @brief Human Entity Unit
     * 
     */
    class heu
    {
    private:
        static uint32_t hIdGlobal_;
        uint32_t hId_;
    protected:
        bool isPlayer_;
    public:
        heu();
        heu(bool isPlayer);
        heu(const heu& instance);
        virtual ~heu();
    };

} // namespace entity

