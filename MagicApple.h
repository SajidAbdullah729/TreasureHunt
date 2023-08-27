#ifndef MAGICAPPLE_H
#define MAGICAPPLE_H
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

class MagicApple
{
private:
    int point,energy,posx,posy;
public:
    MagicApple();
    void setPoint(int);

    void setEnergy(int);


    void setPos(int,int );

    int getEnergy();

    int getpoint();

    int getPosx();

    int getPosy();


    void setRowWise(vll &,int row,int y1,int y2);


    void setColumnWise(vll &,int col,int x1,int x2);

};

#endif // MAGICAPPLE_H
