#include "./heu.hpp"

namespace entities
{

    HEU::HEU()
    {
        std::cout << "Creation of Human Entity Unit " << std::endl;
        hId_ = hIdGlobal_;
        hIdGlobal_++;
    }

    HEU::~HEU()
    {
        std::cout << "Destruction of Human Entity Unity " << std::endl;
    }

    uint32_t HEU::hIdGlobal_ = 0;

}