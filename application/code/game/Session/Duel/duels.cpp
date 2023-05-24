#include <ncurses.h>

#include "./duels.hpp"
// Get modifiers
#include "../../Modifiers/Modifiers.hpp"

#include "../../Display/Graphical/Arena/Arena.hpp"


Duel::Duel(Player* player, Shooter* oponent) : player_(player), oponent_(oponent), distance_(12), duelShotCount_(0), playerDmgDealt_(0), enemyDmgDealt_(0)
{
    player_->setDuelCount(player_->getDuelCount() + 1);
    playerStartingHp_ = player_->getHealth();
    enemyStartingHp_  = oponent_->health_;
    calculateReward();
    printw("Stake is: %d$\n", reward_);
    printw("Duel starts!\n");
    printw("%s VS %s\n", player_->getEntityName().c_str(), oponent_->getEntityName().c_str());
}

void Duel::calculateReward()
{
    // reward will be based on personal charisma and enemy stats
    // Minimal value to win
    int rewardBase = 100;

    reward_ = Modifiers::calculateDuelReward(oponent_->currentlyHeldWeapon_->getWeaponBaseDmg(),
                                             oponent_->currentlyHeldWeapon_->getWeaponBaseAccuracy(),
                                             distance_, player_->statCharisma_, rewardBase);

}

bool Duel::askForSurrender()
{
    char input;
    while(true)
    {
        printw("Are you sure you want to end fight early?\n");
        input = getch();
        if(input == 'y' || input == '\n' || input == KEY_ENTER)
        {
            return true;
        }
        else if (input == 'n')
        {
            return false;
        }
        else
        {
            printw("Please enter a valid option!\n");
            getch();
        }
    }
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
    while((player_->isConcious_ && oponent_->isConcious_) /*|| surrender was choosen*/ && round < 20)
    {
        printw("Round %d\n", round + 1);
        round == 0 ? printw("First turn goes to %s\n", player_->name_.c_str()) : 
                     printw("The turn goes to %s\n", player_->name_.c_str());
        changeDistance();

        // Check if the game was cut short
        if(isCutShort_)
        {
            break;
        }
        player_->fireWeapon(oponent_, distance_);
        player_->addPlayerShotCount();
        duelShotCount_++;
        printw("Press any key to continue...\n");
        getch();

        printw("It's %s\'s turn\n", oponent_->name_.c_str());        
        oponent_->fireWeapon(player_, distance_);
        printw("Press any key to continue...\n");
        getch();
        round++;
    }
    getch();
    clear();
    announceWinner();
    return winner_;
}

void Duel::changeDistance()
{
    keypad(stdscr, TRUE); // Enable keypad 
    noecho(); // Disable input echoing

    int input = 0;

    Graphics::Arena* fightArena = new Graphics::Arena;
    WINDOW* arenaBox = newwin(10, 150, 0, 0);
    wrefresh(arenaBox);
    while(true)
    {
        // Move cursor outside of the box (just under box)
        move(13, 0);
        refresh();
        calculateReward();
        fightArena->makeArena(distance_, arenaBox);
        printw("Dmg: %.2f\n", player_->currentlyHeldWeapon_->getWeaponBaseDmg()/distance_);
        printw("Stake: := %d\n", reward_);
        printw("Chance of hitting %.2f\n", (player_->currentlyHeldWeapon_->getWeaponBaseAccuracy() * 10) * (100 / distance_) + static_cast<double>(player_->statAim_ * 10) / 100);
        printw("Your hp: %.2f - Oponent hp: %.2f\n", player_->health_, oponent_->health_);
        // Show weapon acc and dmg 
        printw("Do you want to get closer or further?\n");
        printw("<-/'a' closer | further ->/'d'\n");
        printw("You can also force quit the duel pressing 'q'\n");
        bool exitLoop = false;
        input = getch();
        //clear window
        wclear(arenaBox);
        switch(input)
        {
            case KEY_RIGHT:
            case 'A':
            case 'a':
                if(distance_ == 125)
                {
                    printw("Distance cannot be greater than 125!\n");
                    getch();
                    break;
                }     
                distance_++;
                break;
            case KEY_LEFT:
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
            case 'q':
            case 'Q':
                if(askForSurrender())
                {
                    isCutShort_ = true;
                    printw("Game ends early!\n");
                    getch();
                    if(fightArena)
                    {
                        delete fightArena;
                    }
                    return;
                }
            default:
                printw("Please use arrow keys to move!\n");
                getch();
                break;
        }

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
    delete fightArena;
    delwin(arenaBox);
}

// TODO: When player faces enemy with greater health than him, he will always lose unless he kills his oponent
// We will have to change that and check how many health each of the participants lost either in percentage or in plain numbers
void Duel::announceWinner()
{
    // This is due to be changed but for now whoever has the bigger hp wins.
    bool hasPlayerWon = false;
    bool wasTie = false;
    Graphics::Arena* winScreen = new Graphics::Arena;

    if(isCutShort_)
    {
        printw("This duel was cut short!\n");
    }

    // Set condition values
    playerDmgDealt_ = enemyStartingHp_ - oponent_->health_;
    enemyDmgDealt_ = playerStartingHp_ - player_->getHealth();
    printw("Player recieved %.2f dmg in this game\n", enemyDmgDealt_);
    printw("Oponent recieved %.2f dmg in this game\n", playerDmgDealt_);
    getch();

    if(playerDmgDealt_ < enemyDmgDealt_ || player_->isDead_)
    {
        winner_ = oponent_;
        winScreen->winScreen(false);
        printw("%s has won!\n", oponent_->name_.c_str());
        if(player_->isDead_)
        {
            printw("You literally died\n");
        }
    }
    else if(playerDmgDealt_ == enemyDmgDealt_)
    {
        wasTie = true;
        winner_ = nullptr;
        printw("No one has one a duel, it's a tie!\n");
    }
    else
    {
        winScreen->winScreen(true);
        player_->duelsWonCount_ ++;
        player_->setMoney(player_->getMoney() + reward_);
        player_->setMoneyWon(player_->getMoneyWon() + reward_);
        hasPlayerWon = true;
        winner_ = player_;
        printw("%s has won!\n", player_->name_.c_str());
        if(oponent_->isDead_)
        {
            printw("You killed that guy!\n");
        }
    }

    bool wasOneShot = false;
    if(duelShotCount_ == 1 && oponent_->isDead_)
    {
        wasOneShot = true;
    }

    expReward_ = Modifiers::calculateExpReward(oponent_->getPower(), duelShotCount_, distance_, hasPlayerWon, oponent_->isDead_, wasOneShot, wasTie);

}

Duel::~Duel()
{
    if(winner_)
    {
        printw("Duel has concluded %s won!\n", winner_->name_.c_str());
    }
    else
    {
        printw("Duel has concluded with a tie!\n");
    }
    
    if(!player_->isDead_)
    {
        player_->giveExp(expReward_);
        player_->setHealth(player_->getMaxHealth());
    }
    getch();
    clear();
}