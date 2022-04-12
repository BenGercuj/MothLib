#include "spinbox.hpp"

using namespace genv;

SpinBox::SpinBox(WindowBase *mainw, int posx, int posy, int sizex, int sizey, std::string name, int val, int minval, int maxval) : WidgetBase(mainw, posx, posy, sizex, sizey, name), _val(val), _minval(minval), _maxval(maxval) { }

bool SpinBox::is_selected(int mx, int my)
{
    return mx <= _posx+_sizex && mx >= _posx && my >= _posy-_sizey && my <= _posy;
}

void SpinBox::draw()
{
    gout << color(0, 0, 0) << move_to(_posx-2, _posy+2) << box(_sizex+9, -_sizey-9);

    if (_focused)
    {
        gout << color(255, 255, 255) << move_to(_posx-2, _posy+2) << box(_sizex+9, -_sizey-9) << move_to(_posx+2, _posy-2) << color(0, 0, 0) << box(_sizex+1, -_sizey-1) << color(255, 255, 255);
    }

    else
    {
        gout << color(255, 255, 255) << move_to(_posx, _posy) << box(_sizex+5, -_sizey-5) << move_to(_posx+2, _posy-2) << color(0, 0, 0) << box(_sizex+1, -_sizey-1) << color(255, 255, 255);
    }

    gout << move_to(_posx+_sizex-10, _posy) << line(0, -_sizey-5);

    gout << move_to(_posx+2, _posy-(_sizey/2)+2) << text(std::to_string(_val));

    _focused = false;
}

void SpinBox::event_handler(event ev)
{
    _focused = true;

    if (ev.keycode == key_up && _val < _maxval) { _val++; }

    else if (ev.keycode == key_down && _val > _minval) { _val--; }

    else if (ev.keycode == key_pgup && _val+10 <= _maxval) { _val += 10; }

    else if (ev.keycode == key_pgdn && _val-10 >= _minval) { _val -= 10; }


}
