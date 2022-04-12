#include "window.hpp"

Window::Window()
{
    sb = new SpinBox(this, 150, 200, 50, 25, "spinbox1", 10, 0, 20);

    sb = new SpinBox(this, 200, 300, 50, 25, "spinbox2", 13, -666, 333);

    for (WidgetBase *w: widget_list) { w->draw(); }
}
