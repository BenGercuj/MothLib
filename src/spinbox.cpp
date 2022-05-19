#include "../include/spinbox.hpp"

using namespace genv;

SpinBox::SpinBox(WindowBase *mainw, int posx, int posy, int sizex, int sizey, std::string name, int val, int minval, int maxval) : WidgetBase(mainw, posx, posy, sizex, sizey, name), _val(val), _minval(minval), _maxval(maxval), _changed(false) { }

bool SpinBox::is_selected(int mx, int my)
{
    return mx <= _posx+_sizex && mx >= _posx && my >= _posy-_sizey && my <= _posy;
}

int SpinBox::selected_spinner(int mx, int my)
{ // 0: none, 1: lower, 2: upper

    // Hitbox debug
//    gout << color(0, 100, 0) << move_to(_posx+_sizex-10, _posy-(_sizey/2)) << box_to(_posx+_sizex+2, _posy);
//    gout << color(100, 0, 0) << move_to(_posx+_sizex-10, _posy-(_sizey/2)-4) << box_to(_posx+_sizex+2, _posy-_sizey-2);

    if (mx >= _posx+_sizex-10 && mx <= _posx+_sizex+2)
    {
        if (my <= _posy && my >= _posy-(_sizey/2))
        {
            return 1;
        }

        else if (my >= _posy-_sizey-2 && my <= _posy-(_sizey/2)-4)
        {
            return 2;
        }
    }

    return 0;
}

void SpinBox::draw()
{ // Creator's note: I genuinely hope I will /not/ have to write GUI code like this in the upcoming.. I dunno, SIXTY YEARS
    gout << color(0, 0, 0) << move_to(_posx-2, _posy+2) << box(_sizex+9, -_sizey-9);

    if (_focused)
    {
        gout << color(255, 255, 255) << move_to(_posx-2, _posy+2) << box(_sizex+9, -_sizey-9) << move_to(_posx+2, _posy-2) << color(0, 0, 0) << box(_sizex+1, -_sizey-1) << color(255, 255, 255);
    }

    else
    {
        gout << color(255, 255, 255) << move_to(_posx, _posy) << box(_sizex+5, -_sizey-5) << move_to(_posx+2, _posy-2) << color(0, 0, 0) << box(_sizex+1, -_sizey-1) << color(255, 255, 255);
    }

    // Horizontal spinner separator
    gout << move_to(_posx+_sizex-10, _posy) << line(0, -_sizey-5);

    // Bottom spinner arrow
    gout << move_to(_posx+_sizex-10, _posy-(_sizey/2)) << line_to(_posx+_sizex-3, _posy-1) << line_to(_posx+_sizex+2, _posy-(_sizey/2)+1);

    // Upper spinner arrow
    gout << move_to(_posx+_sizex-10, _posy-(_sizey/2)) << line_to(_posx+_sizex-3, _posy-_sizey-2) << line_to(_posx+_sizex+2, _posy-(_sizey/2)-3);

    // Vertical spinner separator
    gout << move_to(_posx+_sizex-10, _posy-(_sizey/2)-2) << line_to(_posx+_sizex+3, _posy-(_sizey/2)-2);

    gout << move_to(_posx+2, _posy-(_sizey/2)+2) << text(std::to_string(_val));

    _focused = false;
}

void SpinBox::event_handler(event ev)
{
    _focused = true;

    if (ev.keycode == key_up && _val < _maxval) { _val++; _changed = true; }

    else if (ev.keycode == key_down && _val > _minval) { _val--; _changed = true; }

    else if (ev.keycode == key_pgup && _val+10 <= _maxval) { _val += 10; _changed = true; }

    else if (ev.keycode == key_pgdn && _val-10 >= _minval) { _val -= 10; _changed = true; }

    else if (ev.button == btn_left)
    {
        if (selected_spinner(ev.pos_x, ev.pos_y) == 1 && _val > _minval) { _val--; _changed = true; }

        else if (selected_spinner(ev.pos_x, ev.pos_y) == 2 && _val < _maxval) { _val++; _changed = true; }
    }

}

std::vector<std::string> SpinBox::returnval()
{
    std::vector<std::string> val;
    if (_changed)
    {
        val = { std::to_string(_val), "int", _name };
        _changed = false;
    }

    else { val = { "none_selected", "void", _name }; }

    return val;
}
