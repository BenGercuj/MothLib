#include "graphics.hpp"
#include "widgetbase.hpp"
#include "windowbase.hpp"
#include "window.hpp"

int main()
{
    genv::gout.open(400, 400);

    Window w;
    w.event_loop();

    return 0;
}
