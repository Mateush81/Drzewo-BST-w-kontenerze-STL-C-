#include "FileManager.h"
using namespace std;

bool FileManager::saveBinary(const string& filename, BST& tree) {
    ofstream out(filename, ios::binary);
    if (!out) return false;
    tree.saveToBinary(out);
    return true;
}

bool FileManager::loadBinary(const string& filename, BST& tree) {
    ifstream in(filename, ios::binary);
    if (!in) return false;
    tree.loadFromBinary(in);
    return true;
}

bool FileManager::saveText(const string& filename, BST& tree) {
    return tree.saveToText(filename);
}

bool FileManager::loadText(const string& filename, BST& tree) {
    return tree.loadFromText(filename);
}
