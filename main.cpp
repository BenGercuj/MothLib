#include "../include/mothlib.hpp"

const int XX = 400;
const int YY = 400;

/// Readme
// Egy-egy ablak a Window child-ja legyen, pl AutoKolcsonzo
// Adatszerk tervez�s�n�l legyen bolondbiztos ez a szar
// FONTOS! Vizsga el?tt bugmentes�tsd (ha kell �rd �jra) �s �rj tov�bbi widgeteket mer ha nem cumi lesz

int main()
{
    genv::gout.open(XX, YY);

    Window w(XX, YY);
    w.event_loop();

    return 0;
}
