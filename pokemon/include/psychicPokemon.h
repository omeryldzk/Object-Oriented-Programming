#ifndef PSYCHICPOKEMON_H
#define PSYCHICPOKEMON_H
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "pokemon.h"
#include "electricPokemon.h"

class electricPokemon;

class psychicPokemon : public pokemon
{
public:
    psychicPokemon(const std::string&name,int HP,int damage);
    //function to attack electricPokemon takes char terrain as param
    void attack(electricPokemon*,char);
    
private:
    //Powerup damage 
    const int extraDamage {this->getDamage()*2};
};

#endif