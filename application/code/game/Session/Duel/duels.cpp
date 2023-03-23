#include <ncurses.h> // for getch()

#include "./duels.hpp"
// Get modifiers
#include "../../Modifiers/Modifiers.hpp"


Duel::Duel(Player* player, Shooter* oponent) : player_(player), oponent_(oponent), distance_(12)
{
    calculateReward();
    std::cout << "Stake is: " << reward_;
    std::cout << "Duel stars.\n";
    std::cout << player_->getEntityName() << " VS " << oponent_->getEntityName() << std::endl;
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
    std::cout << "Pick your weapons!\n";
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
    while((player_->isConcious_ && oponent_->isConcious_) /*|| surrender was choosen*/ && round < 10)
    {
        std::cout << "Round: " << round + 1 << std::endl;
        changeDistance();
        std::cout << "!-- Debug: Player health" << player_->health_ << std::endl;
        std::cout << "!-- Debug: Enemy health" << oponent_->health_ << std::endl;
        round == 0 ? std::cout << "First move goes to " << player_->name_ << std::endl : 
                 std::cout << "It's " << player_->name_ << "s turn\n";
        player_->fireWeapon(oponent_, distance_);
        std::cout << "It's " << oponent_->name_ << "s turn\n";        
        oponent_->fireWeapon(player_, distance_);
        std::cout << "Press any key to continue\n";
        std::cin.ignore();
        round++;
    }

    announceWinner();
    return winner_;
}

void Duel::changeDistance()
{
    std::cout << "!-- DEBUG: Adjusting of distance\n";
    // Initialize ncurses
    initscr();
    refresh(); // Match screen refresh
    keypad(stdscr, TRUE); // Enable keypad 
    cbreak(); // Enbale line buffering
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
                    refresh();
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
                refresh(); 
                getch();
                break;
        }

        // TODO: Make screen refresh here is possible
        clear();
        refresh();

        // Check if exit
        if(exitLoop)
        {
            printw("Distance adjusted!\n");
            refresh();            
            break;
        }

    }
    printw("!--- DEBUG: NCURSER: INPUT: %d\n", input);
    printw("Press any key to continue...\n");
    refresh();
    getch();
    clear();
    refresh();
    endwin();
    std::cout << "!--- DEBUG: DISTANCE " << distance_ << std::endl;
    std::cin.ignore();
}

void Duel::announceWinner()
{
    // This is due to be changed but for now whoever has the bigger hp wins.    
    if(player_->health_ < oponent_->health_)
    {
        winner_ = oponent_;
        std::cout << oponent_->getEntityName() << " has won!\n";
        if(player_->isDead_)
        {
            std::cout << "You literally died\n";
        }
    }
    else if(player_->health_ == oponent_->health_)
    {
        winner_ = nullptr;
        std::cout << "No one has one this duel, it's a tie!\n";
    }
    else
    {
        winner_ = player_;
        std::cout << player_->name_ << " has won!\n";
        if(oponent_->isDead_)
        {
            std::cout << "You killed that guy!\n";
        }
    }
}

Duel::~Duel()
{
    std::cout << "Duel concluded. " << winner_->name_ << " won!\n" ;
}