#include<iostream>
#include "Game.h"
#include "Players_2.h"
using namespace std;

Players_2::Players_2()
{
    //ctor
}

int Players_2::play()
{
    char a[100][100],gameover=1;
	int x,y,player=0,xpts=0,opts=0,playagain;
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
    do
        {
            player?cout<<"\nPlayer O : ":cout<<"\nPlayer X : ";
            cin>>x>>y;
            --x;
            --y;
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
            }
            else
        {
            cout<<"The box is either filled or not in range !\nPlease try another position !";
        }
	}while(gameover);
	cout<<"\n\n\n****Score*****\nX - "<<xpts<<"\tO - "<<opts<<"\n\n\n";
	cout<<"Wanna play again?\n1 - Yes\t0 - No\n";
	cin>>playagain;
	return playagain;
}
