#ifndef WINDOWBASE_HPP
#define WINDOWBASE_HPP

#include "widgetbase.hpp"
#include <vector>

class WindowBase
{
    protected:
        std::vector<WidgetBase*> widget_list;
        int XX, YY;
        std::vector<std::vector<int>> _field;
        int _playerid;

    public:
        WindowBase(int winX, int winY);

        void event_loop();
        void add_widget(WidgetBase *w);
        void Draw();
        void Winner(int id);
};

#endif // WINDOWBASE_HPP
