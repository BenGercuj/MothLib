#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP

#include "widgetbase.hpp"

class StaticText : public WidgetBase
{
    std::string _value;
    int _limit;

    public:
        StaticText(WindowBase *mainw, int posx, int posy, int sizex, int sizey, std::string name, std::string val);

        bool is_selected(int mx, int my);
        void draw();
        void event_handler(genv::event ev);
        std::vector<std::string> returnval();

        void setvalue(std::string newval);
};

#endif // STATICTEXT_HPP
