#include "Application.h"
#include<iostream>

Application::Application(int n, int s): _wn(n), _ws(s)
{
    genv::gout.open(_wn*_ws,_wn*_ws);
    initGame();
}

void Application::registerWidget(Widget *w)
{
    _widgets.push_back(w);
}

void Application::initGame()
{
    for (int i=0; i<_wn; i++)
    {
        for (int j=0; j<_wn; j++)
        {
            Widget* b= new OXbox(this, j*_ws, i*_ws, _ws, _ws);
        }
    }
    _TheGameIsOn=true;
    // _winner=-1;

}

void Application::event_loop()
{
    event ev;
    int unfocusables;
    int focus = -1;
    while(gin >> ev)
    {
        if (ev.type == ev_mouse)
        {
            for (size_t i=0; i<_widgets.size(); i++)
            {
                _widgets[i]->unfocus();
                if (_widgets[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                    focus = i;
                }
            }
        }
        if (ev.keycode==key_enter)
            _gm.drawOnConsol();
        if (ev.keycode==key_tab)
        {
            if (focus>-1)
                _widgets[focus]->unfocus();
            focus++;
            focus=(focus%_widgets.size());
        }
        if (focus>-1 && _widgets[focus]->isfocusable())
        {
            _widgets[focus]->focus();
            _widgets[focus]->handle(ev);

            if(ev.button==btn_left)
            {
                if (_gm.check(Player1))
                {
                    //_winner=Jatekos1;
                    endofGame(Player1);
                }
                if (_gm.check(Player2))
                {
                    //_winner=Jatekos2;
                    endofGame(Player2);
                }
                unfocusables=0;
                for(int i=0; i<_widgets.size(); i++)
                {
                    if (!_widgets[i]->isfocusable())
                        unfocusables++;
                }
                if (unfocusables==_wn*_wn && _TheGameIsOn)
                {
                    endofGame(-1);
                }
            }
        }

        if (ev.keycode==key_escape)
        {
            return;
        }

        if (_TheGameIsOn)
        {
            for (Widget * w : _widgets)
            {
                w->draw();
            }
        }
            gout << refresh;


    }
}
///kulon nezni h ki jon, mit lepett->X/O es utana kulon ellenorizni, h nyert-e
bool Application::check(int x, int y)
{
    bool whoSteps=(_gm.steps(x/_ws, y/_ws));
    /*if (_gm.check(whoSteps))
    {
        _TheGameIsOn=false;
    }*/

    return whoSteps;
}



void Application::endofGame(int winner)
{
    _TheGameIsOn=false;
    for (int i=0; i<_wn*_wn; i++)
    {
        _widgets[i]->unfocusable();

    }
    genv::gout<<move_to(_wn*_ws/2-100, _wn*_ws/2-80) << color (0,0,0)<<box(200,160);
    string w;
    if (winner==Player1)
        w="Player1";
    else if (winner==Player2)
        w="Player2";
    else
        w="No one";
    genv::gout<<move_to(_wn*_ws/2-40, _wn*_ws/2-50) <<color(255, 50, 50)<<text(w)<<text(" won!");
    genv::gout<<move_to(_wn*_ws/2-40, _wn*_ws/2-10) <<color(200, 200, 200) <<box(80,30);
    genv::gout<<move_to(_wn*_ws/2-30, _wn*_ws/2+10) <<color(0,0,0)<<text("New game");
    genv::gout<<move_to(_wn*_ws/2-40, _wn*_ws/2+30) <<color(160, 160, 160) <<box(80, 30);
    genv::gout<<move_to(_wn*_ws/2-15, _wn*_ws/2+50) <<color(0,0,0)<<text("Exit");
    std::cout<<w;
}
