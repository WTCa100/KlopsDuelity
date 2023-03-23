#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "../heu.hpp"
#include "../../../Player/player.hpp"

// Import every weapon
#include "../../Weapons/weapons.hpp"
#include "../../Weapons/Muskets/Springfield1835/springfield1835.hpp"

namespace entities::HEUTypes
{
    class Shopkeeper : public HEU
    {
    private:
        /// @brief First - Weapon for sale entry | Second - Is it sold
        std::vector <std::pair<entities::Weapon*, bool>> weaponsForSale_;
        void presentItems();
        void showItem(int itemId);
        bool tryToSell(int itemId);
        Player* customer_;
        // This is a utility function
    public:
        void act();
        Shopkeeper(Player* customer);
        ~Shopkeeper();
    };

} // namespace entities::HEUTypes
