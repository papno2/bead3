#include "Application.h"
//#include<iostream>

Application::Application(int n, int s): _wn(n), _ws(s)
{
    genv::gout.open(_wn*_ws,_wn*_ws);
    InitGame();
}

void Application::registerWidget(Widget *w)
{
    _widgets.push_back(w);
}

void Application::InitGame()
{
    for (int i=0; i<_wn; i++)
    {
        for (int j=0; j<_wn; j++)
        {
            Widget* b= new OXbox(this, j*_ws, i*_ws, _ws, _ws);
        }
    }
    _gm= new GameMaster;
    _TheGameIsOn=true;

}

void Application::event_loop()
{
    event ev;
    int unfocusables;
    int focus = -1;
    while(gin >> ev)
    {
        if (ev.keycode==key_escape)
            return;

        if (_TheGameIsOn)
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
            /*if (ev.keycode==key_enter)
                _gm->drawOnConsol();*/
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
                    if (_gm->check(Player1))
                    {
                        EndofGame(Player1);
                    }
                    if (_gm->check(Player2))
                    {
                        EndofGame(Player2);
                    }
                    unfocusables=0;
                    for(unsigned i=0; i<_widgets.size(); i++)
                    {
                        if (!_widgets[i]->isfocusable())
                            unfocusables++;
                    }
                    if (unfocusables==_wn*_wn && _TheGameIsOn)
                    {
                        EndofGame(-1);
                    }
                }
            }

            for (Widget * w : _widgets)
            {
                w->draw();
            }

        } else
        {
            focus=-1;
            if (ev.type == ev_mouse && ev.button==btn_left)
            {
                if (_wn*_ws/2-40<ev.pos_x && ev.pos_x<_wn*_ws/2+40 && _wn*_ws/2-20<ev.pos_y && ev.pos_y<_wn*_ws/2+10)
                {
                    InitGame();
                }
                if (_wn*_ws/2-40<ev.pos_x && ev.pos_x<_wn*_ws/2+40 && _wn*_ws/2+20<ev.pos_y && ev.pos_y<_wn*_ws/2+50)
                    return;
            }
        }

        gout << refresh;

    }
}

bool Application::StepCheck(int x, int y)
{
    bool whoSteps=(_gm->steps(x/_ws, y/_ws));

    return whoSteps;
}



void Application::EndofGame(int winner)
{
    _TheGameIsOn=false;
    for (unsigned i=0; i<_widgets.size(); i++)
    {
        _widgets[i]->draw();
        delete _widgets[i];

    }
    _widgets.clear();
    genv::gout<<move_to(_wn*_ws/2-70, _wn*_ws/2-74) << color (250,0,0)<<box(140,148);
    genv::gout<<move_to(_wn*_ws/2-66, _wn*_ws/2-70) << color (0,0,0)<<box(132,140);
    string w;
    if (winner==Player1)
        w="Player1 (X)";
    else if (winner==Player2)
        w="Player2 (O)";
    else
        w="No one";
    genv::gout<<move_to(_wn*_ws/2-60, _wn*_ws/2-40) <<color(255, 50, 50)<<text(w)<<text(" won!");
    genv::gout<<move_to(_wn*_ws/2-40, _wn*_ws/2-20) <<color(200, 200, 200) <<box(80,30);
    genv::gout<<move_to(_wn*_ws/2-30, _wn*_ws/2) <<color(0,0,0)<<text("New game");
    genv::gout<<move_to(_wn*_ws/2-40, _wn*_ws/2+20) <<color(160, 160, 160) <<box(80, 30);
    genv::gout<<move_to(_wn*_ws/2-15, _wn*_ws/2+40) <<color(0,0,0)<<text("Exit");
    delete _gm;
}
