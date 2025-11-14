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

	void writeInorder(BSTNode* x, std::ofstream& out) const;

public:
    BST();
    ~BST();

	bool insert(int key);	// funkcja do wstawiania klucza do drzewa
	void remove(int key);			// funkcja do usuwania klucza z drzewa
	BSTNode* search(int key);		// funkcja do wyszukiwania klucza w drzewie



	BSTNode* minNode(BSTNode* x);	// funkcja do znajdowania najmniejszego wêz³a
	BSTNode* maxNode(BSTNode* x);	// funkcja do znajdowania najwiêkszego wêz³a


	BSTNode* pred(BSTNode* x);		// funkcja do znajdowania poprzednika wêz³a
	BSTNode* succ(BSTNode* x);		// funkcja do znajdowania nastêpnika wêz³a

	void preorder(BSTNode* node);	//wyœwietlanie w kolejnoœci preorder
	void inorder(BSTNode* node);	//wyœwietlanie w kolejnoœci inorder
	void postorder(BSTNode* node);	//wyœwietlanie w kolejnoœci postorder
	void display();					// funkcja do wyœwietlania drzewa
	BSTNode* getRoot() { return root; }		// funkcja do pobierania korzenia drzewa

    // zapis / odczyt binarny
    void saveToBinary(std::ostream& out) const;
    void loadFromBinary(std::istream& in);
};
