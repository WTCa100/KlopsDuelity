#include <ncurses.h>

#include "./shopkeeper.hpp"

namespace entities::HEUTypes
{

    void Shopkeeper::presentItems()
    {
        noecho();
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
                if(tryToSell(itemId))
                {
                    // If weapon was sold, push it back into players owned weapon
                    customer_->addWeapon(weaponsForSale_[itemId].first);
                    // Change bool statment to true as the weapon was sold
                    weaponsForSale_[itemId].second = true;
                }
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

        echo();
    }

    void Shopkeeper::showItem(int itemId)
    {
        Weapon* selectedWeapon = weaponsForSale_[itemId].first;
        printw("Weapon: %s\n", selectedWeapon->getWeaponName().c_str());
        printw("Base Dmg: %.2f\n", selectedWeapon->getWeaponBaseDmg());
        printw("Base Accuracy: %.2f\n", selectedWeapon->getWeaponBaseAccuracy());
    }

    bool Shopkeeper::tryToSell(int itemId)
    {
        Weapon* desiredWeapon = weaponsForSale_[itemId].first;
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
        if(customer_->getMoney() < desiredWeapon->getWeaponBasePrice())
        {
            printw("Not enough money!\n");
            return false;
        }

        printw("You have bought %s\n", desiredWeapon->getWeaponName().c_str());
        return true;

    }

    void Shopkeeper::act()
    {
        // Present weapons
        presentItems();
    }

    Shopkeeper::Shopkeeper(Player* customer) : HEU(false, "no_name_entity"), customer_(customer)
    {
        printw("%s Entered shop: Shopkeeper spaned", customer->getEntityName().c_str());
        weaponsForSale_ = {std::make_pair(new entities::weapons::muskets::springfield1835, false) /*Add more weapons later*/};
    }
    Shopkeeper::~Shopkeeper()
    {
        printw("Shopowner dispwaned\n");
        // Delete evry pointer that was not sold (other pointers will be deleted later)
        for(auto weapon : weaponsForSale_)
        {
            delete weapon.first;
        }
    }
} // namespace entities::HEUTypes
