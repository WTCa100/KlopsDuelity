
#include "./heu.hpp"

namespace entity
{
    uint32_t heu::hIdGlobal_ = 0;

    heu::heu() : isPlayer_(false)
    {
        hId_ = hIdGlobal_;
        std::cout << "Creation of heu: assigned Id " << hIdGlobal_ << std::endl;
        ++hIdGlobal_;
    }

    heu::heu(bool isPlayer) : isPlayer_(isPlayer)
    {
        hId_ = hIdGlobal_;        
        std::cout << "Creation of heu: assigned Id " << hIdGlobal_ << std::endl;
        ++hIdGlobal_;
    }

    heu::heu(const heu& instance)
    {
        hId_ = hIdGlobal_;        
        isPlayer_ = instance.isPlayer_;
        ++hIdGlobal_;
    }

    heu::~heu()
    {
        std::cout << "Destruction of heu: freed Id " << hId_ << std::endl; 
        --hIdGlobal_;
    }
} // namespace entity
