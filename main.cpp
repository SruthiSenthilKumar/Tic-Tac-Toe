#include <iostream>
#include"Game.h"
#include"Players_1.h"
#include"Players_2.h"

using namespace std;

int main()
{
    Players_1 P1;
    Players_2 P2;
    int n,x;
    cout<<"\n****************************************\n\t\tTIC TAC TOE\n****************************************";
main_play:
    cout<<"\nENTER YOUR OPTION : \n1.AGAINST COMPUTER\n2.MAN VS MAN\n3.QUIT\t";
    cin>>n;
    switch(n)
    {
                case 1:x=P1.play();break;
                case 2:x=P2.play();break;
                case 3:break;
                default:cout<<"invalid option...";
    }
    if(x==1)
        goto main_play;
}
