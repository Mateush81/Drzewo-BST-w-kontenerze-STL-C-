#pragma once
// Zapobiega wielokrotnemu do³¹czaniu pliku nag³ówkowego (chroni przed b³êdami kompilacji)

#include "BST.h"
#include <string>

// Klasa odpowiedzialna za zapisywanie i wczytywanie drzewa BST z/do plików
class FileManager {

public:

    // Zapisuje drzewo do pliku w formacie BINARNYM.
    // filename – nazwa pliku,
    // tree – drzewo, które ma byæ zapisane.
    // Zwraca true, jeœli zapis siê uda³.
    static bool saveBinary(const std::string& filename, BST& tree);

    // Wczytuje drzewo z pliku binarnego.
    // Zwraca true, jeœli uda³o siê odczytaæ dane.
    static bool loadBinary(const std::string& filename, BST& tree);


    // Zapisuje drzewo do pliku TEKSTOWEGO (np. w postaci liczb w kolejnoœci inorder).
    // Zwraca true, jeœli zapis siê powiód³.
    static bool saveText(const std::string& filename, BST& tree);

    // Wczytuje drzewo z pliku tekstowego.
    // Oczekuje, ¿e plik zawiera liczby, które bêd¹ wstawiane do drzewa.
    // Zwraca true, jeœli wczytanie by³o poprawne.
    static bool loadText(const std::string& filename, BST& tree);
};
