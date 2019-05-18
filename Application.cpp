#include "Application.h"
#include "OXbox.h"

Application::Application(int x, int y)
{
    genv::gout.open(x,y);
    Widget* b1= new OXbox(this, 20, 20, 30, 30);
    Widget* b2= new OXbox(this, 20, 50, 30, 30);
    Widget* b3= new OXbox(this, 50, 20, 30, 30);
    Widget* b4= new OXbox(this, 50, 50, 30, 30);

}
void Application::registerWidget(Widget *w)
{
    widgets.push_back(w);
}
void Application::event_loop()
{
    event ev;
    int focus = -1;
    while(gin >> ev ) {
        if (ev.type == ev_mouse) {
            for (size_t i=0;i<widgets.size();i++) {
                    widgets[i]->unfocus();
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }
        if (ev.keycode==key_enter)
        {
            action("enter");
        }
        if (ev.keycode==key_tab)
        {
            if (focus!=-1)
                widgets[focus]->unfocus();
            focus=(++focus)%widgets.size();
        }
        if (focus!=-1) {
            if (widgets[focus]->isfocusable())
                widgets[focus]->focus();
            else
                focus=(++focus)%widgets.size();
            widgets[focus]->handle(ev);
        }
        for (Widget * w : widgets) {
            w->draw();
        }
        gout << refresh;
    }
}

void Application::action(string id)
{

}
