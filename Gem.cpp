#include "Gem.h"
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
Gem::Gem()
{

}
void Gem::setPoint(int level)
{
    point=level*100;
}
int Gem::getpoint()
{
    return point;
}

void Gem::setRowWise(vll &game,int row,int y1,int y2)
{
    int posxx,posyy,dif;
    posxx=row;
    dif=y2-y1+1;
    posyy=rand()%dif+y1;
    game[posxx][posyy]='$';
}

void Gem::setColumnWise(vll &game,int col,int x1,int x2)
{
    int posxx,posyy,dif;
    posyy=col;
    dif=x2-x1+1;
    posxx=rand()%dif+x1;
    game[posxx][posyy]='$';
}

