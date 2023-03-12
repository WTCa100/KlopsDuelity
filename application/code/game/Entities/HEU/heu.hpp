#pragma once
#include <iostream>

/**
 * @brief Human Entity Unit
 * 
 */
namespace entities
{
    class HEU
    {
        private:
        /**
         * @brief Indicates what value will be assigned as ID into the next HEU instance
         */
        static uint32_t hIdGlobal_;
        protected:
        uint32_t hId_;
        public:
        HEU();
        virtual ~HEU();
    };
} // Namespace entities
