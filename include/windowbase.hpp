#ifndef WINDOWBASE_HPP
#define WINDOWBASE_HPP

#include "widgetbase.hpp"
#include <vector>

class WindowBase
{
    protected:
        std::vector<WidgetBase*> widget_list;

    public:
        void event_loop();
        void add_widget(WidgetBase *w);
};

#endif // WINDOWBASE_HPP
