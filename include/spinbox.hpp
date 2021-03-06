#ifndef SPINBOX_HPP
#define SPINBOX_HPP

#include "widgetbase.hpp"

class SpinBox : public WidgetBase
{
    int _val, _minval, _maxval;
    bool _changed;

    public:
        SpinBox(WindowBase *mainw, int posx, int posy, int sizex, int sizey, std::string name, int val, int minval, int maxval);

        bool is_selected(int mx, int my);
        int selected_spinner(int mx, int my);
        void draw();
        void event_handler(genv::event ev);
        std::vector<std::string> returnval();
};

#endif // SPINBOX_HPP
