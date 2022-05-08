#include "../include/window.hpp"

Window::Window(int winX, int winY) : WindowBase(winX, winY)
{
    //statictext at y=YY/5
    btn = new Button(this, 6+(3*XX/4), YY/5+4, XX/4-12, YY/5, "btn_div", "/", [](){});

    btn = new Button(this, 2, 2*YY/5, XX/4, YY/5, "btn_7", "7", [](){});
    btn = new Button(this, 2, 3*YY/5, XX/4, YY/5, "btn_4", "4", [](){});
    btn = new Button(this, 2, 4*YY/5, XX/4, YY/5, "btn_1", "1", [](){});
    btn = new Button(this, 2, ((5*YY)/5)-3, XX/4, YY/5, "btn_sign", "-/+", [](){});

    btn = new Button(this, 2+(1*XX/4), 2*YY/5, XX/4, YY/5, "btn_8", "8", [](){});
    btn = new Button(this, 2+(1*XX/4), 3*YY/5, XX/4, YY/5, "btn_5", "5", [](){});
    btn = new Button(this, 2+(1*XX/4), 4*YY/5, XX/4, YY/5, "btn_2", "2", [](){});
    btn = new Button(this, 2+(1*XX/4), ((5*YY)/5)-3, XX/4, YY/5, "btn_0", "0", [](){});

    btn = new Button(this, 2+(2*XX/4), 2*YY/5, XX/4, YY/5, "btn_9", "9", [](){});
    btn = new Button(this, 2+(2*XX/4), 3*YY/5, XX/4, YY/5, "btn_6", "6", [](){});
    btn = new Button(this, 2+(2*XX/4), 4*YY/5, XX/4, YY/5, "btn_3", "3", [](){});
    btn = new Button(this, 2+(2*XX/4), ((5*YY)/5)-3, XX/4, YY/5, "btn_del", "DEL", [](){});

    btn = new Button(this, 6+(3*XX/4), 2*YY/5, XX/4-12, YY/5, "btn_multi", "*", [](){});
    btn = new Button(this, 6+(3*XX/4), 3*YY/5, XX/4-12, YY/5, "btn_sub", "-", [](){});
    btn = new Button(this, 6+(3*XX/4), 4*YY/5, XX/4-12, YY/5, "btn_add", "+", [](){});
    btn = new Button(this, 6+(3*XX/4), ((5*YY)/5)-3, XX/4-12, YY/5, "btn_equ", "=", [](){});

//    sb = new SpinBox(this, 250, 200, 50, 25, "spinbox1", 10, 0, 20);
//    sb = new SpinBox(this, 175, 300, 50, 25, "spinbox2", 13, -666, 333);
//    lb = new ListBox(this, 50, 350, 100, 300, "listbox1", {"sanyi", "lajos", "karcsi", "jani"});
//    lb = new ListBox(this, 250, 325, 100, 50, "listbox2", {"hatos", "kettes", "egyes", "tizes"});
//    btn = new Button(this, 250, 50, 50, 25, "button1", "OK", f);

    for (WidgetBase *w: widget_list) { w->draw(); }
}
