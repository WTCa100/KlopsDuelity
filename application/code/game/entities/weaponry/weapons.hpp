#pragma once

class Weapon
{
private:
    static int wId_;
protected:
    double accuracy_;
    double dmgInflict_;
    double price_;
public:
    virtual bool shoot() = 0;
    virtual void present() = 0;
    Weapon();
    virtual ~Weapon();
};
    