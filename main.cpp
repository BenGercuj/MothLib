#include "../include/mothlib.hpp"

const int XX = 400;
const int YY = 400;

/// Readme
// Egy-egy ablak a Window child-ja legyen, pl AutoKolcsonzo
// Adatszerk tervezésénél legyen bolondbiztos ez a szar
// FONTOS! Vizsga el?tt bugmentesítsd (ha kell írd újra) és írj további widgeteket mer ha nem cumi lesz

int main()
{
    genv::gout.open(XX, YY);

    Window w(XX, YY);
    w.event_loop();

    return 0;
}
