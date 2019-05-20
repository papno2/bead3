#ifndef APPLICATION_H
#define APPLICATION_H

#define Player1 1
#define Player2 0

#include "widgets.hpp"
#include "OXbox.h"
#include "OKbutton.h"
#include "GameMaster.h"
#include <vector>
#include <string>

//using namespace std;
using namespace genv;


class Application
{
    public:
        Application(int, int);
        void InitGame();
        void event_loop();
        void registerWidget(Widget*);
        virtual bool StepCheck(int, int);
        void action(std::string);
        void EndofGame(int);

    protected:
        std::vector<Widget*> _widgets;
        //OKbutton* BNewGame, *BExit;
        GameMaster* _gm;
        bool _TheGameIsOn;
        int _wn, _ws;
        int focus;
    private:
};

#endif // APPLICATION_H
