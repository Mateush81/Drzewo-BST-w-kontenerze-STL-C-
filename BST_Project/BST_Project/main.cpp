#include <iostream>       // Biblioteka do wejścia/wyjścia
#include <string>         // Biblioteka do używania typu std::string
#include "BST.h"          // Klasa BST – logika drzewa
#include "FileManager.h"  // Klasa FileManager – obsługa plików

using namespace std;

// Funkcja wyświetlająca menu programu
void printMenu() {
    cout << "\n===== MENU =====" << endl;
    cout << "1) Dodaj element" << endl;
    cout << "2) Usun element" << endl;
    cout << "3) Usun cale drzewo" << endl;
    cout << "4) Szukaj drogi do elementu" << endl;
    cout << "5) Wyswietl drzewo" << endl;
    cout << "6) Zapis drzewa do pliku tekstowego" << endl;
    cout << "7) Zapis drzewa binarnie" << endl;
    cout << "8) Odczyt drzewa binarnie" << endl;
    cout << "9) Wczytaj plik tekstowy z liczbami" << endl;
    cout << "0) Wyjscie" << endl;
    cout << "================" << endl;
}

int main() {
    BST tree;           // Tworzymy obiekt drzewa BST
    FileManager fm;     // Tworzymy obiekt FileManager do obsługi plików
    int choice;         // Zmienna do przechowywania wyboru użytkownika

    do {
        printMenu();    // Wyświetlamy menu
        cout << "Wybierz opcje: ";
        cin >> choice;

        switch (choice) {
        case 1: { // Dodawanie elementu
            int value;
            cout << "Podaj wartosc do dodania: ";
            cin >> value;
            tree.insert(value); // Wywołanie metody BST
            break;
        }
        case 2: { // Usuwanie elementu
            int value;
            cout << "Podaj wartosc do usuniecia: ";
            cin >> value;
            tree.remove(value); // Wywołanie metody BST
            break;
        }
        case 3: { // Usuwanie całego drzewa
            tree.clear(); // Czyszczenie drzewa
            cout << "Drzewo zostalo usuniete." << endl;
            break;
        }
        case 4: { // Szukanie drogi do elementu
            int value;
            cout << "Podaj wartosc do wyszukania: ";
            cin >> value;
            tree.findPath(value); // Wywołanie metody BST
            break;
        }
        case 5: { // Wyświetlanie drzewa
            int method;
            cout << "Wybierz metode wyswietlania (1: preorder, 2: inorder, 3: postorder): ";
            cin >> method;
            tree.display(method); // Wywołanie metody BST
            break;
        }
        case 6: { // Zapis do pliku tekstowego
            string filename;
            cout << "Podaj nazwe pliku do zapisu: ";
            cin >> filename;
            tree.saveToTextFile(filename); // Metoda BST zapisująca do pliku tekstowego
            cout << "Drzewo zapisane do pliku: " << filename << endl;
            break;
        }
        case 7: { // Zapis binarny
            string filename;
            cout << "Podaj nazwe pliku binarnego do zapisu: ";
            cin >> filename;
            fm.saveBinary(tree, filename); // Wywołanie FileManager
            cout << "Drzewo zapisane binarnie do pliku: " << filename << endl;
            break;
        }
        case 8: { // Odczyt binarny
            string filename;
            cout << "Podaj nazwe pliku binarnego do odczytu: ";
            cin >> filename;
            fm.loadBinary(tree, filename); // Wywołanie FileManager
            cout << "Drzewo wczytane z pliku binarnego: " << filename << endl;
            break;
        }
        case 9: { // Wczytanie pliku tekstowego
            string filename;
            cout << "Podaj nazwe pliku tekstowego do wczytania: ";
            cin >> filename;
            fm.loadFromText(tree, filename); // Wywołanie FileManager
            cout << "Drzewo wczytane z pliku tekstowego: " << filename << endl;
            break;
        }
        case 0: { // Wyjście
            cout << "Koniec programu." << endl;
            break;
        }
        default: { // Niepoprawny wybór
            cout << "Nieprawidlowy wybor! Sprobuj ponownie." << endl;
            break;
        }
        }

    } while (choice != 0); // Pętla działa dopóki użytkownik nie wybierze opcji 0

    return 0; // Zakończenie programu
}



hejka, usuń to