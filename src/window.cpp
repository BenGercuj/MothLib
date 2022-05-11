#include "../include/window.hpp"

#include <iostream>

Window::Window(int winX, int winY) : WindowBase(winX, winY)
{
    st = new StaticText(this, XX/2-genv::gout.twidth("Amoeba")/2, YY/4, genv::gout.twidth("Amoeba"), genv::gout.cascent()+genv::gout.cdescent(), "st_title", "Amoeba");

    btn = new Button(this, XX/2-XX/4, YY/2, XX/2, genv::gout.cascent()+genv::gout.cdescent()+10, "btn_start", "Start with two players", [this](int p1, int p2, int p3, std::string p4){; InitGame(false);}, -1, -1);

    btn = new Button(this, XX/2-XX/4, YY/2+50, XX/2, genv::gout.cascent()+genv::gout.cdescent()+10, "btn_startalone", "Start with computer", [this](int p1, int p2, int p3, std::string p4){InitGame(true);}, -1, -1);

    btn = new Button(this, XX/2-XX/4, YY/2+100, XX/2, genv::gout.cascent()+genv::gout.cdescent()+10, "btn_exit", "Exit", [](int p1, int p2, int p3, std::string p4){exit(0);}, -1, -1);

    for (WidgetBase *w: widget_list) { w->draw(); }
}

void Window::InitGame(bool withComp)
{
    for (size_t i = 0; i < widget_list.size(); i++)
    {
        delete widget_list[i];
        widget_list[i] = 0;
    }

    widget_list.clear();

    genv::gout << genv::move_to(1, YY-1) << genv::color(0, 0, 0) << genv::box_to(XX-1, 0) << genv::color(255, 255, 255) << genv::refresh;

    StartGame(withComp);
}

void Window::StartGame(bool withComp)
{
    std::vector<std::vector<int>> *field = &_field;

    for (int i = 0; i < XX/20; i++)
    {
        for (int j = 0; j < YY/20; j++)
        {
            std::string name = "btn_";
            name += std::to_string(i) + "_" + std::to_string(j);

            if (i == XX/20-1 && j != YY/20-1) { btn = new Button(this, (i*XX/20), (j*YY/20)+YY/20+2, XX/20-4, YY/20, name, "", [this](int posx, int posy, int &whowasit, std::string &text){if (!_field[posx][posy]) {_field[posx][posy] = _playerid; whowasit = _playerid; if (_playerid == 1) { text = "X";} else if (_playerid == -1) { text = "O"; } _playerid *= -1; }}, i, j); }
            else if (j == YY/20-1 && i != XX/20-1) { btn = new Button(this, (i*XX/20), (j*YY/20)+YY/20+2, XX/20, YY/20-1, name, "", [this](int posx, int posy, int &whowasit, std::string &text){if (!_field[posx][posy]) {_field[posx][posy] = _playerid; whowasit = _playerid; if (_playerid == 1) { text = "X";} else if (_playerid == -1) { text = "O"; } _playerid *= -1; }}, i, j); }
            else if (j == YY/20-1 && i == XX/20-1) { btn = new Button(this, (i*XX/20), (j*YY/20)+YY/20+2, XX/20-4, YY/20-4, name, "", [this](int posx, int posy, int &whowasit, std::string &text){if (!_field[posx][posy]) { _field[posx][posy] = _playerid; whowasit = _playerid; if (_playerid == 1) { text = "X";} else if (_playerid == -1) { text = "O"; } _playerid *= -1; }}, i, j); }
            else { btn = new Button(this, (i*XX/20), (j*YY/20)+YY/20+2, XX/20, YY/20, name, "", [this](int posx, int posy, int &whowasit, std::string &text){if (!_field[posx][posy]) {_field[posx][posy] = _playerid; whowasit = _playerid; if (_playerid == 1) { text = "X";} else if (_playerid == -1) { text = "O"; } _playerid *= -1; }}, i, j); }
        }
    }
}

void Window::Draw()
{

}

void Window::Winner(int id)
{

}
