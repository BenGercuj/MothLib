#include "../include/window.hpp"

#include <iostream>

Window::Window(int winX, int winY) : WindowBase(winX, winY)
{
    int *getval = &_calcvalue;

    st = new StaticText(this, 2, YY/5+4, 3*XX/4, YY/5, "st_result", "hihi I want to die", getval);
    btn = new Button(this, 6+(3*XX/4), YY/5+4, XX/4-12, YY/5, "btn_div", "/", [this](){});
    btn = new Button(this, 2, 2*YY/5, XX/4, YY/5, "btn_7", "7", [this](){_calcvalue = (_calcvalue * 10) + 7;});
    btn = new Button(this, 2, 3*YY/5, XX/4, YY/5, "btn_4", "4", [this](){_calcvalue = (_calcvalue * 10) + 4;});
    btn = new Button(this, 2, 4*YY/5, XX/4, YY/5, "btn_1", "1", [this](){_calcvalue = (_calcvalue * 10) + 1;});
    btn = new Button(this, 2, ((5*YY)/5)-3, XX/4, YY/5, "btn_sign", "-/+", [this](){_calcvalue *= -1;});

    btn = new Button(this, 2+(1*XX/4), 2*YY/5, XX/4, YY/5, "btn_8", "8", [this](){_calcvalue = (_calcvalue * 10) + 8;});
    btn = new Button(this, 2+(1*XX/4), 3*YY/5, XX/4, YY/5, "btn_5", "5", [this](){_calcvalue = (_calcvalue * 10) + 5;});
    btn = new Button(this, 2+(1*XX/4), 4*YY/5, XX/4, YY/5, "btn_2", "2", [this](){_calcvalue = (_calcvalue * 10) + 2;});
    btn = new Button(this, 2+(1*XX/4), ((5*YY)/5)-3, XX/4, YY/5, "btn_0", "0", [this](){_calcvalue *= 10;});

    btn = new Button(this, 2+(2*XX/4), 2*YY/5, XX/4, YY/5, "btn_9", "9", [this](){_calcvalue = (_calcvalue * 10) + 9;});
    btn = new Button(this, 2+(2*XX/4), 3*YY/5, XX/4, YY/5, "btn_6", "6", [this](){_calcvalue = (_calcvalue * 10) + 6;});
    btn = new Button(this, 2+(2*XX/4), 4*YY/5, XX/4, YY/5, "btn_3", "3", [this](){_calcvalue = (_calcvalue * 10) + 3;});
    btn = new Button(this, 2+(2*XX/4), ((5*YY)/5)-3, XX/4, YY/5, "btn_del", "DEL", [this](){_calcvalue /= 10;});

    btn = new Button(this, 6+(3*XX/4), 2*YY/5, XX/4-12, YY/5, "btn_multi", "*", [this](){});
    btn = new Button(this, 6+(3*XX/4), 3*YY/5, XX/4-12, YY/5, "btn_sub", "-", [this](){});
    btn = new Button(this, 6+(3*XX/4), 4*YY/5, XX/4-12, YY/5, "btn_add", "+", [this](){});
    btn = new Button(this, 6+(3*XX/4), ((5*YY)/5)-3, XX/4-12, YY/5, "btn_equ", "=", [this](){});

//    sb = new SpinBox(this, 250, 200, 50, 25, "spinbox1", 10, 0, 20);
//    sb = new SpinBox(this, 175, 300, 50, 25, "spinbox2", 13, -666, 333);
//    lb = new ListBox(this, 50, 350, 100, 300, "listbox1", {"sanyi", "lajos", "karcsi", "jani"});
//    lb = new ListBox(this, 250, 325, 100, 50, "listbox2", {"hatos", "kettes", "egyes", "tizes"});
//    btn = new Button(this, 250, 50, 50, 25, "button1", "OK", f);

    for (WidgetBase *w: widget_list) { w->draw(); }
}
