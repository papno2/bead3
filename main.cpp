#include "graphics.hpp"
#include "widgets.hpp"
#include "OXbox.h"
#include "examplecheckbox.hpp"
#include "Application.h"
#include "GameMaster.h"
#include <vector>
using namespace std;
using namespace genv;

void event_loop(vector<Widget*>& widgets) {
    event ev;
    int focus = -1;
    while(gin >> ev ) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                    widgets[i]->unfocus();
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }
        if (ev.keycode==key_tab)
        {
            if (focus!=-1)
                widgets[focus]->unfocus();
            focus=(++focus)%widgets.size();
            //widgets[focus]->focus();
        }
        if (focus!=-1) {
            widgets[focus]->focus();
            widgets[focus]->handle(ev);
        }
        for (Widget * w : widgets) {
            w->draw();
        }
        gout << refresh;
    }
}

int main()
{
    Application app(10, 30);
    app.event_loop();

    return 0;
}
