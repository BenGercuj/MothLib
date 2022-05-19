#ifndef WINDOWBASE_HPP
#define WINDOWBASE_HPP

#include "widgetbase.hpp"
#include <vector>
#include <fstream>
#include <iostream>

class WindowBase
{
    protected:
        std::vector<WidgetBase*> widget_list;
        int XX, YY;

    public:
        WindowBase(int winX, int winY);

        void event_loop();
        void add_widget(WidgetBase *w);
};

#endif // WINDOWBASE_HPP
