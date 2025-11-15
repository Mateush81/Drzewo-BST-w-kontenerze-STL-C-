#include <iostream>
#include <string>
#include "BST.h"
#include "FileManager.h"

using namespace std;

// Funkcja wyświetlająca menu dostępnych opcji dla użytkownika
void menu() {
    cout << "\n===== MENU =====\n";
    cout << "1) Dodaj element\n";
    cout << "2) Usun element\n";
    cout << "3) Pokaz sciezke do elementu\n";
    cout << "4) Preorder\n";
    cout << "5) Inorder\n";
    cout << "6) Postorder\n";
    cout << "7) Zapisz binarnie\n";
    cout << "8) Wczytaj binarnie\n";
    cout << "9) Zapisz tekstowo\n";
    cout << "10) Wczytaj tekstowo\n";
    cout << "0) Wyjscie\n";
}

int main() {

    BST tree;              // nasze drzewo BST
    int choice, key;       // 'choice' = wybór z menu, 'key' = wartość wpisywana przez użytkownika
    string filename;       // nazwa pliku do zapisu/odczytu

    // Pętla główna wykonuje się do momentu wybrania opcji 0
    do {
        menu();                       // wyświetlenie menu
        cout << "Wybor: ";
        cin >> choice;                // pobranie wyboru od użytkownika

        
        switch (choice) {

        case 1:
            // Dodawanie elementu do drzewa
            cout << "Podaj wartosc: ";
            cin >> key;
            tree.insert(key);         // wstawia element do BST
            break;

        case 2:
            // Usuwanie elementu z drzewa
            cout << "Podaj wartosc: ";
            cin >> key;
            tree.remove(key);         // usuwa element z BST
            break;

        case 3:
            // Pokazanie ścieżki od korzenia do wskazanego elementu
            cout << "Podaj wartosc: ";
            cin >> key;
            tree.showPathTo(key);     // wypisuje trasę szukania
            break;

        case 4:
            // Przejście drzewa w porządku preorder
            cout << "Preorder: ";
            tree.preorder(tree.getRoot());
            cout << endl;
            break;

        case 5:
            // Przejście drzewa in-order (posortowane wypisanie)
            cout << "Inorder: ";
            tree.inorder(tree.getRoot());
            cout << endl;
            break;

        case 6:
            // Przejście drzewa postorder
            cout << "Postorder: ";
            tree.postorder(tree.getRoot());
            cout << endl;
            break;

        case 7:
            // Zapis drzewa do pliku w formacie binarnym
            cout << "Podaj nazwe pliku: ";
            cin >> filename;
            FileManager::saveBinary(filename, tree);
            break;

        case 8:
            // Odczyt drzewa z pliku binarnego
            cout << "Podaj nazwe pliku: ";
            cin >> filename;
            FileManager::loadBinary(filename, tree);
            break;

        case 9:
            // Zapis drzewa do pliku tekstowego
            cout << "Podaj nazwe pliku: ";
            cin >> filename;
            FileManager::saveText(filename, tree);
            break;

        case 10:
            // Odczyt drzewa z pliku tekstowego
            cout << "Podaj nazwe pliku: ";
            cin >> filename;
            FileManager::loadText(filename, tree);
            break;

        case 0:
            // Wyjście z programu
            cout << "Koniec programu.\n";
            break;

        default:
            // Jeśli użytkownik wpisał zły numer
            cout << "Nieprawidlowy wybor.\n";
        }

    } while (choice != 0);  // dopóki nie wybrano opcji wyjścia

    return 0;
}
