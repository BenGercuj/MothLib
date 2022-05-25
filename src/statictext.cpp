#include "../include/statictext.hpp"
using namespace genv;

StaticText::StaticText(WindowBase *mainw, int posx, int posy, std::string name, std::string val) : WidgetBase(mainw, posx, posy, 0, 0, name), _value(val) { }

bool StaticText::is_selected(int mx, int my)
{
    return mx <= _posx+_sizex && mx >= _posx && my >= _posy-_sizey && my <= _posy;
}

void StaticText::draw()
{
    gout << move_to(_posx, _posy) << text(_value);
}

void StaticText::event_handler(event ev) { }

std::vector<std::string> StaticText::returnval()
{
    std::vector<std::string> val = { _value, "string", _name };

    return val;
}

std::string StaticText::getvalue() { return _value; }
