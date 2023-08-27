
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<cmath>
#include<stdlib.h>
#include<vector>
#include<string>
#include<ctime>
#include<algorithm>
#include "Board.h"
#include "Dungeon.h"
#include "Gameplay.h"
#include "Gem.h"
#include "MagicApple.h"
#include "Monster.h"
#include "Player.h"
#include "Rock.h"
#include "SideWall.h"
typedef vector<vector<char> > vll;


using namespace std;





void openScreen()
{

    cout<<"Press between 1-3 to choose option"<<endl;
    cout<<endl;
    cout<<"1.Play"<<endl;
    cout<<"2.HighScore"<<endl;
    cout<<"3.Exit"<<endl;

}


int main()
{

    cout<<"Treasure Hunt"<<endl;
    cout<<endl;
    while(1)
    {
        openScreen();
        cout<<"Choose Option: ";
        string s;
        cin>>s;
        if(s=="1")
        {
            Gameplay gp;
            gp.Play();
        }
        else if(s=="2")
        {
            Gameplay gp;
            gp.HighScore();
        }
        else if(s=="3")
        {
            Gameplay gp;
            gp.Quit();
            return 0;
        }
        else
        {
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"Invalid Choice"<<endl;
            cout<<"Try Again"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
        }
    }





    return 0;
}
