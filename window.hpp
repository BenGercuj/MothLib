#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "windowbase.hpp"
#include "spinbox.hpp"
#include "listbox.hpp"

class Window : public WindowBase
{
    SpinBox *sb;
    ListBox *lb;

    public:
        Window();
};

#endif // WINDOW_HPP
