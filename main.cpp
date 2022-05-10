#include "../include/mothlib.hpp"

const int XX = 400;
const int YY = 400;

int main()
{
    genv::gout.open(XX, YY);

    Window w(XX, YY);
    w.event_loop();

    return 0;
}
