#include "button.hpp"
#include <iostream>

using namespace genv;

Button::Button(WindowBase *mainw, int posx, int posy, int sizex, int sizey, std::string name) : WidgetBase(mainw, posx, posy, sizex, sizey, name), _value(false), _changed(false) { }

bool Button::is_selected(int mx, int my)
{
    return mx > _posx && mx < _posx+_sizex && my < _posy && my > _posy-_sizey;
}

void Button::draw()
{
    if (_focused)
    {
        gout << color(255, 255, 255) << move_to(_posx-2, _posy+2) << box(_sizex+9, -_sizey-9) << move_to(_posx+2, _posy-2) << color(0, 0, 0) << box(_sizex+1, -_sizey-1) << color(255, 255, 255);
    }

    else
    {
        gout << color(255, 255, 255) << move_to(_posx, _posy) << box(_sizex+5, -_sizey-5) << move_to(_posx+2, _posy-2) << color(0, 0, 0) << box(_sizex+1, -_sizey-1) << color(255, 255, 255);
    }
}

void Button::event_handler(event ev)
{
    if (ev.button == btn_left || ev.keycode == key_space) { _value = true; _changed = true; }

    else if (ev.button == -btn_left || ev.keycode == -key_space) { _value = false; _changed = true; }

    _focused = true;
}

std::vector<std::string> Button::returnval()
{
    std::vector<std::string> val;
    if (_changed)
    {
        val = { std::to_string(_value), "bool", _name };

        _changed = false;
    }

    else { val = { "none_selected", "void", _name }; }

    return val;

}
