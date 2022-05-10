#include "../include/window.hpp"

#include <iostream>

Window::Window(int winX, int winY) : WindowBase(winX, winY)
{
    std::vector<int> *field = &_field;

    st = new StaticText(this, XX/2-genv::gout.twidth("Amoeba")/2, YY/4, genv::gout.twidth("Amoeba"), genv::gout.cascent()+genv::gout.cdescent(), "st_title", "Amoeba");

    btn = new Button(this, XX/2-XX/4, YY/2, XX/2, genv::gout.cascent()+genv::gout.cdescent()+10, "btn_start", "Start with two players", [this](){InitGame(false);});

    btn = new Button(this, XX/2-XX/4, YY/2+50, XX/2, genv::gout.cascent()+genv::gout.cdescent()+10, "btn_startalone", "Start with computer", [this](){InitGame(true);});

    btn = new Button(this, XX/2-XX/4, YY/2+100, XX/2, genv::gout.cascent()+genv::gout.cdescent()+10, "btn_startalone", "Exit", [](){exit(0);});

    for (WidgetBase *w: widget_list) { w->draw(); }
}

void Window::InitGame(bool withComp)
{

}

void Window::StartGame(bool withComp)
{

}
