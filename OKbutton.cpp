#include "OKbutton.h"
//#include "Application.h"
using namespace genv;

OKbutton::OKbutton(Application* parent, int x, int y, int sx, int sy, std::string s): Widget(parent, x, y, sx, sy,true)
{
    _text=s;
    _pushed=false;
}
void OKbutton::draw()
{
    if(_in_focus)
        gout << color(0,0,255);
    else
        gout << color(255,255,255);
    gout << move_to(_x, _y) << box(_size_x, _size_y);
    if (_pushed)
        gout << color(150,150,150);
    else
        gout << color(180,180,180);
    gout << move_to(_x+2, _y+2) << box(_size_x-4, _size_y-4);
    gout << color(0,0,0)<< move_to(_x+_size_x/2-gout.twidth(_text)/2, _y+_size_y/2+6) << text(_text);
}
void OKbutton::handle(genv::event ev)
{
    if (ev.button==btn_left && is_selected(ev.pos_x, ev.pos_y))
    {
        if (ev.button<0)
        {
            _pushed=false;
        }
        if (ev.button>0)
            _pushed=true;
            _parent->action(_text);
    }
}
