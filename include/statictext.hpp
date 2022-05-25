#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP

#include "widgetbase.hpp"

class StaticText : public WidgetBase
{
    std::string _value;

    public:
        StaticText(WindowBase *mainw, int posx, int posy, std::string name, std::string val);

        bool is_selected(int mx, int my);
        void draw();
        void event_handler(genv::event ev);
        std::vector<std::string> returnval();
        std::string getvalue();
};

#endif // STATICTEXT_HPP
