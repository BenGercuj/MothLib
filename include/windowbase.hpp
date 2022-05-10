#ifndef WINDOWBASE_HPP
#define WINDOWBASE_HPP

#include "widgetbase.hpp"
#include <vector>

class WindowBase
{
    protected:
        std::vector<WidgetBase*> widget_list;
        int XX, YY; int _calcvalue;

    public:
        WindowBase(int winX, int winY);

        void event_loop();
        void add_widget(WidgetBase *w);
};

#endif // WINDOWBASE_HPP
