#include <ncurses.h> // for getch()

#include "./duels.hpp"
// Get modifiers
#include "../../Modifiers/Modifiers.hpp"


Duel::Duel(Player* player, Shooter* oponent) : player_(player), oponent_(oponent), distance_(12)
{
    calculateReward();
    printw("Stake is: %.2f$\n", reward_);
    printw("Duel starts!\n");
    printw("%s VS %s\n", player_->getEntityName().c_str(), oponent_->getEntityName().c_str());
}

void Duel::calculateReward()
{
    // reward will be based on personal charisma and enemy stats
    // Minimal value to win
    double rewardBase = 100;

//    double enemyModifer = oponent_->currentlyHeldWeapon_->getWeaponBaseDmg() + oponent_->currentlyHeldWeapon_->getWeaponBaseAccuracy();
//    double distanceModifier = distance_ * 2;
//    double charismaModifier = 1 + (static_cast<double>(player_->statCharisma_) / 10);
//    reward_ = (rewardBase + enemyModifer + distanceModifier) * charismaModifier;
    reward_ = Modifiers::duelReward(oponent_->currentlyHeldWeapon_->getWeaponBaseDmg(),
                                    oponent_->currentlyHeldWeapon_->getWeaponBaseAccuracy(),
                                    distance_, player_->statCharisma_, rewardBase);

}

void Duel::prepareForFight()
{
    printw("Prepare your weapons!\n");
    if(player_)
    {
        player_->pickWeapon();
        // Todo: allow player to pick his gun from his inventory
    }
    if(oponent_)
    {
        oponent_->pickWeapon();
    }

}

Shooter* Duel::shootOut()
{
    int round = 0;
    while((player_->isConcious_ && oponent_->isConcious_) /*|| surrender was choosen*/ && round < 2)
    {
        printw("Round %d\n", round + 1);
        changeDistance();
        printw("! --- DEBUG: Distance: %.2f\n", distance_);        
        printw("!--- Debug: Player health %d\n", player_->health_);
        printw("!--- Debug: Enemy health %d\n", oponent_->health_);
        round == 0 ? printw("First turn goes to %s\n", player_->name_.c_str()) : 
                     printw("The turn goes to %s", player_->name_.c_str());
        player_->fireWeapon(oponent_, distance_);
        printw("It's %s\'s turn\n", oponent_->name_.c_str());        
        oponent_->fireWeapon(player_, distance_);
        printw("Press any key to continue...\n");
        getch();
        round++;
    }

    announceWinner();
    return winner_;
}

void Duel::changeDistance()
{
    printw("!DEBUG --- Adjusting of distance\n");
    keypad(stdscr, TRUE); // Enable keypad 
    noecho(); // Disable input echoing

    int input = 0;

    while(true)
    {
        calculateReward();
        printw("You are %.2f meters away from your oponent\n", distance_);
        printw("Debug: Dmg w/ modifier %.2f\n", player_->currentlyHeldWeapon_->getWeaponBaseDmg()/distance_);
        printw("Debug: reward_ := %.2f\n", reward_);
        printw("Debug: Acc w/ modifier %.2f\n", (player_->currentlyHeldWeapon_->getWeaponBaseAccuracy() * 10) * (100 / distance_) + static_cast<double>(player_->statAim_ * 10) / 100);
        printw("Debug: Player vitality %d\n", player_->statVitality_);
        printw("Debug: Your hp: %.2f - Oponent hp: %.2f\n", player_->health_, oponent_->health_);
        // Show weapon acc and dmg 
        printw("Do you want to get closer or further?\n");
        printw("<-/'a' further | closer ->/'d'\n");                        
        bool exitLoop = false;
        input = getch();
        switch(input)
        {
            case KEY_LEFT:
            case 'A':
            case 'a':
                distance_++;
                break;
            case KEY_RIGHT:
            case 'D':
            case 'd':
                if(distance_ == 1)
                {
                    printw("Distance cannot be lower than 1!\n");
                    getch();
                    break;
                }            
                distance_--;
                break;
            case '\n':
            case '\r':
            case 27:
                exitLoop = true;
                break;
            default:
                printw("Please use arrow keys to move!\n");
                getch();
                break;
        }

        // TODO: Make screen refresh here is possible
        clear();

        // Check if exit
        if(exitLoop)
        {
            printw("Distance adjusted!\n");           
            break;
        }

    }
    clear();
    echo();
}

void Duel::announceWinner()
{
    // This is due to be changed but for now whoever has the bigger hp wins.    
    if(player_->health_ < oponent_->health_)
    {
        winner_ = oponent_;
        printw("%s has won!\n", oponent_->name_.c_str());
        if(player_->isDead_)
        {
            printw("You literally died\n");
        }
    }
    else if(player_->health_ == oponent_->health_)
    {
        winner_ = nullptr;
        printw("No one has one a duel, it's a tie!\n");
    }
    else
    {
        winner_ = player_;
        printw("%s has won!\n", player_->name_.c_str());
        if(oponent_->isDead_)
        {
            printw("You killed that guy!\n");
        }
    }
}

Duel::~Duel()
{
    printw("Duel has concluded %s won!\n", winner_->name_.c_str());
}