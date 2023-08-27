#ifndef BOARD_H
#define BOARD_H
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

class Board
{
   private:
    int pos,element;
public:
    Board();
    void setPos(int);

    void setElement(int);

    int getPos();

    int getElement();

    void displayBoard(vll &,int,int );

    void createBoard(vll &,int ,int,int ,int );



};

#endif // BOARD_H
