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

}

void Application::event_loop()
{
    event ev;

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
            if (focus!=-1)
                _widgets[focus]->unfocus();
            focus=(++focus)%_widgets.size();
        }
        if (focus!=-1)
        {
            if (_widgets[focus]->isfocusable())
                _widgets[focus]->focus();
            else
                focus=(++focus)%_widgets.size();
            _widgets[focus]->handle(ev);
        }

        if (_TheGameIsOn)
        {
            for (Widget * w : _widgets)
            {
                w->draw();
            }
            gout << refresh;

        }
        else
        {
            endofGame();
            gout << refresh;
        }
    }
}
///kulon nezni h ki jon, mit lepett->X/O es utana kulon ellenorizni, h nyert-e
bool Application::check(int x, int y)
{
    bool whoSteps=(_gm.steps(x/_ws, y/_ws));
    if (_gm.check(whoSteps))
    {
        _TheGameIsOn=false;
    }

    return whoSteps;
}



void Application::endofGame()
{
    //genv::gout<<refresh;
    for (int i=0; i<_wn*_wn; i++)
    {
        _widgets[i]->unfocusable();

    }
    genv::gout<<move_to(_wn*_ws/2-100, _wn*_ws/2-50) << color (0,0,0)<<box(200,100);
    genv::gout<<move_to(_wn*_ws/2-10, _wn*_ws/2) <<color(255, 50, 50)<<text("Vege");
}
