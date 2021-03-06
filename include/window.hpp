#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "windowbase.hpp"
#include "spinbox.hpp"
#include "listbox.hpp"
#include "button.hpp"
#include "statictext.hpp"

class Window : public WindowBase
{
    SpinBox *sb;
    ListBox *lb;
    Button *btn;
    StaticText *st;

    public:
        Window(int winX, int winY);
        void InitGame();
        void StartGame();
        void Draw();
        void Winner(int id);
};

#endif // WINDOW_HPP
