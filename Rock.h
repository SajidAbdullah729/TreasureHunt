#ifndef ROCK_H
#define ROCK_H
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

class Rock
{
private:
    int powerloss;
public:
    Rock();
    void setPowerloss(int level);

    int getPowerloss();

    void Topdown(vll &,int,int,int );

    void BottomUp(vll &,int,int,int);

    void LeftRight(vll &,int,int,int);

    void RightLeft(vll&,int,int,int);


};




#endif // ROCK_H
