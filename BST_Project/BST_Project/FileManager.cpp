#include "FileManager.h"   // Do³¹czenie nag³ówka FileManager
#include <fstream>         // Do obs³ugi plików
#include <iostream>        // Do wyœwietlania komunikatów
#include <sstream>         // Do przetwarzania linii tekstowych

using namespace std;

// Konstruktor klasy FileManager
FileManager::FileManager() {
    // Obecnie konstruktor nie wykonuje ¿adnych operacji
}

// Wczytywanie liczb z pliku tekstowego do drzewa BST
void FileManager::loadFromText(BST& tree, const std::string& filename) {
    ifstream file(filename); // Otwieramy plik tekstowy do odczytu
    if (!file.is_open()) {
        cerr << "Nie mozna otworzyc pliku: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {        // Czytamy plik linia po linii
        istringstream iss(line);
        int value;
        while (iss >> value) {            // Wczytujemy liczby z jednej linii
            tree.insert(value);           // Wstawiamy ka¿d¹ liczbê do drzewa
        }
    }

    file.close(); // Zamykamy plik po odczycie
}

// Zapis drzewa do pliku binarnego
void FileManager::saveBinary(const BST& tree, const std::string& filename) {
    ofstream file(filename, ios::binary); // Otwieramy plik binarnie do zapisu
    if (!file.is_open()) {
        cerr << "Nie mozna utworzyc pliku: " << filename << endl;
        return;
    }

    // Wywo³anie funkcji BST do zapisu preorder do pliku binarnego
    tree.saveToBinary(file);

    file.close(); // Zamykamy plik
}

// Odczyt drzewa z pliku binarnego
void FileManager::loadBinary(BST& tree, const std::string& filename) {
    ifstream file(filename, ios::binary); // Otwieramy plik binarnie do odczytu
    if (!file.is_open()) {
        cerr << "Nie mozna otworzyc pliku: " << filename << endl;
        return;
    }

    // Wywo³anie funkcji BST do odczytu preorder z pliku binarnego
    tree.loadFromBinary(file);

    file.close(); // Zamykamy plik
}
