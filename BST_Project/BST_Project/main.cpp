#include <iostream>
#include <string>
#include "BST.h"
#include "FileManager.h"

using namespace std;

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
    BST tree;
    int choice, key;
    string filename;

    do {
        menu();
        cout << "Wybor: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Podaj wartosc: ";
            cin >> key;
            tree.insert(key);
            break;

        case 2:
            cout << "Podaj wartosc: ";
            cin >> key;
            tree.remove(key);
            break;

        case 3:
            cout << "Podaj wartosc: ";
            cin >> key;
            tree.showPathTo(key);
            break;

        case 4:
            cout << "Preorder: ";
            tree.preorder(tree.getRoot());
            cout << endl;
            break;

        case 5:
            cout << "Inorder: ";
            tree.inorder(tree.getRoot());
            cout << endl;
            break;

        case 6:
            cout << "Postorder: ";
            tree.postorder(tree.getRoot());
            cout << endl;
            break;

        case 7:
            cout << "Podaj nazwe pliku: ";
            cin >> filename;
            FileManager::saveBinary(filename, tree);
            break;

        case 8:
            cout << "Podaj nazwe pliku: ";
            cin >> filename;
            FileManager::loadBinary(filename, tree);
            break;

        case 9:
            cout << "Podaj nazwe pliku: ";
            cin >> filename;
            FileManager::saveText(filename, tree);
            break;

        case 10:
            cout << "Podaj nazwe pliku: ";
            cin >> filename;
            FileManager::loadText(filename, tree);
            break;

        case 0:
            cout << "Koniec programu.\n";
            break;

        default:
            cout << "Nieprawidlowy wybor.\n";
        }

    } while (choice != 0);

    return 0;
}
