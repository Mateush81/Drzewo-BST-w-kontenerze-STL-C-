#pragma once
#include <iostream>
#include <fstream>
#include <string>

/*
Dzia³anie BST (Binary Search Tree):
„Lewe < rodzic < prawe”
Wszystko po lewej stronie ma wartoœci mniejsze od rodzica,
wszystko po prawej stronie ma wartoœci wiêksze od rodzica.
*/

// Struktura jednego wêz³a BST
struct BSTNode {
    int key;                  // wartoœæ w wêŸle
    BSTNode* left;            // lewe dziecko
    BSTNode* right;           // prawe dziecko
    BSTNode* parent;          // wskaŸnik na rodzica

    BSTNode(int k) : key(k), left(nullptr), right(nullptr), parent(nullptr) {}
};

class BST {

private:
    BSTNode* root;      // korzeñ drzewa
    int count;          // liczba wêz³ów

    void destroy(BSTNode* x);              // usuwa ca³e drzewo
    BSTNode* removeNode(BSTNode* x);       // usuwa jeden wêze³

    void writeInorder(BSTNode* x, std::ofstream& out) const; // do zapisu tekstowego
    void loadTextInsert(std::ifstream& in);                  // do odczytu tekstowego

public:
    BST();
    ~BST();

    bool insert(int key);     // dodawanie elementu
    void remove(int key);     // usuwanie elementu
    BSTNode* search(int key); // szukanie elementu

    // min / max
    BSTNode* minNode(BSTNode* x);
    BSTNode* maxNode(BSTNode* x);

    // poprzednik / nastêpnik
    BSTNode* pred(BSTNode* x);
    BSTNode* succ(BSTNode* x);

    // przejœcia drzewa
    void preorder(BSTNode* x);
    void inorder(BSTNode* x);
    void postorder(BSTNode* x);

    // pomocnicze
    void display();                // wyœwietlanie inorder
    BSTNode* getRoot() { return root; }

    // NOWE — wymagane w zadaniu:
    void showPathTo(int key);      // wypisuje œcie¿kê do elementu
    bool saveToText(const std::string& filename) const;
    bool loadFromText(const std::string& filename);

    // zapis / odczyt binarny
    void saveToBinary(std::ostream& out) const;
    void loadFromBinary(std::istream& in);
};
