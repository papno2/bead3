#include "GameMaster.h"

GameMaster::GameMaster()
{
    for (short i=0; i<M; i++)
        for (short j=0; j<M; j++)
        {
            board[i][j]=-1;
        }
    step=1;
}
bool GameMaster::isFree(short x, short y)
{
    if (board[x][y]==-1)
        return true;
    return false;
}

void GameMaster::steps(short x, short y)
{
    if (isFree(x, y))
    {
        board[x][y]=step%2;
        step++;
    }
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


GameMaster::~GameMaster()
{
    //dtor
}
