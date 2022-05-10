#include "../include/statictext.hpp"
using namespace genv;

StaticText::StaticText(WindowBase *mainw, int posx, int posy, int sizex, int sizey, std::string name, std::string val, int *getval) : WidgetBase(mainw, posx, posy, sizex, sizey, name), _value(val), _limit(sizey/gout.twidth("a")), _getval(getval) { }

bool StaticText::is_selected(int mx, int my)
{
    return mx <= _posx+_sizex && mx >= _posx && my >= _posy-_sizey && my <= _posy;
}

void StaticText::draw()
{
    gout << color(0, 0, 0) << move_to(_posx-2, _posy+2) << box(_sizex+9, -_sizey-9);

    if (_focused)
    {
        gout << color(255, 255, 255) << move_to(_posx-2, _posy+2) << box(_sizex+9, -_sizey-9) << move_to(_posx+2, _posy-2) << color(0, 0, 0) << box(_sizex+1, -_sizey-1) << color(255, 255, 255) << move_to(_posx+4, _posy-_sizey/2) << text(_value);
    }

    else
    {
        gout << color(255, 255, 255) << move_to(_posx, _posy) << box(_sizex+5, -_sizey-5) << move_to(_posx+2, _posy-2) << color(0, 0, 0) << box(_sizex+1, -_sizey-1) << color(255, 255, 255) << move_to(_posx+4, _posy-_sizey/2) << text(_value);
    }
}

void StaticText::event_handler(event ev) { _value = std::to_string(*_getval); }

std::vector<std::string> StaticText::returnval()
{
    std::vector<std::string> val = { _value, "string", _name };

    return val;
}

void StaticText::setvalue(std::string newval)
{
    if (newval.length() <= _limit) { _value = newval; }
}

std::string StaticText::getvalue() { return _value; }
