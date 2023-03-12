#pragma once
#include <iostream>
#include <string>

/**
 * @brief Human Entity Unit
 * 
 */
namespace entities
{
    class HEU
    {
        
        private:
        std::string name_;
        /**
         * @brief Indicates what value will be assigned as ID into the next HEU instance
         */
        static uint32_t hIdGlobal_;
        protected:
        bool isPlayer_;
        uint32_t hId_;
        public:
        HEU();
        HEU(bool isPlayer, std::string name);
        virtual ~HEU();
    };
} // Namespace entities
