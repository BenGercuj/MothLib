#include "../include/textctrl.hpp"
using namespace genv;

TextCtrl::TextCtrl(WindowBase *mainw, int posx, int posy, int sizex, int sizey, std::string name, std::string val) : WidgetBase(mainw, posx, posy, sizex, sizey, name), _value(val), _limit(sizex/gout.twidth("a")) { }

bool TextCtrl::is_selected(int mx, int my)
{
    return mx <= _posx+_sizex && mx >= _posx && my >= _posy-_sizey && my <= _posy;
}

void TextCtrl::draw()
{
    gout << color(0, 0, 0) << move_to(_posx-2, _posy+2) << box(_sizex+9, -_sizey-9);

    if (_focused)
    {
        gout << color(255, 255, 255) << move_to(_posx-2, _posy+2) << box(_sizex+9, -_sizey-9) << move_to(_posx+2, _posy-2) << color(0, 0, 0) << box(_sizex+1, -_sizey-1) << color(255, 255, 255) << move_to(_posx+4, _posy-_sizey/2) << text(_value);;
    }

    else
    {
        gout << color(255, 255, 255) << move_to(_posx, _posy) << box(_sizex+5, -_sizey-5) << move_to(_posx+2, _posy-2) << color(0, 0, 0) << box(_sizex+1, -_sizey-1) << color(255, 255, 255) << move_to(_posx+4, _posy-_sizey/2) << text(_value);
    }
}

void TextCtrl::event_handler(event ev)
{
    if (ev.type == ev_key)
    {
        if (ev.keycode >= 32 && ev.keycode <= 126 && _value.length() < _limit)
        {
            char c = ev.keycode;
            _value += c;
        }

        else if (ev.keycode == key_backspace && _value.length() > 0)
        {
            _value.erase(_value.length()-1);
        }
    }
}

std::vector<std::string> TextCtrl::returnval()
{
    std::vector<std::string> val = { _value, "string", _name };

    return val;
}

void TextCtrl::setvalue(std::string newval)
{
    if (newval.length() <= _limit) { _value = newval; }
}

std::string TextCtrl::getvalue() { return _value; }
