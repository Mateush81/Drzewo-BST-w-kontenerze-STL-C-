#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include "BST.h"

class FileManager {
public:
    // Konstruktor klasy FileManager
    FileManager();

    // Zapis drzewa BST do pliku binarnego
    void saveBinary(const BST& tree, const std::string& filename);

    // Odczyt drzewa BST z pliku binarnego
    void loadBinary(BST& tree, const std::string& filename);

    // Wczytanie liczb z pliku tekstowego i dodanie ich do drzewa BST
    void loadFromText(BST& tree, const std::string& filename);
};

#endif
