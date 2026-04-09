#include "Czas.h"

Czas::Czas()
{
    godziny = 0;
    minuty = 0;
    sekundy = 0;
}

Czas::Czas(int _godziny, int _minuty, int _sekundy)
{
    godziny = 0;
    minuty = 0;
    sekundy = 0;
    ustawCzas(_godziny, _minuty, _sekundy);
}

Czas::Czas(int _minuty, int _sekundy)
{
    godziny = 0;
    minuty = 0;
    sekundy = 0;
    ustawCzas(_minuty, _sekundy);
}

Czas::Czas(int _sekundy)
{
    godziny = 0;
    minuty = 0;
    sekundy = 0;
    ustawCzas(_sekundy);
}

int Czas::podajSekundy()
{
    return sekundy;
}

int Czas::podajMinuty()
{
    return minuty;
}

int Czas::podajGodziny()
{
    return godziny;
}

void Czas::ustawSekundy(int _sekundy)
{
    minuty += _sekundy / 60;
    sekundy = _sekundy % 60;

    godziny += minuty / 60;
    minuty = minuty % 60;
}

void Czas::ustawMinuty(int _minuty)
{
    godziny += _minuty / 60;
    minuty = _minuty % 60;
}

void Czas::ustawGodziny(int _godziny)
{
    godziny = _godziny;
}

void Czas::ustawCzas(int _godziny, int _minuty, int _sekundy)
{
    godziny = 0;
    minuty = 0;
    sekundy = 0;
    ustawGodziny(_godziny);
    ustawMinuty(_minuty);
    ustawSekundy(_sekundy);
}

void Czas::ustawCzas(int _minuty, int _sekundy)
{
    minuty = 0;
    sekundy = 0;
    ustawMinuty(_minuty);
    ustawSekundy(_sekundy);
}

void Czas::ustawCzas(int _sekundy)
{
    minuty = 0;
    sekundy = 0;
    ustawSekundy(_sekundy);
}

Czas Czas::operator+(const Czas& drugi)
{
    Czas wynik;
    wynik.ustawCzas(
        godziny + drugi.godziny,
        minuty + drugi.minuty,
        sekundy + drugi.sekundy
    );
    return wynik;
}

Czas& Czas::operator+=(const Czas& drugi)
{
    ustawCzas(
        godziny + drugi.godziny,
        minuty + drugi.minuty,
        sekundy + drugi.sekundy
    );
    return *this;
}

bool Czas::operator==(const Czas& drugi)
{
    return (godziny == drugi.godziny) && (minuty == drugi.minuty) && (sekundy == drugi.sekundy);
}

bool Czas::operator<(const Czas& drugi)
{
    if (godziny != drugi.godziny)
        return godziny < drugi.godziny;
    if (minuty != drugi.minuty)
        return minuty < drugi.minuty;
    return sekundy < drugi.sekundy;
}

bool Czas::operator>(const Czas& drugi)
{
    return !(*this < drugi) && !(*this == drugi);
}

bool Czas::operator>=(const Czas& drugi)
{
    return !(*this < drugi);
}

bool Czas::operator<=(const Czas& drugi)
{
    return (*this < drugi) || (*this == drugi);
}

bool Czas::operator!=(const Czas& drugi)
{
    return !(*this == drugi);
}

void Czas::wypisz()
{
    std::cout << "Czas: "
        << godziny << ":"
        << (minuty < 10 ? "0" : "") << minuty << ":"
        << (sekundy < 10 ? "0" : "") << sekundy
        << std::endl;
}
