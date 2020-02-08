// Zadanie 4.3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
using namespace std;

const int rozmiar_tablicy = 500;
int tablica[rozmiar_tablicy];
int liczba_wczytanych_liczb = 0;

//int najwiekszydz(int a, int b) {
//    if (b == 0)
//        return a;
//    else {
//        int c = a % b;
//        return najwiekszydz(b, c);
//    }
//}

int najwiekszydz(int a, int b) {
    int a1, b1;
    a1 = a;
    b1 = b;
    while(a1 != b1) {
        if (a1 > b1)
            a1 = a1 - b1;
        else if (b1 > a1)
            b1 = b1 - a1;       
    }
    return a1;      

}

//int najwiekszydz(int a, int b) {
//	int a1, b1;
//	int c;
//	a1 = a;
//	b1 = b;
//	while (b1 != 0) {
//		c = a1 % b1;
//		a1 = b1;
//		b1 = c;
//	}
//	return a1;
//}


//int main(int argc, char *argv[])
//{
//    int liczba;
//    int liczba_poprzednia;
//    int pierw = 0;
//    int dlugciag = 0;
//    int nwdw = 1;
//    int max_pierw = 0;
//    int max_dlugciag = 0;
//    int max_nwdw = 1;
//
//    while (!cin.eof()) {
//        
//        cin >> liczba;
//        if (dlugciag == 0) {
//            nwdw = liczba;
//            pierw = liczba;
//        }
//        else {
//            int tmp_nwd;
//            tmp_nwd = najwiekszydz(nwdw, liczba);
//
//            if (tmp_nwd > 1)
//                nwdw = tmp_nwd;
//            else {
//                if (dlugciag > max_dlugciag) {
//                    max_dlugciag = dlugciag;
//                    max_pierw = pierw;
//                    max_nwdw = nwdw;
//                }
//
//                tmp_nwd = najwiekszydz(liczba, liczba_poprzednia);
//                if (tmp_nwd == 1) {
//                    pierw = liczba;
//                    nwdw = liczba;
//                    dlugciag = 0;
//
//                }
//                else {
//                    pierw = liczba_poprzednia;
//                    nwdw = tmp_nwd;
//                    dlugciag = 1;
//
//                }
//
//
//            }
//        }
//        liczba_poprzednia = liczba;
//        dlugciag++;
//        
//         
//
//        //cout << line;
//    }
//    cout << max_pierw << " " << max_dlugciag << " " << max_nwdw << endl;
//
//       
//}

int main() {

	int liczba;
	int pierw = 0;
	int dlugciag = 0;
	int nwdw = 1;
	int max_pierw = 0;
	int max_dlugciag = 0;
	int max_nwdw = 1;
	while (!cin.eof() && liczba_wczytanych_liczb < rozmiar_tablicy) {
		cin >> tablica[liczba_wczytanych_liczb];
		liczba_wczytanych_liczb = liczba_wczytanych_liczb + 1;
	}
	for (int i = 0; i < liczba_wczytanych_liczb; i++) {
		int liczba = tablica[i];
		if (i == 0) {
			nwdw = liczba;
			pierw = liczba;
		}
		else {
			int tmp_nwd;
			tmp_nwd = najwiekszydz(liczba, nwdw);
			if (tmp_nwd == 1) {
				if (dlugciag > max_dlugciag) {
					max_dlugciag = dlugciag;
					max_nwdw = nwdw;
					max_pierw = pierw;
				}
				tmp_nwd = najwiekszydz(liczba, tablica[i - 1]);
				if (tmp_nwd == 1) {
					pierw = liczba;
					nwdw = liczba;
					dlugciag = 0;

				}
				else {
					pierw = tablica[i - 1];
					nwdw = tmp_nwd;
					dlugciag = 1;


				}


			}
			dlugciag++;

		}
	}
	cout << max_pierw << " " << max_dlugciag << " " << max_nwdw << endl;
}


// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
