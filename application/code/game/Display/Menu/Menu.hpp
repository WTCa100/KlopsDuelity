#pragma once

#include <string>

#include "../Display.hpp"

enum class MenuOptions
{
    kNone = -1,
    kStartGame = 1,
    kExit = 2
};

class Menu : public Display
{
private:
    MenuOptions actionChoosen_;
protected:
    virtual bool getUserInput(std::string& userInput);
public:
    virtual void mainDisplay() override;
    MenuOptions getActionChoosen() const {return actionChoosen_;}

    Menu();
    ~Menu();
};

