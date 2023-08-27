#include "Rock.h"
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
Rock::Rock()
{

}

void  Rock::setPowerloss(int level)
{
    powerloss=level*7;
}

int Rock::getPowerloss()
{
    return powerloss;
}

void Rock::Topdown(vll &game,int x1,int x2,int y)
{
    for(int i=x1; i<=x2; i++)
    {
        game[i][y]='X';
    }
}

void Rock::BottomUp(vll &game,int x1,int x2,int y)
{
    for(int i=x1; i>=x2; i--)
    {
        game[i][y]='X';
    }
}

void Rock::LeftRight(vll &game,int y1,int y2,int x)
{
    for(int i=y1; i<=y2; i++)
    {
        game[x][i]='X';
    }
}

void Rock::RightLeft(vll &game,int y1,int y2,int x)
{
    for(int i=y1; i>=y2; i--)
    {
        game[x][i]='X';
    }
}

