#ifndef GAMEMASTER_H
#define GAMEMASTER_H


const int M=20;

class GameMaster
{
    public:
        GameMaster();
        virtual ~GameMaster();
        bool isFree(short, short);
        void steps(short, short);
        bool check(short);

    protected:
        short board[M][M];
        int step;
    private:
};

#endif // GAMEMASTER_H
