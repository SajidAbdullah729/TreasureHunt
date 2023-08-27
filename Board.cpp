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
Board::Board()
{

}

void Board::setPos(int x)
{
    pos=x;
}
void Board::setElement(int e)
{
    element=e;
}
int Board::getPos()
{
    return pos;
}
int Board::getElement()
{
    return element;
}



void Board::displayBoard(vll &game,int n,int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<game[i][j];
        }
        cout<<endl;
    }
}

void Board::createBoard(vll &game,int n,int m,int level,int state)
{
    if(level==1 && state==1)
    {
        SideWall s;
        s.Wall(game,n,m);

        Rock rck;

        rck.LeftRight(game,1,3,5);

        rck.LeftRight(game,1,2,6);

        MagicApple ms;
        ms.setRowWise(game,2,2,m-1);
        ms.setRowWise(game,9,4,m-1);

        Monster mm;
        mm.setRowWise(game,10,1,m-1);
        Gem g;
        g.setRowWise(game,8,1,m-1);
    }

    else if(level==1 && state==2)
    {

        SideWall s;
        s.Wall(game,n,m);

        Rock rck;

        rck.LeftRight(game,1,3,6);

        rck.LeftRight(game,1,2,1);

        rck.RightLeft(game,m,5,5);

        MagicApple ms;
        ms.setRowWise(game,3,2,m-1);
        ms.setRowWise(game,10,4,m-1);

        Monster mm;
        mm.setRowWise(game,11,1,m-1);

        Dungeon g;
        g.setRowWise(game,9,1,m-1);
    }

    else if(level==2 && state==1)
    {
        SideWall s;
        s.Wall(game,n,m);

        Rock rck;

        rck.LeftRight(game,1,6,4);

        rck.RightLeft(game,m-1,m-6,6);

        MagicApple ms;

        ms.setRowWise(game,5,1,m-2);
        ms.setRowWise(game,11,1,m-2);

        Monster mm;
        mm.setRowWise(game,7,1,m-2);

        Gem g;
        g.setRowWise(game,8,1,m-2);
    }

    else if(level==2 && state==2)
    {
        SideWall s;
        s.Wall(game,n,m);

        Rock rck;
        rck.LeftRight(game,1,3,2);

        rck.LeftRight(game,1,6,9);

        rck.RightLeft(game,m-1,m-7,7);

        MagicApple ms;
        ms.setRowWise(game,5,1,m-2);
        ms.setRowWise(game,11,1,m-2);

        Monster mm;
        mm.setRowWise(game,7,1,m-2);

        Dungeon gg;
        gg.setRowWise(game,8,1,m-2);
    }

    else if(level==3 && state==1 )
    {

        SideWall s;
        s.Wall(game,n,m);

        Rock rck;
        rck.Topdown(game,0,3,3);

        rck.Topdown(game,0,6,5);

        rck.RightLeft(game,m-1,m-9,7);

        rck.RightLeft(game,m-1,m-8,13);

        MagicApple ms;
        ms.setRowWise(game,5,1,m-2);
        ms.setRowWise(game,11,2,m-2);

        Monster mm;
        mm.setRowWise(game,6,8,m-2);
        Gem gg;
        gg.setRowWise(game,8,9,m-2);
    }

    else if(level==3 && state==2)
    {
        //clearDisplay(n,m);
        SideWall s;
        s.Wall(game,n,m);

        Rock rck;

        rck.Topdown(game,1,5,4);

        rck.RightLeft(game,m-1,m-8,9);

        rck.RightLeft(game,m-1,m-7,13);

        MagicApple ms;
        ms.setRowWise(game,5,1,m-2);
        ms.setRowWise(game,11,2,m-2);

        Monster mm;
        mm.setRowWise(game,6,8,m-2);
        Dungeon gg;
        gg.setRowWise(game,8,9,m-2);
    }

    else if(level==4 && state==1)
    {

        SideWall s;
        s.Wall(game,n,m);

        Rock rck;

        rck.Topdown(game,0,2,5);

        rck.Topdown(game,0,6,9);

        rck.RightLeft(game,m-1,m-6,15);

        rck.RightLeft(game,m-1,m-7,18);

        MagicApple ms;
        ms.setRowWise(game,5,1,m-2);
        ms.setRowWise(game,11,2,m-2);

        Monster mm;
        mm.setRowWise(game,6,8,m-2);
        Gem gg;
        gg.setRowWise(game,8,9,m-2);
    }

    else if(level==4 && state==2)
    {
        //clearDisplay(n,m);

        SideWall s;
        s.Wall(game,n,m);

        for(int i=0; i<3; i++)
        {
            game[i][5]='X';
        }
        for(int i=0; i<6; i++)
        {
            game[9][i]='X';
        }
        for(int i=m-1; i>=m-8; i--)
        {
            game[i][10]='X';
        }
        for(int i=m-1; i>=m-7; i--)
        {
            game[i][18]='X';
        }

        MagicApple ms;
        ms.setRowWise(game,5,6,m-2);
        ms.setRowWise(game,11,6,m-2);

        Monster mm;
        mm.setRowWise(game,6,10,m-2);
        Dungeon gg;
        gg.setRowWise(game,8,11,m-2);

    }

    else if(level==5 && state==1)
    {

        //clearDisplay(n,m);

        SideWall s;
        s.Wall(game,n,m);

        Rock rck;
        rck.LeftRight(game,0,5,5);

        rck.Topdown(game,0,5,5);

        rck.RightLeft(game,m-1,m-6,14);

        rck.BottomUp(game,n-1,n-6,14);

        MagicApple ms;
        ms.setRowWise(game,5,1,m-5);
        ms.setRowWise(game,11,1,m-5);

        Monster mm;
        mm.setRowWise(game,6,2,m-5);
        Dungeon gg;
        gg.setRowWise(game,8,2,m-3);

    }

    else if(level==5 && state==2)
    {
        SideWall s;
        s.Wall(game,n,m);

        Rock rck;
        rck.LeftRight(game,0,3,4);

        rck.Topdown(game,0,5,6);

        rck.RightLeft(game,m-1,m-4,14);

        rck.BottomUp(game,n-1,n-4,14);

        MagicApple ms;
        ms.setRowWise(game,5,2,m-2);
        ms.setRowWise(game,11,4,m-2);

        Monster mm;
        mm.setRowWise(game,6,1,m-4);

        Dungeon gg;
        gg.setRowWise(game,8,11,m-2);

    }

}





