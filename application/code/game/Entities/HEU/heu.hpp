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
        /**
         * @brief Indicates what value will be assigned as ID into the next HEU instance
         */
        static uint32_t hIdGlobal_;
        
        protected:
        std::string name_;
        bool isPlayer_;
        uint32_t hId_;
        
        public:

        // Setters
        void setEntityName(const std::string& newName) { name_ = newName; }

        // Getters
        std::string getEntityName() const { return name_;}
        int getEntityId() const { return hId_; }

        HEU();
        HEU(bool isPlayer, std::string name);
        virtual ~HEU();
    };
} // Namespace entities
