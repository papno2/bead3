#ifndef OXBOX_H
#define OXBOX_H

#include "widgets.hpp"
#include "graphics.hpp"
#include "Application.h"

class OXbox : public Widget
{
    public:
        OXbox(Application* parent, int x, int y, int sx, int sy);
        void handle(genv::event);
        void draw();
    protected:
        bool _xo;
        bool _checked;
    private:
};

#endif // OXBOX_H
