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
Player::Player()
{
    //ctor
}
void Player::setPosx(int x)
{
    posx=x;
}

void Player::setPosy(int y)
{
    posy=y;
}

void Player::setTurn(int n)
{
    turn=n;
}

void Player::setEnergy(int n)
{
    energy=n;
}

void Player::setPoint(int p)
{
    point=p;
}

void Player::setName(string s)
{
    name=s;
}

int Player::getPosx()
{
    return posx;
}

int Player::getPosy()
{
    return posy;
}

int Player::getTurn()
{
    return turn;
}

int Player::getPoint()
{
    return point;
}

string Player::getName()
{
    return name;
}

int Player::getEnergy()
{
    return energy;
}


