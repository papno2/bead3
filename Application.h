#ifndef APPLICATION_H
#define APPLICATION_H

#include "widgets.hpp"
#include <vector>
#include <string>
#include <fstream>
using namespace std;
using namespace genv;

class Application
{
    public:
        Application(int x, int y);
        void event_loop();
        void registerWidget(Widget *w);
        virtual void action(std::string id);

    protected:
        std::vector<Widget*> widgets;
    private:
};

#endif // APPLICATION_H
