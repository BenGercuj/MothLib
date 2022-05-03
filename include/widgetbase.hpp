#ifndef WIDGETBASE_HPP
#define WIDGETBASE_HPP

#include "graphics.hpp"
#include <vector>

class WindowBase;

class WidgetBase
{
    protected:
        WindowBase *_mainw;
        int _posx, _posy, _sizex, _sizey;
        std::string _name;
        bool _focused;

    public:
        WidgetBase(WindowBase *mainw, int posx, int posy, int sizex, int sizey, std::string name);
        virtual ~WidgetBase();

        virtual bool is_selected(int mx, int my) = 0;
        virtual void draw() = 0;
        virtual void event_handler(genv::event ev) = 0;
        virtual std::vector<std::string> returnval() = 0;
};

#endif // WIDGETBASE_HPP
