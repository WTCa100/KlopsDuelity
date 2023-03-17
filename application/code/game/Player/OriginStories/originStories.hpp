#pragma once
#include <string>

//#include "../player.hpp"

// Todo fill this up so that every origin will be a instance of specific type which automatically will asign values for the player
enum class PlayerOrigin
{
    // Dummies - change later
    kBasicAim = 1,
    kBasicVitality = 2,
    kBasicCharisma = 3
};

class Origin
{
    int baseOriginStatAim_;
    int baseOriginStatVitality_;
    int baseOriginStatCharisma_;
    const PlayerOrigin startingOrigin_;
    void initStatAssign();
    PlayerOrigin choosePlayerOrigin();
    public:
    Origin();
    ~Origin() = default;

    int getBaseOriginStatAim() const { return baseOriginStatAim_;}
    int getBaseOriginStatChraisma() const { return baseOriginStatCharisma_;}
    int getBaseOriginStatVitality() const { return baseOriginStatVitality_;}

};

