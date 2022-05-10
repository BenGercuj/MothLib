#include "../include/mothlib.hpp"

///HF: Számológép
// Legyen példaprogram a vizsgához, hogy lehessen kopipasztázni

const int XX = 200;
const int YY = 200;

int main()
{
    genv::gout.open(XX, YY);

    Window w(XX, YY);
    w.event_loop();

    return 0;
}
