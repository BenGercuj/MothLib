#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "widgetbase.hpp"
#include <functional>

class Button : public WidgetBase
{
    bool _value, _changed; std::string _text;
    std::function<void(int, int, int&, std::string&)> _f;
    int _fieldposx, _fieldposy;
    int _whowasit;

    public:
        Button(WindowBase *mainw, int posx, int posy, int sizex, int sizey, std::string name, std::string text, std::function<void(int, int, int&, std::string&)> f, int fieldposx, int fieldposy);

        bool is_selected(int mx, int my);
        void draw();
        void event_handler(genv::event ev);

        std::vector<std::string> returnval();
};

#endif // BUTTON_HPP
