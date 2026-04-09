
#include "Czas.h"
#include "Harmonogram.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

Harmonogram* utworzTabliceHarmonogramow(int liczbaHarmonogramow)
{
    Harmonogram* tablica = new Harmonogram[liczbaHarmonogramow];
    
    srand(time(nullptr));
    
    for (int i = 0; i < liczbaHarmonogramow; i++)
    {
       
        int liczbaCzasow = rand() % 5 + 1;
        
        for (int j = 0; j < liczbaCzasow; j++)
        {
           
            int godziny = rand() % 24;
            int minuty = rand() % 60;
            int sekundy = rand() % 60;
            
            Czas czas(godziny, minuty, sekundy);
            tablica[i].dodajCzas(czas);
        }
    }
    
    return tablica;
}


void sortujHarmonogramy(Harmonogram* tablica, int rozmiar)
{
    for (int i = 0; i < rozmiar - 1; i++)
    {
        for (int j = 0; j < rozmiar - i - 1; j++)
        {
            if (tablica[j + 1] < tablica[j])
            {
                Harmonogram temp = tablica[j];
                tablica[j] = tablica[j + 1];
                tablica[j + 1] = temp;
            }
        }
    }
}

void porownajHarmonogramy(const Harmonogram& h1, const Harmonogram& h2, const char* nazwa1, const char* nazwa2)
{
    std::cout << "\n--- Porownanie " << nazwa1 << " i " << nazwa2 << " ---" << std::endl;
    
    if (h1 == h2)
    {
        std::cout << "Harmonogramy sa identyczne!" << std::endl;
    }
    else if (h1 < h2)
    {
        std::cout << nazwa1 << " jest mniejszy od " << nazwa2 << std::endl;
    }
    else
    {
        std::cout << nazwa1 << " jest wiekszy od " << nazwa2 << std::endl;
    }
}

void wypiszWszystkieHarmonogramy(Harmonogram* tablica, int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        std::cout << "\nHarmonogram " << i + 1 << " (ilosc czasow: " 
                  << tablica[i].podajIlosc() << "):" << std::endl;
        tablica[i].wypisz();
        std::cout << "Suma czasow: ";
        tablica[i].sumaCzasow().wypisz();
    }
}

int main()
{
    
    std::cout << " oryginalny harmonogram" << std::endl;
    
    Czas c1(0, 2, 3);
    Czas c2(4, 5);
    Czas c3(6);

    c1.wypisz();
    c2.wypisz();
    c3.wypisz();

    Czas suma = c2 + c3;
    suma.wypisz();

    if (c1 == c2)
        std::cout << "c1 jest rowny c2" << std::endl;
    else
        std::cout << "c1 nie jest rowny c2" << std::endl;

    c1 += c2;
    c1.wypisz();

    std::cout << std::endl;

    Harmonogram h;
    h.dodajCzas(c1);
    h.dodajCzas(c2);
    h.dodajCzas(c3);

    std::cout << "Ilosc czasow: " << h.podajIlosc() << std::endl;
    h.wypisz();

    std::cout << std::endl;

    h[0].ustawCzas(0, 2);
    std::cout << "Po edycji pierwszego czasu:" << std::endl;
    h.wypisz();

    std::cout << "Suma czasow:" << std::endl;
    h.sumaCzasow().wypisz();

    std::cout << std::endl;

    Harmonogram h2 = h;
    std::cout << "Kopia harmonogramu :" << std::endl;
    h2.wypisz();

    std::cout << std::endl;

    Harmonogram h3;
    h3 = h;
    std::cout << "Kopia harmonogramu :" << std::endl;
    h3.wypisz();

    std::cout << std::endl;

    Harmonogram hZakres;
    Czas zakres(1, 0, 0);
    hZakres = h.kopiujDoZakresu(zakres);
    std::cout << "Harmonogram w zakresie 1:00:00:" << std::endl;
    hZakres.wypisz();

    std::cout << "\n\nobrona" << std::endl;
    
  
    int liczbaHarmonogramow = 5;
    std::cout << "Tworzenie tablicy " << liczbaHarmonogramow << " harmonogramow z losowymi czasami..." << std::endl;
    
    Harmonogram* harmonogramy = utworzTabliceHarmonogramow(liczbaHarmonogramow);
    
    std::cout << "\n--- HARMONOGRAMY PRZED SORTOWANIEM ---" << std::endl;
    wypiszWszystkieHarmonogramy(harmonogramy, liczbaHarmonogramow);
    
    std::cout << "\n--- SORTOWANIE HARMONOGRAMOW ---" << std::endl;
    sortujHarmonogramy(harmonogramy, liczbaHarmonogramow);
    
    std::cout << "\n--- HARMONOGRAMY PO SORTOWANIU (wedlug sumy czasow) ---" << std::endl;
    wypiszWszystkieHarmonogramy(harmonogramy, liczbaHarmonogramow);
    
    std::cout << "\n--- POROWNANIE HARMONOGRAMOW ---" << std::endl;
    porownajHarmonogramy(harmonogramy[0], harmonogramy[1], "Harmonogram 1", "Harmonogram 2");
    porownajHarmonogramy(harmonogramy[2], harmonogramy[3], "Harmonogram 3", "Harmonogram 4");
    
    Harmonogram kopiaPierwszego = harmonogramy[0];
    std::cout << "\nTest porownania harmonogramu z jego kopia:" << std::endl;
    porownajHarmonogramy(harmonogramy[0], kopiaPierwszego, "Oryginal", "Kopia");
   
    delete[] harmonogramy;
    
    std::cout << "\nNacisnij Enter aby zakonczyc";
    std::cin.get();
    return 0;
}
