#include "widgets.hpp"
#include "graphics.hpp"
#include "Application.h"
using namespace genv;

Widget::Widget(Application* parent, int x, int y, int sx, int sy, bool f) :
     _parent(parent), _x(x), _y(y), _size_x(sx), _size_y(sy), _focusable(f)
{
    _in_focus=false;
    _parent->registerWidget(this);
}

bool Widget::is_selected(int mouse_x, int mouse_y)
{
    return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}
void Widget::focus()
{
    if (_focusable)
        _in_focus=true;
}
void Widget::unfocus()
{
    _in_focus=false;
}

bool Widget::isfocusable()
{
    return _focusable;
}

void Widget::unfocusable()
{
    _focusable=false;
}

Widget::~Widget()
{
    _parent=nullptr;
}
