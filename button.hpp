#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "widgetbase.hpp"

class Button : public WidgetBase
{
    bool _value, _changed;

    public:
        Button(WindowBase *mainw, int posx, int posy, int sizex, int sizey, std::string name);

        bool is_selected(int mx, int my);
        void draw();
        void event_handler(genv::event ev);

        std::vector<std::string> returnval();
};

#endif // BUTTON_HPP
