#pragma once
#include <iostream>

class Czas
{
private:
    int sekundy;
    int minuty;
    int godziny;

    void ustawSekundy(int _sekundy);
    void ustawMinuty(int _minuty);
    void ustawGodziny(int _godziny);

public:
    Czas();
    Czas(int _godziny, int _minuty, int _sekundy);
    Czas(int _minuty, int _sekundy);
    Czas(int _sekundy);

    int podajSekundy();
    int podajMinuty();
    int podajGodziny();

    void ustawCzas(int _godziny, int _minuty, int _sekundy);
    void ustawCzas(int _minuty, int _sekundy);
    void ustawCzas(int _sekundy);

    Czas operator+(const Czas& drugi);
    Czas& operator+=(const Czas& drugi);

    bool operator==(const Czas& drugi);
    bool operator<(const Czas& drugi);
    bool operator>(const Czas& drugi);
    bool operator>=(const Czas& drugi);
    bool operator<=(const Czas& drugi);
    bool operator!=(const Czas& drugi);

    void wypisz();
};
