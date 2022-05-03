// Switch on word wrap and prepare for a spaghetti

#include "listbox.hpp"

using namespace genv;

ListBox::ListBox(WindowBase *mainw, int posx, int posy, int sizex, int sizey, std::string name, std::vector<std::string> values) : WidgetBase(mainw, posx, posy, sizex, sizey, name), _values(values), _showlimit(_sizey/textheight), _showfirst(0), _selected(-1) { }

bool ListBox::is_selected(int mx, int my)
{
    return mx <= _posx+_sizex && mx >= _posx && my >= _posy-_sizey && my <= _posy;
}

void ListBox::draw()
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

    if (_showlimit < _values.size())
    {
        for (int i = 0; i < _showlimit; i++)
        {
            if (_showfirst+i < _values.size())
            {
                gout << move_to(_posx+2, _posy+textheight*i-_sizey+gout.cascent()) << text(_values[i+_showfirst]);

                if (_showfirst+i == _selected)
                {
                    gout << move_to(_posx+2, _posy+textheight*i-_sizey+gout.cdescent()) << color(255, 255, 255) << box(_sizex, textheight) << color(0, 0, 0) << move_to(_posx+2, _posy+textheight*i-_sizey+gout.cascent()) << text(_values[i+_showfirst]) << color(255, 255, 255);
                }
            }
        }
    }

    else
    {
        for (int i = 0; i < _values.size(); i++)
        {
            gout << move_to(_posx+2, _posy+textheight*i-_sizey+gout.cascent()) << text(_values[i]);
            if (i == _selected)
            {
                gout << move_to(_posx+2, _posy+textheight*i-_sizey+gout.cdescent()) << color(255, 255, 255) << box(_sizex, textheight) << color(0, 0, 0) << move_to(_posx+2, _posy+textheight*i-_sizey+gout.cascent()) << text(_values[i]) << color(255, 255, 255);
            }
        }
    }

    _focused = false;
}

void ListBox::event_handler(event ev)
{
    if (_showlimit < _values.size())
    {
        if (ev.button == btn_wheelup && _showfirst < _values.size() && _showfirst < _showlimit) { _showfirst++; }
        else if (ev.button == btn_wheeldown && _showfirst > 0) { _showfirst--; }
    }

    if (ev.button == btn_left && ev.pos_y < textheight*_values.size()+(_posy-_sizey))
    {
        for (int i = textheight*_showlimit; i >= 0; i-=textheight)
        {
            if (ev.pos_y < _posy-i) { _selected = _showlimit-(i/textheight)+_showfirst; i = -1; }
        }
    }

    _focused = true;
}

std::vector<std::string> ListBox::returnval()
{
    std::vector<std::string> val;
    if (_selected != -1) { val = { _values[_selected], "string", _name }; }

    else { val = { "none_selected", "void", _name }; }
    return val;
}
