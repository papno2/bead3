#ifndef GAMEMASTER_H
#define GAMEMASTER_H
#include<cmath>

const int M=10;

class GameMaster
{
    public:
        GameMaster();

        bool isFree(short, short);
        bool steps(short, short);
        bool check(short); //nyert-e valaki
        void drawOnConsol();

    protected:
        short board[M][M]; //palya reprezentacioja; -1: ures, 1:1.jatekos, 0:2. jatekos
        int step; //hanyadik lepes; ptln->1. jatekos lep, ps->2. jatekos lep
    private:
};

#endif // GAMEMASTER_H
