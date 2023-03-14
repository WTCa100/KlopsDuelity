#include "./duels.hpp"

Duel::Duel(Player* player, Shooter* oponent) : player_(player), oponent_(oponent)
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

    for(int i = 0; i < 3; i++)
    {
        i == 0 ? std::cout << "First move goes to " << player_->getEntityName() << std::endl : 
                 std::cout << "It's " << player_->getEntityName() << "s turn\n";
        player_->fireWeapon(oponent_);
        std::cout << "It's " << oponent_->getEntityName() << "s turn\n";        
        oponent_->fireWeapon(player_);
    }

    announceWinner();
    return winner_;
}

void Duel::announceWinner()
{
    // This is due to be changed but for now whoever has the bigger hp wins.    
    if(player_->getHealth() < oponent_->getHealth())
    {
        winner_ = oponent_;
        std::cout << oponent_->getEntityName() << " has won!\n";
    }
    else if(player_->getHealth() == oponent_->getHealth())
    {
        winner_ = nullptr;
        std::cout << "No one has one this duel, it's a tie!\n";
    }
    else
    {
        winner_ = player_;
        std::cout << player_->getEntityName() << " has won!\n";
    }
}

Duel::~Duel()
{
    std::cout << "Duel concluded. " << winner_->getEntityName() << " won!\n" ;
}