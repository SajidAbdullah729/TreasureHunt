#pragma warning(disable :4996)
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
#include<sstream>
#include<fstream>
#include<conio.h>
#include<cmath>
#include<stdlib.h>
#include<vector>
#include<string>
#include<ctime>
#include<algorithm>
using namespace std;
typedef vector<vector<char> > vll;



vector<vector<char > >  game(101, vector<char>(101, '.'));


int kkx,kky;

struct Times
{
    char* dt;
    int kor;
    string korbo;
};

struct Scores
{
    string name;
    int score;
};

bool cmp(Scores a,Scores b)
{
    if(a.score!=b.score) return (a.score>b.score);
    return a.name>b.name;
}


void Message(int n)
{
    if(n==1)
    {
        cout<<"Alert!! There is a Rock"<<endl;
    }
    else if(n==2)
    {

    }
    else if(n==3)
    {
        cout<<"Fighting Monster"<<endl;
    }
    else if(n==4)
    {
        cout<<"Collecting Gem"<<endl;
    }
    else if(n==5)
    {
        cout<<"Explore new Cave"<<endl;
    }
    else if(n==6)
    {
        cout<<"Getting Energy!!Eating Magic Apple"<<endl;
    }
}


void StartPos(int level,int state)
{
    if(level==1 )
    {
        if(state==1)
        {
            kkx=8;
            kky=2;
        }
        else if(state==2)
        {
            kkx=8;
            kky=4;
        }
    }
    else if(level==2)
    {
        if(state==1)
        {
            kkx=3;
            kky=8;
        }
        else if(state==2)
        {
            kkx=3;
            kky=3;
        }
    }
    else if(level==3)
    {
        if(state==1)
        {
            kkx=7;
            kky=2;
        }
        else if(state==2)
        {
            kkx=7;
            kky=2;
        }
    }
    else if(level==4)
    {
        if(state==1)
        {
            kkx=2;
            kky=3;
        }
        else if(state==2)
        {
            kkx=15;
            kky=3;
        }
    }
    else if(level==5)
    {
        if(state==1)
        {
            kkx=2;
            kky=2;
        }
        else if(state==2)
        {
            kkx=4;
            kky=3;
        }
    }
}

int toNumber(string s) {stringstream aa(s);int mm;aa>>mm; return mm;}

string toString(int n) { ostringstream ost; ost << n; ost.flush(); return ost.str();}

int cx, cy;

void Gridsize(int level)
{
    if(level==1 )
    {
        cx=13;
        cy=13;
    }
    else if(level==2)
    {
        cx=14;
        cy=13;
    }
    else if(level==3)
    {
        cx=16;
        cx=14;
    }
    else if(level==4)
    {
        cx=20;
        cy=20;
    }
    else if(level==5)
    {
        cx=22;
        cy=22;
    }
}

vector<Scores> finalscore;
void AddScore(string n,int sc)
{
   // Scores tt;
   // tt.name=n;
   // tt.score=sc;
   // finalscore.push_back(tt);
   ofstream file_;
   file_.open("myscore.txt",std::ios_base::app);
   if(file_.is_open())
   {
       file_<<n;
       file_<<" ";
       file_<<toString(sc)<<endl;
       Scores sk;
       sk.name=n;
       sk.score=sc;
       finalscore.push_back(sk);
   }
   file_.close();
}

void Insert()
{
    ifstream infile;
    infile.open("myscore.txt");
    if(infile.fail()==false)
    {
        string nam;
        string sc;
        while(infile>>nam>>sc)
        {
            int r=toNumber(sc);
            Scores sss;
            sss.name=nam;
            sss.score=r;
            finalscore.push_back(sss);
        }
    }
}

void clearDisplay(int n,int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            game[i][j]='.';
        }
    }
}

vector<Times> v;
int p=0;
int cpp=0;
int bug=0;
void Time(int k,char* dt)
{

    Times t;
    cout<<endl;

    cout<<endl;
    t.dt=dt;
    t.kor=k;
    t.korbo=dt;
    if(k!=2)
    {
        v.push_back(t);
        p++;
    }

}




