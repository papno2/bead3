#ifndef APPLICATION_H
#define APPLICATION_H

#define Player1 1
#define Player2 0

#include "widgets.hpp"
#include "OXbox.h"
#include "GameMaster.h"
#include <vector>
#include <string>
#include <fstream>
using namespace std;
using namespace genv;


class Application
{
    public:
        Application(int, int);
        void initGame();
        void event_loop();
        void registerWidget(Widget*);
        virtual bool check(int, int);
        void endofGame(int);

    protected:
        std::vector<Widget*> _widgets;
        GameMaster _gm;
        bool _TheGameIsOn;
        int _wn, _ws;
        int focus;
        //int _winner;
    private:
};

#endif // APPLICATION_H
