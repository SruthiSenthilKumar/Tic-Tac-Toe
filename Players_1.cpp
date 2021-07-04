#include<iostream>
#include "Players_1.h"
#include<bits/stdc++.h>

using namespace std;
int i,j,k,size;

Players_1::Players_1()
{
    //ctor
}

void initialise( int moves[],int size)
{
    //srand(time(NULL));

    for (i=0; i<size*size; i++)
        moves[i] = i;

    random_shuffle(moves, moves + size*size);

    return;
}



int Players_1::play()
{
    char a[100][100],gameover=1;
	int x,y,player=0,xpts=0,opts=0,playagain,moveIndex=0;
try_block:
	cout<<"\nEnter the number of rows or columns : ";
	cin>>size;
	/*try
	{
	    if(size<=1)
            throw size;
	}
	catch(int size)
	{
	    cout<<"not valid...";
	    goto try_block;
	}*/
	int moves[size*size];
	initialise(moves,size);
	for(k=0;k<5*size-2;k++)
		cout<<"-";
	cout<<"\n";
	for(i=0;i<size;++i)
	{
		cout<<"|";
		for(j=0;j<size;++j)
		{
			a[i][j]=32;
			cout<<a[i][j]<<" | ";
		}
		cout<<"\n";
		for(k=0;k<5*size-2;k++)
			cout<<"-";
		cout<<"\n";
	}
	cout << "\nYou will fill with X and Computer will play with O \n";
    do
        {
            if(player==0)
            {
                cout<<"\nPlayer X : ";
                cin>>x>>y;
            }
            --x;
            --y;
        if(player==0)
        {
            if(a[x][y]!='X'&&a[x][y]!='O'&&x<size&&y<size)
            {
                a[x][y]=player?'O':'X';
                player=!player;
                print(a,size);
                switch(check(a,size))
                {
                    case 0 : cout<<"\n\nDraw !";
                    gameover=0;
                    break;
                    case 1 : cout<<"\n\nPlayer X wins !";
                        gameover=0;
                        ++xpts;
                        break;
                    case 2 : cout<<"\n\nPlayer O wins !";
                        gameover=0;
                        ++opts;
                        break;
                }
                 if(gameover==0)
                break;

            }
            else
            {
                cout<<"The box is either filled or not in range !\nPlease try another position !";
            }
    }
cout<<"COMPUTER'S TURN\n";
     if(player==1)
    {
            x = moves[moveIndex] / size;
            y = moves[moveIndex] % size;
empty:  if(a[x][y]!='X'&&a[x][y]!='O'&&x<size&&y<size)
        {
            a[x][y] = 'O';
            cout<<"COMPUTER has put a O in cell "<<moves[moveIndex]+1<<'\n';
        }
        else
        {
            moveIndex=(moveIndex+1)%(size*size);
            x=moves[moveIndex]/size;
            y=moves[moveIndex]%size;
            goto empty;
        }
            print(a,size);
            switch(check(a,size))
                {
                    case 0 : cout<<"\n\nDraw !";
                    gameover=0;
                    break;
                    case 1 : cout<<"\n\nPlayer X wins !";
                        gameover=0;
                        ++xpts;
                        break;
                    case 2 : cout<<"\n\nPlayer O wins !";
                        gameover=0;
                        ++opts;
                        break;
                }
                 if(gameover==0)
                break;

            moveIndex=(moveIndex+1)%(size*size);
            player=!player;
    }
    /*try
    {
        if(player!=1&&player!=0)
            throw player;
    }
    catch(int player)
    {
        cout<<"invalid player";
    }*/
	}while(gameover);
	cout<<"\n\n\n****Score*****\nX - "<<xpts<<"\tO - "<<opts<<"\n\n\n";
	cout<<"Wanna play again?\n1 - Yes\t0 - No\n";
	cin>>playagain;
	return playagain;
}
