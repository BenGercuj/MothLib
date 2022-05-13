#include "../include/windowbase.hpp"
#include <fstream>
#include <iostream>

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

        // Checker
        int counter = 0;
        for (size_t i = 0; i < _field.size(); i++)
        {
            for (size_t j = 0; j < _field[i].size(); j++)
            {
                if (_field[i][j] != 0)
                {
                    counter = 1;
                    int holder = _field[i][j];
                    if (20-(int)i >= 5)
                    {
                        for (int x = i+1; x < i+5; x++)
                        {
                            if (_field[x][j] == holder)
                            {
                                counter++;
                            }

                            else { break; }
                        }
                    }
                    if (counter >= 5) { Winner(holder); break; }
                    counter = 1;

                    if (20-(int)j >= 5)
                    {
                        for (int x = j+1; x < j+5; x++)
                        {
                            if (_field[i][x] == holder)
                            {
                                counter++;
                            }

                            else { break; }
                        }
                    }
                    if (counter >= 5) { Winner(holder); break; }
                    counter = 1;
                }
            }
        }

        gout << refresh;
    }
}

void WindowBase::add_widget(WidgetBase *w) { widget_list.push_back(w); }

void WindowBase::Draw()
{
    for (size_t i = 0; i < widget_list.size(); i++)
    {
        delete widget_list[i];
        widget_list[i] = 0;
    }

    widget_list.clear();

    genv::gout << genv::move_to(1, YY-1) << genv::color(0, 0, 0) << genv::box_to(XX-1, 0) << genv::color(255, 255, 255) << genv::move_to(XX/2, YY/2) << genv::text("Draw!");
}

void WindowBase::Winner(int id)
{
    for (size_t i = 0; i < widget_list.size(); i++)
    {
        delete widget_list[i];
        widget_list[i] = 0;
    }

    widget_list.clear();

    genv::gout << genv::move_to(1, YY-1) << genv::color(0, 0, 0) << genv::box_to(XX-1, 0) << genv::color(255, 255, 255) << genv::move_to(XX/2, YY/2);

    if (id == 1) { genv::gout << genv::text("Player X wins!"); }
    else if (id == -1) { genv::gout << genv::text("Player O wins!"); }
}
