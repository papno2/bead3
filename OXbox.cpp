#include "OXbox.h"
#include <cmath>

using namespace genv;

void kort_rajzol(int r, int x, int y)
    {
        for (int i=-r; i<r; i++)
        {
            for (int j=-r; j<r; j++)
            {
                if ((pow(i, 2)+pow(j, 2))<pow(r,2))
                    gout << move_to(x+i, y+j) << dot;
            }
        }
    }

OXbox::OXbox(Application* parent, int x, int y, int sx, int sy) :
    Widget(parent, x, y, sx, sy, true)
{
    _checked=false;
    _xo=Player1;
}

void OXbox::draw()
{
    if(_in_focus)
        gout << move_to(_x, _y) << color(0,0,255) << box(_size_x, _size_y);
    else
        gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    if (_checked)
    {
        gout << color(255,255,255);
        if (_xo)
        {
            gout << move_to(_x+4, _y+4) << line(_size_x-8, _size_y-8);
            gout << move_to(_x+5, _y+4) << line(_size_x-8, _size_y-8);
            gout << move_to(_x+_size_x-4, _y+4) << line(-_size_x+8, _size_y-8);
            gout << move_to(_x+_size_x-5, _y+4) << line(-_size_x+8, _size_y-8);
        } else
        {
            kort_rajzol(_size_x/2-4, _x+_size_x/2, _y+_size_y/2);
            gout << color(0,0,0);
            kort_rajzol(_size_x/2-6, _x+_size_x/2, _y+_size_y/2);
        }

    }
}

void OXbox::handle(genv::event ev)
{
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left)
        {
            _xo=_parent->check(ev.pos_x, ev.pos_y);
            _checked = true;
            _focusable=false;
        }
}



