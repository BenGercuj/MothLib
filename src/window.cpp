#include "../include/window.hpp"
#include <iostream>

Window::Window()
{
    std::function<void()> f = [this]()
    {
        for (WidgetBase* wb: this->widget_list)
        {
            std::cout << wb->_name << "\n";
        }
    };

    sb = new SpinBox(this, 250, 200, 50, 25, "spinbox1", 10, 0, 20);

    sb = new SpinBox(this, 175, 300, 50, 25, "spinbox2", 13, -666, 333);

    lb = new ListBox(this, 50, 350, 100, 300, "listbox1", {"sanyi", "lajos", "karcsi", "jani"});

    lb = new ListBox(this, 250, 325, 100, 50, "listbox2", {"hatos", "kettes", "egyes", "tizes"});

    btn = new Button(this, 250, 50, 50, 25, "button1", "OK", f);

    for (WidgetBase *w: widget_list) { w->draw(); }
}
