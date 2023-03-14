#include <ncurses.h> // for getch()

#include "./duels.hpp"

Duel::Duel(Player* player, Shooter* oponent) : player_(player), oponent_(oponent), distance_(12)
{
    std::cout << "Duel stars.\n";
    std::cout << player_->getEntityName() << " VS " << oponent_->getEntityName() << std::endl;
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
    //printw("You are %.2f meters away from your oponent\n", distance_);
    //printw("Do you want to get closer or further?\n");
    //printw("<- further | closer ->\n");
    refresh(); // Match screen refresh
    keypad(stdscr, TRUE); // Enable keypad 
    cbreak(); // Enbale line buffering
    noecho(); // Disable input echoing

    int input = 0;

    while(true)
    {
        printw("You are %.2f meters away from your oponent\n", distance_);
        printw("Debug: Dmg w/ modifier %.2f\n", player_->currentlyHeldWeapon_->getWeaponBaseDmg()/distance_);
        printw("Debug: Acc w/ modifier %.2f\n", (player_->currentlyHeldWeapon_->getWeaponBaseAccuracy() * 10) * (100 / distance_));
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
                clear();
                refresh();
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
                    clear();
                    refresh();
                    break;
                }
                clear();
                refresh();                
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
                clear();
                refresh();            
                break;
        }

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