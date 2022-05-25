#include "../include/window.hpp"

#include <iostream> // debug, delete after done

Window::Window(int winX, int winY) : WindowBase(winX, winY)
{
    btn = new Button(this, 100, 100, 100, 50, "btn_demo", "DEMO", [](){ std::cout << "demo pressed\n"; }); // seems to work
    lb = new ListBox(this, 50, 250, 100, 100, "lb_demo", { "egyeske", "ketteske", "harmaska", "hihi", "lajos", "lajoska" });
    sb = new SpinBox(this, 175, 200, 50, 50, "sb_demo", 2, -4, -1);
    st = new StaticText(this, 50, 300, "st_demo", "lmao");
}
