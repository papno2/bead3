#ifndef GAMEMASTER_H
#define GAMEMASTER_H
#include<cmath>

const int M=18;

class GameMaster
{
    public:
        GameMaster();

        bool isFree(short, short); //szabad-e az adott mezo
        bool steps(short, short); //lepes ellenorzese (lehet-e, ha igen, beirja a belso reprezentacioba)
        bool check(short); //nyert-e valaki
       // void drawOnConsol();

    protected:
        short board[M][M]; //palya reprezentacioja; -1: ures, 1:1.jatekos, 0:2. jatekos
        int step; //hanyadik lepes; ptln->1. jatekos lep, ps->2. jatekos lep
    private:
};

#endif // GAMEMASTER_H
