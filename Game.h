#ifndef GAME_H
#define GAME_H
//#include"Players_1.h"
//#include"Players_2.h"
class Game
{
    public:
        int i,j,k,size;
        Game();
        void print(char a[100][100],int size);
        int check(char a[100][100],int size);

    protected:

    private:
};

#endif // GAME_H
