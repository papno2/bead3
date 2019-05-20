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

bool GameMaster::steps(short x, short y)
{
    if (isFree(x, y))
    {
        step++;
        board[x][y]=step%2;
    }
    return step%2; //ha sikerult lepni, a masik jatekos jon, ha nem, tovabbra is a jelenlegi
}

/*int GameMaster::steps(short x, short y)
{
    if (isFree(x, y))
    {
        step++;
        board[x][y]=step%2;
        return step%2; // ha sikerult lepni, akkor visszater annak a szamaval, aki lepett
    }
    return -1; //ha nem sikerult lepni -> -1
}*/

bool GameMaster::check(short who)
{
    short horizontalcount=0;
    short verticalcount=0;
    short diagonalcount1=0;
    short diagonalcount2=0;

    for (short i=0; i<M; i++)
    {
        for (short j=0; j<M; j++)
        {
            if (board[j][i]==who)
            {
                horizontalcount++;
                //std::cout<< horizontalcount<<' ';
                if (horizontalcount>=5)
                    return true;
            } else{
                horizontalcount=0;
            }

            if (board[i][j]==who)
            {
                verticalcount++;
                //std::cout<< verticalcount<<' ';
                if (verticalcount>=5)
                    return true;
            } else{
                verticalcount=0;
            }
        }
    }
    for (short t=0; t<=M-5; t++) //bal felso-jobb also
    {
        for (short h=0; h<abs(M-t); h++)
        {
            if (board[h][h+t]==who)
            {
                diagonalcount1++;
                //std::cout<< diagonalcount1<<' ';
                if (diagonalcount1>=5)
                    return true;
            } else{
                diagonalcount1=0;
            }

            if (board[h+t][h]==who)
            {
                diagonalcount2++;
                //std::cout<< diagonalcount2<<' ';
                if (diagonalcount2>=5)
                    return true;
            } else{
                diagonalcount2=0;
            }
        }

    }
    for (short t=4; t<M; t++) //jobb felso-bal also
    {
        for (short h=0; h<=t; h++)
        {
            if (board[h][t-h]==who)
            {
                diagonalcount1++;
                //std::cout<< diagonalcount1<<' ';
                if (diagonalcount1>=5)
                    return true;
            } else{
                diagonalcount1=0;
            }
            if (board[M-1-h][M-1-t+h]==who)
            {
                diagonalcount2++;
                //std::cout<< diagonalcount2<<' ';
                if (diagonalcount2>=5)
                    return true;
            } else{
                diagonalcount2=0;
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

