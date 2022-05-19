#include "../include/windowbase.hpp"
#include <fstream>
#include <iostream>

using namespace genv;

WindowBase::WindowBase(int winX, int winY) : XX(winX), YY(winY) { }

void WindowBase::event_loop()
{
    event ev;
    int focus = -1; bool did_event = false;
    while(gin >> ev && ev.keycode != key_escape )
    {
        if (ev.button==btn_left)
        {
            did_event = false;

            for (size_t i=0;i<widget_list.size();i++)
            {
                if (widget_list[i]->is_selected(ev.pos_x, ev.pos_y)) { focus = i; did_event = true; }
            }

            if (!did_event) { focus = -1; }
        }

        if (focus!=-1 && widget_list[focus]) { widget_list[focus]->event_handler(ev); }

        for (WidgetBase * w : widget_list) { w->draw(); }
    }
}


void WindowBase::add_widget(WidgetBase *w) { widget_list.push_back(w); }
