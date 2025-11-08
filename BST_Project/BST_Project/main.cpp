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
    cout << "3) Szukaj drogi do elementu" << endl;
    cout << "4) Min/Max" << endl;
    cout << "5) Preorder" << endl;
    cout << "6) Inorder" << endl;
    cout << "7) Postorder" << endl;
    cout << "8) Wyjscie" << endl;
    cout << "================" << endl;
}

int main() {
    BST tree;           // Tworzymy obiekt drzewa BST
    //FileManager fm;     // Tworzymy obiekt FileManager do obsługi plików
    int choice,key;         // Zmienna do przechowywania wyboru użytkownika

    do {
        printMenu();    // Wyświetlamy menu
        cout << "Wybierz opcje: ";
        cin >> choice;

        switch (choice) {
        case 1: { // Dodawanie elementu
            cout << "Podaj wartosc do dodania: ";
            cin >> key;
            tree.insert(key); // Wywołanie metody BST
			tree.display(); // Wyświetlenie drzewa po dodaniu
            break;
        }
        case 2: { // Usuwanie elementu
            cout << "Podaj wartosc do usuniecia: ";
            cin >> key;
            tree.remove(key); // Wywołanie metody BST
            tree.display();
            break;
        }
        case 3: { // Szukanie drogi do elementu
            cout << "Podaj wartosc do wyszukania: ";
            cin >> key;
            tree.search(key); // Wywołanie metody BST
            break;
        }
        case 4: { 
            if (tree.getRoot()) {
                cout << "Min:" << tree.minNode(tree.getRoot())->key
                    << ", Max:" << tree.maxNode(tree.getRoot())->key << endl;
            }
			else cout << "Drzewo jest puste." << endl;
            break; 
        }
        case 5: { 
			cout << "Preorder: "; tree.preorder(tree.getRoot()); cout << endl;
            break;
        }
        case 6: { 
			cout << "Inorder: "; tree.inorder(tree.getRoot()); cout << endl;
            break;
        }
        case 7: { 
			cout << "Postorder: "; tree.postorder(tree.getRoot()); cout << endl;
            break;
        }
        case 0: { // Odczyt binarny
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