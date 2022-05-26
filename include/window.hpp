#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "windowbase.hpp"
#include "spinbox.hpp"
#include "listbox.hpp"
#include "button.hpp"
#include "statictext.hpp"
#include "textctrl.hpp"

class Window : public WindowBase
{
    SpinBox *sb;
    ListBox *lb;
    Button *btn;
    StaticText *st;
    TextCtrl *tctrl;

    public:
        Window(int winX, int winY);
};

#endif // WINDOW_HPP
