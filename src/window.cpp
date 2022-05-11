#include "../include/window.hpp"

#include <iostream>

Window::Window(int winX, int winY) : WindowBase(winX, winY)
{
    st = new StaticText(this, XX/2-genv::gout.twidth("Amoeba")/2, YY/4, genv::gout.twidth("Amoeba"), genv::gout.cascent()+genv::gout.cdescent(), "st_title", "Amoeba");

    btn = new Button(this, XX/2-XX/4, YY/2, XX/2, genv::gout.cascent()+genv::gout.cdescent()+10, "btn_start", "Start with two players", [this](){std::cout << "Hih"; InitGame(false);});

    btn = new Button(this, XX/2-XX/4, YY/2+50, XX/2, genv::gout.cascent()+genv::gout.cdescent()+10, "btn_startalone", "Start with computer", [this](){std::cout << "Hih"; InitGame(true);});

    btn = new Button(this, XX/2-XX/4, YY/2+100, XX/2, genv::gout.cascent()+genv::gout.cdescent()+10, "btn_exit", "Exit", [](){exit(0);});

    for (WidgetBase *w: widget_list) { w->draw(); }
}

void Window::InitGame(bool withComp)
{
    for (size_t i = 0; i < widget_list.size(); i++)
    {
        delete widget_list[i];
        widget_list[i] = 0;
    }

    widget_list.clear();

    genv::gout << genv::move_to(1, YY-1) << genv::color(0, 0, 0) << genv::box_to(XX-1, 0) << genv::color(255, 255, 255) << genv::refresh;

    StartGame(withComp);
}

void Window::StartGame(bool withComp)
{
    std::vector<std::vector<int>> *field = &_field;

    btn = new Button(this, XX/2, YY/2, XX/20-2, YY/20-2, "btn_1", "a", [](){});
}
