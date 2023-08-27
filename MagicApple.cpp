#include "MagicApple.h"
#include "Gameplay.h"
#include "Board.h"
#include "Dungeon.h"
#include "Gem.h"
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
MagicApple::MagicApple()
{

}
void MagicApple::setPoint(int p)
{
    point=p;
}
void MagicApple::setEnergy(int e)
{
    energy=e;
}

void MagicApple::setPos(int x,int y)
{
    posx=x;
    posy=y;
}
int MagicApple::getEnergy()
{
    return energy;
}
int MagicApple::getpoint()
{
    return point;
}
int MagicApple::getPosx()
{
    return posx;
}
int MagicApple::getPosy()
{
    return posy;
}

void MagicApple::setRowWise(vll &game,int row,int y1,int y2)
{
    int posxx,posyy,dif;
    posxx=row;
    dif=y2-y1+1;
    posyy=y1+dif/2;
    game[posxx][posyy]='a';
}

void MagicApple::setColumnWise(vll &game,int col,int x1,int x2)
{
    int posxx,posyy,dif;
    posyy=col;
    dif=x2-x1+1;
    posxx=x1+dif/2;
    game[posxx][posyy]='a';
}

