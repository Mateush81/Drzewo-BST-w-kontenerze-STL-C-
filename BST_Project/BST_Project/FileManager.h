#ifndef FILEMANAGER_H  // Jeœli plik nie by³ wczeœniej do³¹czony
#define FILEMANAGER_H  // Definiuje symbol FILEMANAGER_H, aby chroniæ przed wielokrotnym do³¹czeniem

#include <string>     // Do u¿ycia typu std::string dla nazw plików
#include "BST.h"      // Do wspó³pracy z klas¹ BST (wstawianie i odczytywanie elementów)

/// @brief Klasa FileManager
/// Odpowiada za operacje na plikach dla drzewa BST.
/// Pozwala wczytaæ dane z pliku tekstowego, zapisaæ drzewo do pliku binarnego
/// i odczytaæ drzewo z pliku binarnego.
class FileManager {
public:

    /// @brief Konstruktor klasy FileManager
    /// Tworzy obiekt FileManager. Nie wykonuje dodatkowych operacji.
    FileManager();

    /// @brief Zapisuje drzewo BST do pliku binarnego
    /// @param tree Drzewo, które ma byæ zapisane
    /// @param filename Nazwa pliku binarnego
    void saveBinary(const BST& tree, const std::string& filename);

    /// @brief Odczytuje drzewo BST z pliku binarnego
    /// @param tree Drzewo, które ma zostaæ wype³nione
    /// @param filename Nazwa pliku binarnego
    void loadBinary(BST& tree, const std::string& filename);

    /// @brief Wczytuje liczby z pliku tekstowego i dodaje je do drzewa BST
    /// @param tree Drzewo, które ma zostaæ wype³nione
    /// @param filename Nazwa pliku tekstowego
    void loadFromText(BST& tree, const std::string& filename);
};

#endif // FILEMANAGER_H
