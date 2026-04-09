#include "Harmonogram.h"

Harmonogram::Harmonogram()
{
    czasy = nullptr;
    ilosc = 0;
}

Harmonogram::Harmonogram(const Harmonogram& inny)
{
    ilosc = inny.ilosc;

    if (ilosc > 0)
    {
        czasy = new Czas[ilosc];
        for (int i = 0; i < ilosc; i++)
            czasy[i] = inny.czasy[i];
    }
    else
    {
        czasy = nullptr;
    }
}

Harmonogram& Harmonogram::operator=(const Harmonogram& inny)
{
    if (this == &inny)
        return *this;

    delete[] czasy;

    ilosc = inny.ilosc;

    if (ilosc > 0)
    {
        czasy = new Czas[ilosc];
        for (int i = 0; i < ilosc; i++)
            czasy[i] = inny.czasy[i];
    }
    else
    {
        czasy = nullptr;
    }

    return *this;
}

Harmonogram::~Harmonogram()
{
    delete[] czasy;
}

void Harmonogram::dodajCzas(const Czas& czas)
{
    Czas* nowaTablica = new Czas[ilosc + 1];

    for (int i = 0; i < ilosc; i++)
        nowaTablica[i] = czasy[i];

    nowaTablica[ilosc] = czas;

    delete[] czasy;
    czasy = nowaTablica;
    ilosc++;
}

int Harmonogram::podajIlosc()
{
    return ilosc;
}

Czas& Harmonogram::podajCzas(int indeks)
{
    return czasy[indeks];
}

Czas& Harmonogram::operator[](int indeks)
{
    return czasy[indeks];
}

Czas Harmonogram::sumaCzasow()
{
    Czas suma;
    for (int i = 0; i < ilosc; i++)
        suma += czasy[i];
    return suma;
}

void Harmonogram::wypisz()
{
    for (int i = 0; i < ilosc; i++)
        czasy[i].wypisz();
}

Harmonogram Harmonogram::kopiujDoZakresu(const Czas& zakres) const
{
    Harmonogram nowy;

    for (int i = 0; i < ilosc; i++)
    {
        if (czasy[i] < zakres)
            nowy.dodajCzas(czasy[i]);
    }
    return nowy;
}

bool Harmonogram::operator<(const Harmonogram& other) const
{
    Czas sumaThis = const_cast<Harmonogram*>(this)->sumaCzasow();
    Czas sumaOther = const_cast<Harmonogram&>(other).sumaCzasow();
    return sumaThis < sumaOther;
}

bool Harmonogram::operator==(const Harmonogram& other) const
{
    if (ilosc != other.ilosc)
        return false;
    
    for (int i = 0; i < ilosc; i++)
    {
        if (!(czasy[i] == other.czasy[i]))
            return false;
    }
    return true;
}
