#include "GameMaster.h"
#include<iostream>

GameMaster::GameMaster()
{
    for (short i=0; i<M; i++)
        for (short j=0; j<M; j++)
        {
            board[i][j]=-1;
        }
    step=0;
}
bool GameMaster::isFree(short x, short y)
{
    if (board[x][y]==-1)
        return true;
    return false;
}

/*bool GameMaster::steps(short x, short y)
{
    if (isFree(x, y))
    {
        board[x][y]=step%2;
        step++;
    }
    return (step%2==1); //ha sikerult lepni, a masik jatekos jon, ha nem, tovabbra is a jelenlegi
}*/

int GameMaster::steps(short x, short y)
{
    if (isFree(x, y))
    {
        step++;
        board[x][y]=step%2;
        return step%2; // ha sikerult lepni, akkor visszater annak a szamaval, aki lepett
    }
    return -1; //ha nem sikerult lepni -> -1
}

bool GameMaster::check(short who)
{
    short horizontalcount=0;
    short verticalcount=0;
    short diagonalcount1=0;
    short diagonalcount2=0;

    bool horizontal, vertical;

    for (short i=0; i<M; i++)
    {
        horizontal=true;
        vertical=true;
        for (short j=0; j<M; j++)
        {
            if (horizontal && board[i][j]==who)
            {
                horizontalcount++;
                horizontal=true;
                //std::cout<< horizontalcount<<' ';
                if (horizontalcount>=5)
                    return true;
            } else{
                horizontalcount=0;
                horizontal=false;
            }

             if (vertical && board[j][i]==who)
            {
                verticalcount++;
                vertical=true;
                std::cout<< verticalcount<<' ';
                if (verticalcount>=5)
                    return true;
            } else{
                verticalcount=0;
                vertical=false;
            }
        }
    }

     return false;
}

void GameMaster::drawOnConsol()
{
    for (short i=0; i<M; i++)
    {
        std::cout<<std::endl;
        for (short j=0; j<M; j++)
        {
            if (board[j][i]==0)
                std::cout<<'O';
            if (board[j][i]==1)
                std::cout<<'X';
            if (board[j][i]==-1)
                std::cout<<' ';
        }
    }
}

GameMaster::~GameMaster()
{
    //dtor
}
