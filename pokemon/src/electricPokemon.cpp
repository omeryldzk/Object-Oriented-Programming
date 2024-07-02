/* @Author
 * Student Name:  ÖMER YILDIZ
 * Student ID : 150200060
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "electricPokemon.h"


electricPokemon::electricPokemon(const std::string& name,int HP,int damage)
    :
        pokemon{name,HP,damage,20,3}
    {
        rechargeCount = 3;
    }
void electricPokemon::attack(psychicPokemon* enemy){
    if(this->PowerUpcheck()){
        enemy->HP -= (this->extraDamage );
        this->rechargeCount = 0;
    }
    else
         enemy->HP -= this->getDamage();
}

int electricPokemon::checkState(char terrain){
    if(!stateCheck){
        if(confuseRound == 3 || terrain =='e'){
            confuseRound = 0;
            stateCheck = 1;
            return 1;
        }
        else{
            confuseRound++;
            return 0;
        }
    }   
    else{
        return 1;
    }
}
void electricPokemon::confuse(){
    confuseRound = 0;
    stateCheck = 0;
}
