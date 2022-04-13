#include "window.hpp"

Window::Window()
{
    sb = new SpinBox(this, 250, 200, 50, 25, "spinbox1", 10, 0, 20);

    sb = new SpinBox(this, 175, 300, 50, 25, "spinbox2", 13, -666, 333);

    lb = new ListBox(this, 50, 350, 100, 300, "listbox1", {"sanyi", "lajos", "karcsi", "jani"});

    lb = new ListBox(this, 250, 325, 100, 50, "listbox2", {"hatos", "kettes", "egyes", "tizes"});

    for (WidgetBase *w: widget_list) { w->draw(); }
}
