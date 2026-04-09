#include "Czas.h"
#include "Harmonogram.h"
#include <cstdlib>
#include <ctime>

Harmonogram* utworzHarmonogramyOdUzytkownika(int& liczbaHarmonogramow)
{
    std::cout << "Podaj ilosc harmonogramow do utworzenia: ";
    std::cin >> liczbaHarmonogramow;
    
   
    while (liczbaHarmonogramow <= 0)
    {
        std::cout << "Podaj liczbe wieksza od 0: ";
        std::cin >> liczbaHarmonogramow;
    }
    
    Harmonogram* tablica = new Harmonogram[liczbaHarmonogramow];
    
    srand(time(nullptr));
    
    for (int i = 0; i < liczbaHarmonogramow; i++)
    {
        // Losowa ilość czasów w harmonogramie (od 1 do 5)
        int iloscCzasow = rand() % 5 + 1;
        
        std::cout << "\nTworzenie harmonogramu " << i + 1 << " z " << iloscCzasow << " czasami..." << std::endl;
        
        for (int j = 0; j < iloscCzasow; j++)
        {
           
            int godziny = rand() % 24;
            int minuty = rand() % 60;
            int sekundy = rand() % 60;
            
            Czas czas(godziny, minuty, sekundy);
            tablica[i].dodajCzas(czas);
            
            std::cout << "  Dodano czas: ";
            czas.wypisz();
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

void wypiszWszystkieHarmonogramy(const Harmonogram* tablica, int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        std::cout << "\n========== HARMONOGRAM " << i + 1 << " ==========" << std::endl;
        std::cout << "Ilosc czasow: " << tablica[i].podajIlosc() << std::endl;
        std::cout << "Czasy:" << std::endl;
        tablica[i].wypisz();
        std::cout << "Suma wszystkich czasow: ";
        tablica[i].sumaCzasow().wypisz();
    }
}

// Funkcja porównująca dwa harmonogramy
void porownajHarmonogramy(const Harmonogram& h1, const Harmonogram& h2, const char* nazwa1, const char* nazwa2)
{
    std::cout << "\n--- Porownanie " << nazwa1 << " i " << nazwa2 << " ---" << std::endl;
    
    if (h1 == h2)
    {
        std::cout << "Harmonogramy sa IDENTYCZNE!" << std::endl;
    }
    else if (h1 < h2)
    {
        std::cout << nazwa1 << " jest MNIEJSZY od " << nazwa2 << " (wedlug sumy czasow)" << std::endl;
    }
    else
    {
        std::cout << nazwa1 << " jest WIEKSZY od " << nazwa2 << " (wedlug sumy czasow)" << std::endl;
    }
}

int main()
{
    
    std::cout << "     PROGRAM DO ZARZADZANIA CZASEM     " << std::endl;
  
    
    // ===== ORYGINALNE TESTY (zachowane) =====
    std::cout << "\n===== ORYGINALNE TESTY KLASY CZAS =====" << std::endl;
    
    Czas c1(0, 2, 3);
    Czas c2(4, 5);
    Czas c3(6);

    std::cout << "c1: "; c1.wypisz();
    std::cout << "c2: "; c2.wypisz();
    std::cout << "c3: "; c3.wypisz();

    Czas suma = c2 + c3;
    std::cout << "c2 + c3 = "; suma.wypisz();

    if (c1 == c2)
        std::cout << "c1 jest rowny c2" << std::endl;
    else
        std::cout << "c1 nie jest rowny c2" << std::endl;

    c1 += c2;
    std::cout << "c1 += c2 -> "; c1.wypisz();

    std::cout << std::endl;

  
    std::cout << "===== TEST KLASY HARMONOGRAM =====" << std::endl;
    
    Harmonogram h;
    h.dodajCzas(c1);
    h.dodajCzas(c2);
    h.dodajCzas(c3);

    std::cout << "Ilosc czasow w harmonogramie: " << h.podajIlosc() << std::endl;
    std::cout << "Czasy w harmonogramie:" << std::endl;
    h.wypisz();

    h[0].ustawCzas(0, 2);
    std::cout << "\nPo edycji pierwszego czasu:" << std::endl;
    h.wypisz();

    std::cout << "\nSuma czasow w harmonogramie:" << std::endl;
    h.sumaCzasow().wypisz();


    Harmonogram h2 = h;
    std::cout << "\nKopia harmonogramu:" << std::endl;
    h2.wypisz();


    Harmonogram hZakres;
    Czas zakres(1, 0, 0);
    hZakres = h.kopiujDoZakresu(zakres);
    std::cout << "\nHarmonogram w zakresie < 1:00:00:" << std::endl;
    hZakres.wypisz();

    
   
    std::cout << "     NOWA FUNKCJONALNOSC              " << std::endl;
  
    
    int liczbaHarmonogramow;
    Harmonogram* harmonogramy = utworzHarmonogramyOdUzytkownika(liczbaHarmonogramow);
    
    // Wyświetlenie przed sortowaniem
    std::cout << "\n\n PRZED SORTOWANIEM " << std::endl;
    wypiszWszystkieHarmonogramy(harmonogramy, liczbaHarmonogramow);
    
    // Sortowanie
    std::cout << "\n\n SORTOWANIE HARMONOGRAMOW " << std::endl;
    sortujHarmonogramy(harmonogramy, liczbaHarmonogramow);
    std::cout << "Harmonogramy zostaly posortowane wedlug sumy czasow (od najmniejszego do najwiekszego)!" << std::endl;
    
    std::cout << "\n\n PO SORTOWANIU " << std::endl;
    wypiszWszystkieHarmonogramy(harmonogramy, liczbaHarmonogramow);
    
  
    if (liczbaHarmonogramow >= 2)
    {
        porownajHarmonogramy(harmonogramy[0], harmonogramy[1], "Harmonogram 1", "Harmonogram 2");
    }
    
  
    if (liczbaHarmonogramow >= 1)
    {
        Harmonogram kopia = harmonogramy[0];
        std::cout << "\n--- Test porownania harmonogramu z jego kopia ---" << std::endl;
        porownajHarmonogramy(harmonogramy[0], kopia, "Oryginal", "Kopia");
    }
    

    delete[] harmonogramy;
    
    std::cout << "\n\nNacisnij Enter aby zakonczyc...";
    std::cin.ignore();
    std::cin.get();
    
    return 0;
}
