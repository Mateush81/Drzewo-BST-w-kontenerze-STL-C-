#pragma once
#include "BST.h"
#include <string>

class FileManager {

public:
    static bool saveBinary(const std::string& filename, BST& tree);
    static bool loadBinary(const std::string& filename, BST& tree);

    static bool saveText(const std::string& filename, BST& tree);
    static bool loadText(const std::string& filename, BST& tree);
};
