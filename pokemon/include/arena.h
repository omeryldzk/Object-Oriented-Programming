#ifndef ARENA_H
#define ARENA_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "electricPokemon.h"
#include "psychicPokemon.h"

class Arena 
{
public:
    Arena();
    ~Arena();
    void addPokemon(char,const std::string&,int,int);
    void simulateBattle();
    void printRoundStats(int,int);
    void printMatchResult();
    
private:
    psychicPokemon* pokemon2{nullptr};
    electricPokemon* pokemon1{nullptr};
    char terrain{'n'};
    void spawnTerrain();
    void restartTerrain();
    int terrainRound{1};
    int totalRound{1};
};

#endif
