#pragma once
#include "Czas.h"

class Harmonogram
{
private:
    Czas* czasy;
    int ilosc;

public:
    Harmonogram();
    ~Harmonogram();
    Harmonogram(const Harmonogram& inny);
    Harmonogram& operator=(const Harmonogram& inny);

    void dodajCzas(const Czas& czas);
    int podajIlosc();
    Czas& podajCzas(int indeks);
    Czas& operator[](int indeks);
    Czas sumaCzasow();
    void wypisz();

    bool operator<(const Czas& drugi);
   
bool operator<(const Harmonogram& other) const;
bool operator==(const Harmonogram& other) const;

    Harmonogram kopiujDoZakresu(const Czas& zakres) const;
};
