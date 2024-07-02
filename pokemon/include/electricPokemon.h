#ifndef ELECTRICPOKEMON_H
#define ELECTRICPOKEMON_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "pokemon.h"
#include "psychicPokemon.h"

class psychicPokemon;

class electricPokemon : public pokemon
{
public:
    electricPokemon(const std::string& name,int HP,int damage);
    void attack(psychicPokemon*);
    void confuse();
    int checkState(char);
private:
    const int extraDamage {this->getDamage()*3};
    int confuseRound{0};
    //if pokemon is confused statecheck sets to 0
    int stateCheck{1};


};

#endif