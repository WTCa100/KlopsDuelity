#include <ncurses.h>

#include "./shopkeeper.hpp"

// Import every weapon
#include "../../Weapons/Muskets/Springfield1835/springfield1835.hpp"
#include "../../Weapons/Muskets/Moukahla/moukahla.hpp"
#include "../../Weapons/Muskets/Enfield1861/Enfield1861.hpp"
#include "../../Weapons/Muskets/Hulverin/Hulverin.hpp"
#include "../../Weapons/Muskets/Tanegashima/Tanegashima.hpp"
#include "../../Weapons/Pistols/BSSP/BSSP.hpp"
#include "../../Weapons/Pistols/HarpersFerry1805/HarpersFerry1805.hpp"

namespace entities::HEUTypes
{

    void Shopkeeper::presentItems()
    {
        //noecho();
        int itemId = 0;
        bool exitLoop = false;
        while(!exitLoop)
        {
            // Always show first item at start
            printw("<- Previous item | Next item -> | q - exit\n");
            showItem(itemId);
            printw("Would you like to buy this weapon?\n");
            int input = getch();
            switch (input)
            {
            case KEY_LEFT:
                if(itemId == 0)
                {
                    itemId = weaponsForSale_.size() - 1;
                    break;
                }
                itemId--;
                break;
            case KEY_RIGHT:
                if(itemId == weaponsForSale_.size() - 1)
                {
                    itemId = 0;
                    break;
                }
                itemId++;
                break;
            case 'q':
            case 'Q':
                exitLoop = true;
                break;
            case KEY_ENTER:
            case '\n':
                if(tryToSell(itemId))
                {
                    // If weapon was sold, push it back into players owned weapon
                    customer_->addWeapon(weaponsForSale_[itemId].first);
                    // Change bool statment to true as the weapon was sold
                    weaponsForSale_[itemId].second = true;
                }
                printw("Press any key to continue...\n");
                getch();
                break;
            default:
                printw("Please enter a valid option!\n");
                refresh(); 
                getch();            
                break;
            }
            clear();
            refresh();
        }

        //echo();
    }

    void Shopkeeper::showItem(int itemId)
    {
        // Show it visually 
        Weapon* selectedWeapon = weaponsForSale_[itemId].first;
        selectedWeapon->presentStats(true);
    }

    bool Shopkeeper::tryToSell(int itemId)
    {
        Weapon* desiredWeapon = weaponsForSale_[itemId].first;
        double currentPlayerBalance = customer_->getMoney();
        double finalPrice = desiredWeapon->getWeaponModPrice(customer_->getStatVit());
        // Player shall not have any duplicate weapons
        for(auto weapon : customer_->getWeaponsOwned())
        {
            if(desiredWeapon->getWeaponName() == weapon->getWeaponName())
            {
                printw("You already own this weapon!\n");
                return false;
            }
        }

        // Check ammount of money
        if(currentPlayerBalance < finalPrice)
        {
            printw("Not enough money!\n");
            return false;
        }

        // Substract money out of player
        printw("You have bought %s\n", desiredWeapon->getWeaponName().c_str());
        customer_->setMoney(currentPlayerBalance - finalPrice);
        return true;

    }

    void Shopkeeper::act()
    {
        // Present weapons
        presentItems();
    }

    Shopkeeper::Shopkeeper(Player* customer) : HEU(false, "no_name_entity"), customer_(customer)
    {
        printw("%s Entered shop: Shopkeeper spawned", customer->getEntityName().c_str());
        weaponsForSale_ = 
        {
            std::make_pair(new entities::weapons::muskets::Springfield1835, false),
            std::make_pair(new entities::weapons::muskets::Moukahla, false),
            std::make_pair(new entities::weapons::muskets::Enfield1861, false),
            std::make_pair(new entities::weapons::muskets::Hulverin, false),
            std::make_pair(new entities::weapons::muskets::Tanegashima, false),
            std::make_pair(new entities::weapons::pistols::BSSP, false),
            std::make_pair(new entities::weapons::pistols::HarpersFerry1805, false)
            /*Add more weapons later*/
        };
    }
    Shopkeeper::~Shopkeeper()
    {
        printw("Shopowner dispwaned\n");
        // Delete evry pointer that was not sold (other pointers will be deleted later)
        for(auto weapon : weaponsForSale_)
        {
            if(!weapon.second)
            {
                delete weapon.first;
            }
        }
    }
} // namespace entities::HEUTypes
