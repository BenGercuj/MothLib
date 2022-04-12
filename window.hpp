#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "windowbase.hpp"
#include "spinbox.hpp"

class Window : public WindowBase
{
    SpinBox *sb;

    public:
        Window();
};

#endif // WINDOW_HPP
