#include "./springfield1835.hpp"

    Springfield1835::Springfield1835()
    {
        std::cout << "Springfield model 1835 created\n";
    }

    void Springfield1835::present()
    {
        std::cout << "It's a springfiled - noice\n";
    }

    bool Springfield1835::shoot()
    {
        std::cout << "*Shooting noises*\n";
    }

    Springfield1835::~Springfield1835()
    {
        std::cout << "Springfield model 1835 destroyed\n";
    }
