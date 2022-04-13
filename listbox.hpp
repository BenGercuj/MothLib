#ifndef LISTBOX_HPP
#define LISTBOX_HPP

#include "widgetbase.hpp"
#include <vector>

const int textheight = genv::gout.cascent()+genv::gout.cdescent();

class ListBox : public WidgetBase
{
    std::vector<std::string> _values;
    int _showlimit, _showfirst, _selected;

    public:
        ListBox(WindowBase *mainw, int posx, int posy, int sizex, int sizey, std::string name, std::vector<std::string> values);

        bool is_selected(int mx, int my);
        void draw();
        void event_handler(genv::event ev);
};

#endif // LISTBOX_HPP
