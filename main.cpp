#include "../include/mothlib.hpp"

///HF: Sz�mol�g�p
// Legyen p�ldaprogram a vizsg�hoz, hogy lehessen kopipaszt�zni

const int XX = 200;
const int YY = 200;

int main()
{
    genv::gout.open(XX, YY);

    Window w(XX, YY);
    w.event_loop();

    return 0;
}
