#include "../include/window.hpp"

#include <iostream>

Window::Window(int winX, int winY) : WindowBase(winX, winY)
{
    lb = new ListBox(this, 40, 90, 100, 20, "lb_1", {"1", "2", "3", "4", "5", "6", "7"});

    for (WidgetBase *w: widget_list) { w->draw(); }
}
