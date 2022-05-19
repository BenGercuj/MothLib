#include "../include/button.hpp"
using namespace genv;

Button::Button(WindowBase *mainw, int posx, int posy, int sizex, int sizey, std::string name, std::string text, std::function<void()> f) : WidgetBase(mainw, posx, posy, sizex, sizey, name), _value(false), _changed(false), _text(text), _f(f) { }

bool Button::is_selected(int mx, int my)
{
    return mx > _posx && mx < _posx+_sizex && my < _posy && my > _posy-_sizey;
}

void Button::draw()
{
    gout << color(0, 0, 0) << move_to(_posx-2, _posy+2) << box(_sizex+9, -_sizey-9);

    gout << color(255, 255, 255) << move_to(_posx, _posy) << box(_sizex+3, -_sizey-3) << move_to(_posx+1, _posy-1) << color(0, 0, 0) << box(_sizex+1, -_sizey-1) << color(255, 255, 255) << move_to(_posx+_sizex/2-gout.twidth(_text)/2, _posy-_sizey/3) << text(_text);
}

void Button::event_handler(event ev)
{
    if (ev.button == btn_left || ev.keycode == key_space)
    {
        _value = true;

        if (!_changed) { _f(); }

        _changed = true;
    }

    else if (ev.button == -btn_left || ev.keycode == -key_space) { _value = false; _changed = false; }

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
