#include "windowbase.hpp"

using namespace genv;

void WindowBase::event_loop() {
    event ev;
    int focus = -1;
    while(gin >> ev && ev.keycode != key_escape )
    {
        if (ev.button==btn_left)
        {
            for (size_t i=0;i<widget_list.size();i++)
            {
                if (widget_list[i]->is_selected(ev.pos_x, ev.pos_y)) { focus = i; }
            }
        }

        if (focus!=-1) { widget_list[focus]->event_handler(ev); }

        for (WidgetBase * w : widget_list) { w->draw(); }

        gout << refresh;
    }
}

void WindowBase::add_widget(WidgetBase *w) { widget_list.push_back(w); }
