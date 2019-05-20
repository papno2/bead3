#include "OKbutton.h"
//#include "Application.h"
using namespace genv;

OKbutton::OKbutton(Application* parent, int x, int y, int sx, int sy, std::string s): Widget(parent, x, y, sx, sy,true)
{
    _text=s;
}
void OKbutton::draw()
{
    if(_in_focus)
        gout << move_to(_x, _y) << color(0,0,255) << box(_size_x, _size_y);
    else
        gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(150,150,150) << box(_size_x-4, _size_y-4);
    gout << color(0,0,0)<< move_to(_x+_size_x/2-gout.twidth(_text)/2, _y+_size_y/2+6) << text(_text);
}
void OKbutton::handle(genv::event ev)
{
    if (ev.button==btn_left && is_selected(ev.pos_x, ev.pos_y))
        _parent->action(_text);
}
