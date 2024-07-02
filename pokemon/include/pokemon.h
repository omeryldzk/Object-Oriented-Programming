#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>

class pokemon
{
public:
    pokemon(const std::string&,int,int,int,int);
    //function to check powerup
    int PowerUpcheck();
    //counter to count powerup recharge
    int rechargeCount{recharge};
    int HP;
    const std::string getName() const {return name;};
    const int& getDamage() const {return damage;}
    const int& getPowerUp() const {return PowerUp;}
    const int& getRecharge() const {return recharge;}
private:
    const std::string name;
    const int damage;
    const int PowerUp;
    const int recharge;


};
