#include "../include/windowbase.hpp"
#include <fstream>

using namespace genv;

WindowBase::WindowBase(int winX, int winY) : XX(winX), YY(winY), _playerid(1)
{
    for (int i = 0; i < 20; i++)
    {
        std::vector<int> holder;
        for (int j = 0; j < 20; j++)
        {
            holder.push_back(0);
        }
        _field.push_back(holder);
    }
}

void WindowBase::event_loop() {
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

//        if (focus != -1 && did_event)
//        {
//            std::vector<std::string> val;
//            val = widget_list[focus]->returnval();

//            std::ofstream of("log.txt", std::_S_app);
//            if (val[1] != "void") { of << "Registered value: " << val[0] << ", type: " << val[1] << ", from: " << val[2] << std::endl; }
//            did_event = false;

//            of.close();
//        }

//        for (WidgetBase *w: widget_list)
//        {
//            if (w->_name == "st_result") { w->event_handler(ev); }
//        }

        for (WidgetBase * w : widget_list) { w->draw(); }

        gout << refresh;
    }
}

void WindowBase::add_widget(WidgetBase *w) { widget_list.push_back(w); }
