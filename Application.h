#ifndef APPLICATION_H
#define APPLICATION_H

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
        void event_loop();
        void registerWidget(Widget*);
        virtual bool action(int, int);
        void endofGame();

    protected:
        std::vector<Widget*> _widgets;
        GameMaster _gm;
        bool _TheGameIsOn;
        int _wn, _ws;
        int focus;
    private:
};

#endif // APPLICATION_H
