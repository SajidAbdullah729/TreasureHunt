#ifndef PLAYER_H
#define PLAYER_H
#include "Gameplay.h"
#include "Board.h"
#include "Dungeon.h"
#include "Gem.h"
#include "MagicApple.h"
#include "Monster.h"
#include "Player.h"
#include "Rock.h"
#include "SideWall.h"
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<cmath>
#include<stdlib.h>
#include<vector>
#include<string>
#include<ctime>
#include<algorithm>
using namespace std;
typedef vector<vector<char> > vll;

class Player
{
private:
    int posx,posy,turn,point,energy;
    string name;
public:
    Player();
    void setPosx(int );

    void setPosy(int );

    void setTurn(int );

    void setEnergy(int);

    void setPoint(int);

    void setName(string);

    int getPosx();

    int getPosy();

    int getTurn();


    int getPoint();

    string getName();

    int getEnergy();



};

#endif // PLAYER_H
