#ifndef MONSTER_H
#define MONSTER_H
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

class Monster
{
public:
    Monster();
    void setRowWise(vll &,int ,int,int );
    void setColumnWise(vll &,int ,int ,int);

};

#endif // MONSTER_H
