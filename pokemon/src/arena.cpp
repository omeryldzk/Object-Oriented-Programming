/* @Author
 * Student Name:  ÖMER YILDIZ
 * Student ID : 150200060
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include "arena.h"

Arena::Arena(){
}
Arena::~Arena(){
    if(pokemon1)
        delete pokemon1;
    if(pokemon2)
        delete pokemon2;
}
void Arena::addPokemon(char type,const std::string& name,int HP,int damage){
    if(type == 'e'){
        pokemon1 = new electricPokemon(name,HP,damage);
    }
    if(type == 'p'){
        pokemon2 = new psychicPokemon(name,HP,damage);
    }
    this->restartTerrain();
}
void Arena::spawnTerrain(){
    int rand_num = rand() % 100;
    if (rand_num < 20)
    {
      terrain = 'e';
    }
    else if (rand_num < 40)
    {
        terrain = 'p';
    }
    else
    {
        terrain = 'n';
    }
    
}
void Arena::restartTerrain(){
    std::cout << " Terrain is reseting." << std::endl;
    this->spawnTerrain();
}
 void Arena::simulateBattle(){
    if(pokemon1!=nullptr && pokemon2!=nullptr){
        while(pokemon1->HP > 0 && pokemon2->HP >0){
            int heads = rand()%2;
            //if pokemon1's turn check for confusion
            if(heads == 1){
                if(pokemon1->checkState(terrain))
                    pokemon1->attack(pokemon2);
                heads = 0;
            }
            //if pokemon2's turn
            else if(heads == 0){
                pokemon2->attack(pokemon1,terrain);
                heads = 1;
            }
            this->printRoundStats(totalRound,heads);
            //terrain spawn again at the begining or after five rounds or 
            //equals to none
            if(terrainRound == 5 || terrain == 'n'){
                this->spawnTerrain();
                terrainRound = 0;
            }
            terrainRound++;
            totalRound++;
            pokemon1->rechargeCount++;
            pokemon2->rechargeCount++;     
    }
    this->printMatchResult();
 }
totalRound = 1;
terrainRound = 1;
}
void Arena::printRoundStats(int round,int heads){
    std::ofstream outfile;
    outfile.open("output.txt", std::ios_base::app); // append instead of overwrite
    if(terrain == 'p')
        outfile << "Psychic terrain "<<std::endl; 
    if(terrain == 'e')
        outfile << "Electric terrain "<<std::endl; 
    else if(terrain == 'n')
        outfile << "None terrain "<<std::endl; 
    if(heads)
        outfile << pokemon2->getName() << " is attacking"<<std::endl;
    else
        outfile << pokemon1->getName() << " is attacking"<<std::endl;
    outfile<< "HP of "<< pokemon1->getName()<<" "<<pokemon1->HP<<std::endl
    << "HP of "<< pokemon2->getName()<<" "<<pokemon2->HP<<std::endl;
    outfile<<"**************************************************************"<<std::endl;
    outfile.close();
}
void Arena::printMatchResult(){
    std::ofstream outfile;
    outfile.open("output.txt", std::ios_base::app); // append instead of overwrite
    outfile << "Total Round => "<< totalRound<<std::endl; 
    if(pokemon1->HP>0)
        outfile << "WINNER => "<< pokemon1->getName() <<std::endl;
    else if(pokemon2->HP>0)
        outfile << "WINNER => "<< pokemon2->getName() <<std::endl;
    else
        outfile << "DRAW "<<std::endl;
    outfile<<"**************************************************************"<<std::endl;
    outfile.close();
}