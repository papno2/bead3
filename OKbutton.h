#ifndef OKBUTTON_H
#define OKBUTTON_H

#include "widgets.hpp"
#include "Application.h"


class OKbutton : public Widget
{
    public:
        OKbutton(Application* parent, int x, int y, int sx, int sy, std::string s);
        void handle(genv::event ev);
        void draw();
    protected:
        std::string _text;
        bool _pushed;
    private:
};

#endif // OKBUTTON_H