bool valid(int x,int y,int level)
{
    int n,m;
    Gridsize(level);
    n=cx;
    m=cy;
    if(x>=1 && x<=n-2 && y>=1 && y<=m-2)
    {
        return true;
    }
    else return false;
}

void Timer()
{

}


Gameplay::Gameplay()
{
    //ctor
}

void Gameplay::Play()
{
        if(cpp==0) {Insert();cpp=1;}
        clearDisplay(25,25);
        int level=1,state=1;
        int energy=100;
        int points=0;
        int win=0;
        int gems=0;
        int moves=0;
        Player p;
        StartPos(level,state);

        p.setPosx(kkx);
        p.setPosy(kky);

        cout<<endl;
        cout<<"Welcome to the treasure Hunt!"<<endl;
        cout<<"Entered into the magical dungeon"<<endl;
        cout<<"Name :";

        string q;cin>>q;
        p.setName(q);
        Board b;
        b.createBoard(game,13,13,1,1);
        int tempx=p.getPosx();
        int tempy=p.getPosy();
        game[tempx][tempy]='@';
        b.displayBoard(game,13,13);

        while(1)
        {

            cout<<"Please select action(move with wasd or Q to escape and select valid move) >";
            char c;
            cin>>c;
            time_t now=time(0);
            char *dt=ctime(&now);
            cout<<endl;
            cout<<endl;
            if(c=='Q')
            {
                break;
            }
            int f=0;
            int newposx,newposy;
            if(c=='w')
            {

                newposx=tempx-1;
                newposy=tempy;
                if(valid(newposx,newposy,level) )
                {
                    moves++;
                    if(game[newposx][newposy]=='X')
                    {
                        Rock rc;
                        rc.setPowerloss(level);
                        energy-=rc.getPowerloss();
                        if(energy<=0)
                        {
                            energy=0;
                            break;
                        }

                        Time(1,dt);
                        f=1;
                        if(f==1)
                        {

                            game[tempx][tempy]='.';
                            tempx =newposx;
                            tempy=newposy;
                            game[newposx][newposy]='@';
                        }
                        else
                        {
                            tempx=tempx;
                            tempy=tempy;
                            game[tempx][tempy]='@';
                        }




                    }
                    else
                    {
                        if(game[newposx][newposy]=='.')
                        {
                            energy-=2;
                            f=1;
                            if(energy<=0)
                            {
                                Time(2,dt);
                                energy=0;
                                break;
                            }
                            Time(2,dt);

                        }
                        else if(game[newposx][newposy]=='m')
                        {
                            if(energy<50)
                            {
                                energy=0;

                                Time(3,dt);

                                break;
                            }
                            else
                            {
                                energy=energy;
                                points+=50*level;
                                Time(3,dt);
                                f=1;
                            }

                        }
                        else if(game[newposx][newposy]=='$')
                        {

                            gems++;
                            state=2;
                            Gridsize(level);
                            b.createBoard(game,cx,cy,level,state);
                            StartPos(level,state);
                            tempx=kkx;
                            tempy=kky;
                            Gem gg;
                            gg.setPoint(level);
                            points+=gg.getpoint();
                            Time(4,dt);
                            f=0;
                        }
                        else if(game[newposx][newposy]=='E')
                        {

                            points+=level*150;
                            level++;

                            if(level>5)
                            {
                                win=1;
                                break;
                            }

                            state=1;

                            Gridsize(level);
                            b.createBoard(game,cx,cy,level,state);

                            StartPos(level,state);
                            tempx=kkx;
                            tempy=kky;
                            f=0;
                            Time(5,dt);
                        }
                        else if(game[newposx][newposy]='a')
                        {
                            Time(6,dt);
                            energy=100;
                            points+=level*22;
                            f=1;
                        }
                        if(f==1)
                        {

                            game[tempx][tempy]='.';
                            tempx =newposx;
                            tempy=newposy;
                            game[newposx][newposy]='@';
                        }
                        else
                        {
                            tempx=tempx;
                            tempy=tempy;
                            game[tempx][tempy]='@';
                        }


                    }


                }
                else continue;

            }


            else if(c=='s')
            {
                newposx=tempx+1;
                newposy=tempy;
                if(valid(newposx,newposy,level) )
                {
                    moves++;
                    if(game[newposx][newposy]=='X')
                    {
                        Rock rc;
                        rc.setPowerloss(level);

                        energy-=rc.getPowerloss();
                        if(energy<=0)
                        {
                            energy=0;
                            Time(1,dt);
                            break;
                        }
                        Time(1,dt);
                        f=1;

                        if(f==1)
                        {

                            game[tempx][tempy]='.';
                            tempx =newposx;
                            tempy=newposy;
                            game[newposx][newposy]='@';
                        }
                        else
                        {
                            tempx=tempx;
                            tempy=tempy;
                            game[tempx][tempy]='@';
                        }

                    }
                    else
                    {
                        if(game[newposx][newposy]=='.')
                        {
                            energy-=2;
                            f=1;
                            if(energy<=0)
                            {
                                energy=0;
                                Time(2,dt);
                                break;
                            }
                            Time(2,dt);

                        }
                        else if(game[newposx][newposy]=='m')
                        {
                            if(energy<50)
                            {
                                energy=0;

                                Time(3,dt);

                                break;
                            }
                            else
                            {
                                energy=energy;
                                points+=50*level;
                                Time(3,dt);
                                f=1;
                            }

                        }
                        else if(game[newposx][newposy]=='$')
                        {
                            gems++;
                            Time(4,dt);
                            state=2;
                            Gridsize(level);
                            b.createBoard(game,cx,cy,level,state);
                            StartPos(level,state);
                            tempx=kkx;
                            tempy=kky;
                            Gem gg;
                            gg.setPoint(level);
                            points+=gg.getpoint();
                            f=0;
                        }
                        else if(game[newposx][newposy]=='E')
                        {

                            points+=level*150;
                            level++;

                            if(level>5)
                            {
                                win=1;
                                break;
                            }

                            state=1;

                            Gridsize(level);
                            b.createBoard(game,cx,cy,level,state);

                            StartPos(level,state);
                            tempx=kkx;
                            tempy=kky;
                            f=0;
                            Time(5,dt);
                        }
                        else if(game[newposx][newposy]='a')
                        {
                            energy=100;
                            points+=level*22;
                            f=1;
                            Time(6,dt);
                        }
                        if(f==1)
                        {

                            game[tempx][tempy]='.';
                            tempx =newposx;
                            tempy=newposy;
                            game[newposx][newposy]='@';
                        }
                        else
                        {
                            tempx=tempx;
                            tempy=tempy;
                            game[tempx][tempy]='@';
                        }


                    }


                }
                else continue;

            }

            else if(c=='d')
            {
                newposx=tempx;
                newposy=tempy+1;
                if(valid(newposx,newposy,level) )
                {
                    moves++;
                    if(game[newposx][newposy]=='X')
                    {
                        Rock rc;
                        rc.setPowerloss(level);
                        energy-=rc.getPowerloss();
                        if(energy<=0)
                        {
                            energy=0;
                            Time(1,dt);
                            break;
                        }
                        Time(1,dt);
                        f=1;

                        if(f==1)
                        {

                            game[tempx][tempy]='.';
                            tempx =newposx;
                            tempy=newposy;
                            game[newposx][newposy]='@';
                        }
                        else
                        {
                            tempx=tempx;
                            tempy=tempy;
                            game[tempx][tempy]='@';
                        }
                    }
                    else
                    {
                        if(game[newposx][newposy]=='.')
                        {
                            energy-=2;
                            f=1;
                            if(energy<=0)
                            {
                                energy=0;
                                Time(2,dt);
                                break;
                            }
                            Time(2,dt);

                        }
                        else if(game[newposx][newposy]=='m')
                        {
                            if(energy<50)
                            {
                                energy=0;

                                Time(3,dt);

                                break;
                            }
                            else
                            {
                                energy=energy;
                                points+=50*level;
                                f=1;
                                Time(3,dt);
                            }

                        }
                        else if(game[newposx][newposy]=='$')
                        {
                            Time(4,dt);
                            gems++;
                            state=2;
                            Gridsize(level);
                            b.createBoard(game,cx,cy,level,state);
                            StartPos(level,state);
                            tempx=kkx;
                            tempy=kky;
                            Gem gg;
                            gg.setPoint(level);
                            points+=gg.getpoint();
                            f=0;
                        }
                        else if(game[newposx][newposy]=='E')
                        {

                            points+=level*150;
                            level++;

                            if(level>5)
                            {
                                win=1;
                                break;
                            }
                            Time(5,dt);
                            state=1;


                            Gridsize(level);
                            b.createBoard(game,cx,cy,level,state);

                            StartPos(level,state);
                            tempx=kkx;
                            tempy=kky;
                            f=1;
                        }
                        else if(game[newposx][newposy]='a')
                        {
                            Time(6,dt);
                            energy=100;
                            points+=level*22;
                            f=1;
                        }
                        if(f==1)
                        {

                            game[tempx][tempy]='.';
                            tempx =newposx;
                            tempy=newposy;
                            game[newposx][newposy]='@';
                        }
                        else
                        {
                            tempx=tempx;
                            tempy=tempy;
                            game[tempx][tempy]='@';
                        }
                    }


                }

            }

            else if(c=='a')
            {
                newposx=tempx;
                newposy=tempy-1;
                if(valid(newposx,newposy,level) )
                {
                    moves++;
                    if(game[newposx][newposy]=='X')
                    {
                        Rock rc;
                        rc.setPowerloss(level);
                        energy-=rc.getPowerloss();
                        if(energy<=0)
                        {
                            energy=0;
                            Time(1,dt);
                            break;
                        }
                        Time(1,dt);
                        f=1;

                        if(f==1)
                        {

                            game[tempx][tempy]='.';
                            tempx =newposx;
                            tempy=newposy;
                            game[newposx][newposy]='@';
                        }
                        else
                        {
                            tempx=tempx;
                            tempy=tempy;
                            game[tempx][tempy]='@';
                        }
                    }
                    else
                    {
                        if(game[newposx][newposy]=='.')
                        {
                            energy-=2;
                            f=1;
                            if(energy<=0)
                            {
                                energy=0;
                                Time(2,dt);
                                break;
                            }
                            Time(2,dt);

                        }
                        else if(game[newposx][newposy]=='m')
                        {
                            f=1;
                            if(energy<50)
                            {
                                energy=0;

                                Time(3,dt);

                                break;
                            }
                            else
                            {
                                energy=energy;
                                points+=50*level;
                                f=1;
                                Time(3,dt);
                            }

                        }
                        else if(game[newposx][newposy]=='$')
                        {
                            f=1;
                            gems++;
                            Time(4,dt);
                            state=2;
                            Gridsize(level);
                            b.createBoard(game,cx,cy,level,state);
                            StartPos(level,state);
                            tempx=kkx;
                            tempy=kky;
                            Gem gg;
                            gg.setPoint(level);
                            points+=gg.getpoint();
                            f=0;
                        }
                        else if(game[newposx][newposy]=='E')
                        {
                            f=1;
                            points+=level*150;
                            level++;

                            if(level>5)
                            {
                                win=1;
                                break;
                            }
                            Time(5,dt);
                            state=1;

                            Gridsize(level);
                            b.createBoard(game,cx,cy,level,state);

                            StartPos(level,state);
                            tempx=kkx;
                            tempy=kky;
                            f=0;
                        }
                        else if(game[newposx][newposy]='a')
                        {
                            Time(6,dt);
                            energy=100;
                            points+=level*22;
                            f=1;
                        }
                        if(f==1)
                        {

                            game[tempx][tempy]='.';
                            tempx =newposx;
                            tempy=newposy;
                            game[newposx][newposy]='@';
                        }
                        else
                        {
                            tempx=tempx;
                            tempy=tempy;
                            game[tempx][tempy]='@';
                        }


                    }


                }







            }
            else
            {
                 cout<<endl;
                 cout<<"Invalid Choice "<<endl;
                 cout<<endl;
                 continue;
            }



            if(level==1 && state==1)
            {

                cout<<"Level : "<<level<<"; "<<"Player energy: "<<energy<<"%.   ";
                cout<<"Points: "<<points<<"."<<endl;
                b.displayBoard(game,13,13);
            }
            else if(level==1 && state==2)
            {

                cout<<"Level : "<<level<<"; "<<"Player energy: "<<energy<<"%.   ";
                cout<<"Points: "<<points<<"."<<endl;
                b.displayBoard(game,13,13);
            }
            else if(level==2 && state==1)
            {

                cout<<"Level : "<<level<<"; "<<"Player energy: "<<energy<<"%.   ";
                cout<<"Points: "<<points<<"."<<endl;
                b.displayBoard(game,14,13);
            }
            else if(level==2 && state==2)
            {

                cout<<"Level : "<<level<<"; "<<"Player energy: "<<energy<<"%.   ";
                cout<<"Points: "<<points<<"."<<endl;
                b.displayBoard(game,14,13);
            }
            else if(level==3 && state==1)
            {
                cout<<"Level : "<<level<<"; "<<"Player energy: "<<energy<<"%.   ";
                cout<<"Points: "<<points<<"."<<endl;
                b.displayBoard(game,16,14);
            }
            else if(level==3 && state==2)
            {

                cout<<"Level : "<<level<<"; "<<"Player energy: "<<energy<<"%.   ";
                cout<<"Points: "<<points<<"."<<endl;
                b.displayBoard(game,16,14);
            }
            else if(level==4 && state==1)
            {
                cout<<"Level : "<<level<<"; "<<"Player energy: "<<energy<<"%.   ";
                cout<<"Points: "<<points<<"."<<endl;
                b.displayBoard(game,20,20);
            }
            else if(level==4 && state==2)
            {

                cout<<"Level : "<<level<<"; "<<"Player energy: "<<energy<<"%.   ";
                cout<<"Points: "<<points<<"."<<endl;
                b.displayBoard(game,20,20);
            }
            else if(level==5 && state==1)
            {

                cout<<"Level : "<<level<<"; "<<"Player energy: "<<energy<<"%.   ";
                cout<<"Points: "<<points<<"."<<endl;
                b.displayBoard(game,22,22);
            }
            else if(level==5 && state==2)
            {

                cout<<"Level : "<<level<<"; "<<"Player energy: "<<energy<<"%.   ";
                cout<<"Points: "<<points<<"."<<endl;
                b.displayBoard(game,22,22);
            }
        }

        if(win==0)
        {
            AddScore(p.getName(),points);
            cout<<endl;
            cout<<endl;
            cout<<"Couldn't Successfully Escape!!";
            cout<<endl;
            cout<<"You have gained "<<gems<<" gems and total valid moves were ";
            cout<<moves<<"."<<endl;
            cout<<endl;
            cout<<"Yoh have gained total "<<points<<" points"<<endl;
            //cout<<"You feel relaxed,breath the fresh air and hold tightly to your treasure!!"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"Brief Adventure History:"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            for(int i=0; i<v.size(); i++)
            {
                cout<<v[i].korbo;
                Message(v[i].kor);

            }
            cout<<endl;
            cout<<endl;
            cout<<endl;
        }
        else
        {
            AddScore(p.getName(),points);
            cout<<"Congratulations! You have successfully Escpaed from the "<<level-1<<"th level"<<endl;
            cout<<"You have gained "<<gems<<" gems and total valid moves were ";
            cout<<moves<<"."<<endl;
            cout<<"You have gained total "<<points<<" points"<<endl;
            cout<<"You feel relaxed,breath the fresh air and hold tightly to your treasure!!"<<endl;
            cout<<"Brief Adventure History:"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            for(int i=0; i<v.size(); i++)
            {
                cout<<v[i].korbo;
                Message(v[i].kor);

            }
            cout<<endl;
            cout<<endl;
        }

}

void Gameplay::HighScore()
{
    if(cpp==0) Insert();

    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"   HIGH SCORE: "<<endl;
    cout<<endl;

    sort(finalscore.begin(),finalscore.end(),cmp);
    int kkp=finalscore.size();
    for(int i=0;i<min(kkp,5);i++)
    {
        cout<<"   ";
        cout<<finalscore[i].name<<" "<<finalscore[i].score<<endl;

    }
    cout<<endl;
    cpp=1;
}
void Gameplay::Quit()
{
    for(int i=0;i<3;i++) cout<<endl;
    cout<<"Thank You "<<endl;

}


