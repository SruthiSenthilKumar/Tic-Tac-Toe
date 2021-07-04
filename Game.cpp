
#include<iostream>
#include "Game.h"

using namespace std;

Game::Game()
{
    //ctor
}

void Game::print(char a[100][100],int size)
{
	cout<<"\n\n\n";
	for(k=0;k<5*size-2;k++)
		cout<<"-";
	cout<<"\n";
	for(i=0;i<size;++i)
	{
		cout<<"|";
		for(j=0;j<size;++j)
		{
			cout<<a[i][j]<<" | ";
		}
		cout<<"\n";
		for(k=0;k<5*size-2;k++)
			cout<<"-";
		cout<<"\n";
	}
}

int Game::check(char a[100][100],int size)
{
	int x,o,empty=size*size;
	for(i=0;i<size;++i)
	{
		x=o=0;
		for(j=0;j<size-1;++j)
		{
			if(a[i][j]==a[i][j+1]&&a[i][j]!=' ')
			{
				a[i][j]=='X'?++x:++o;
			}
			else
			{
				break;
			}
		}

		if(x==size-1)
		{
			return 1;
		}
		else if(o==size-1)
		{
			return 2;
		}
	}

	for(j=0;j<size;++j)
	{
		x=o=0;
		for(i=0;i<size-1;++i)
		{
			if(a[i][j]==a[i+1][j]&&a[i][j]!=' ')
			{
				a[i][j]=='X'?++x:++o;
			}
			else
			{
				break;
			}
		}

		if(x==size-1)
		{
			return 1;
		}
		else if(o==size-1)
		{
			return 2;
		}
	}
	x=o=0;
	for(i=0;i<size-1;++i)
	{
		if(a[i][i]==a[i+1][i+1]&&a[i][i]!=' ')
		{
			a[i][i]=='X'?++x:++o;
		}
		else
		{
			break;
		}
	}
	if(x==size-1)
	{
		return 1;
	}
	if(o==size-1)
	{
		return 2;
	}
	x=o=0;
	for(i=size-1;i;--i)
	{
		if(a[i][size-1-i]==a[i-1][size-i]&&a[i][size-1-i]!=' ')
		{
			a[i-1][size-i]=='X'?++x:++o;
		}
		else
		{
			break;
		}
	}

	if(x==size-1)
	{
		return 1;
	} else if(x==size-1)
	{
		return 2;
	}

	for(j=0;j<size;++j)
		for(i=0;i<size;++i)
			if(a[i][j]!=' ')
				--empty;
	if(!empty)
	{
		cout<<"\n"<<empty<<"\n";
		return 0;
	}
	return 3;
}
