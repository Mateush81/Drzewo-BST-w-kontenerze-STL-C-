#include "FileManager.h"
#include <fstream>
using namespace std;

// Zapis drzewa BST do pliku binarnego
bool FileManager::saveBinary(const string& filename, BST& tree) {
    ofstream out(filename, ios::binary);  // otwieramy plik do zapisu binarnego
    if (!out) return false;               // jeœli pliku nie da siê otworzyæ, zwracamy false
    tree.saveToBinary(out);               // zapisujemy drzewo
    return true;                          // zapis zakoñczony sukcesem
}

// Wczytanie drzewa BST z pliku binarnego
bool FileManager::loadBinary(const string& filename, BST& tree) {
    ifstream in(filename, ios::binary);   // otwieramy plik do odczytu binarnego
    if (!in) return false;                // jeœli pliku nie da siê otworzyæ, zwracamy false
    tree.loadFromBinary(in);              // wczytujemy drzewo
    return true;                          // wczytanie zakoñczone sukcesem
}

// Zapis drzewa BST do pliku tekstowego
bool FileManager::saveText(const string& filename, BST& tree) {
    // metoda saveToText zwraca true/false w zaleznosci od powodzenia
    return tree.saveToText(filename);
}

// Wczytanie drzewa BST z pliku tekstowego
bool FileManager::loadText(const string& filename, BST& tree) {
    // metoda loadFromText zwraca true/false w zaleznosci od powodzenia
    return tree.loadFromText(filename);
}
