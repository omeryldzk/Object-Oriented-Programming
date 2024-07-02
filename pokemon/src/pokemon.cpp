/* @Author
 * Student Name:  ÖMER YILDIZ
 * Student ID : 150200060
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "pokemon.h"

pokemon::pokemon(const std::string& name,int HP,const int damage,const int PowerUp,const int recharge)
: damage{damage},PowerUp{PowerUp},recharge{recharge},name{name},HP{HP}
    {
    }
int pokemon::PowerUpcheck(){
    if(rechargeCount >= this->getRecharge()){
        int rand_num = rand() % 100;
        if (rand_num <= this->getPowerUp())
        {
            rechargeCount = 0;
            return 1;
        }
    }
    return 0;
}
