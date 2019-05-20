#ifndef OXBOX_H
#define OXBOX_H

#include "widgets.hpp"
#include "graphics.hpp"
#include "Application.h"
//class Application;

class OXbox : public Widget
{
    public:
        OXbox(Application* parent, int x, int y, int sx, int sy);
        void handle(genv::event);
        void draw();
    protected:
        bool _xo; //X vagy O lesz kirajzolva (X az 1., O a 2. jatekos)
        bool _checked;
    private:
};

#endif // OXBOX_H
