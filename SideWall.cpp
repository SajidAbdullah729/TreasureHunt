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




SideWall::SideWall()
{

}

void SideWall::Wall(vll &game,int n,int m)
{

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i==0 || i==n-1) game[i][j]='X';
                else if(j==0 || j==m-1) game[i][j]='X';
                else
                {
                    game[i][j]='.';
                }
            }
        }
}

