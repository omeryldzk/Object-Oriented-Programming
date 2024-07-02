/* @Author
 * Student Name:  ÖMER YILDIZ
 * Student ID : 150200060
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "psychicPokemon.h"


psychicPokemon::psychicPokemon(const std::string& name,int HP,int damage)
    :
        pokemon{name,HP,damage,30,5}
    {
        rechargeCount = 5;
    }
void psychicPokemon::attack(electricPokemon* enemy,char terrain){
    if(this->PowerUpcheck()){
        //if psychicPokemon has powerup and terrain is not electric
        //electricPokemon will be confused anyways
        if(terrain == 'p' || terrain == 'n'){
            enemy->confuse();
            if(terrain == 'p')
                //if terrain is psychic pokemon will damage double
                enemy->HP -= (this->extraDamage);
            else if(terrain == 'n')
                //otherwise pokemon will damage normally
                enemy->HP -= this->getDamage();
        }
        else 
            enemy->HP -= this->getDamage();
        this->rechargeCount = 0;
    }
    else 
        if(terrain == 'p')
            enemy->HP -= this->extraDamage;
        else
            enemy->HP -= this->getDamage();
}
