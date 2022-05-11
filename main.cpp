#include "../include/mothlib.hpp"

const int XX = 419;
const int YY = 419;
int main()
{
    genv::gout.open(XX, YY);

    Window w(XX, YY);
    w.event_loop();

    return 0;
}
