#pragma once
#include <iostream>


/*
Dzia³anie BST(Binary Search Tree):
„Lewy < rodzic < prawy”
wszystko po lewej stronie ma wartoœci mniejsze od rodzica,
wszystko po prawej stronie ma wartoœci wiêksze od rodzica.
*/



struct BSTNode {
	int key;     // wartoœæ (czyli liczba, po której sortujemy)
	BSTNode* left;  // wskaŸnik na lewe dziecko (mniejsze)
	BSTNode* right;  // wskaŸnik na prawe dziecko (wiêksze)
	BSTNode* parent;  // wskaŸnik na rodzica (¿eby ³atwiej szukaæ poprzednika i nastêpnika)
	BSTNode(int k) : key(k), left(nullptr), right(nullptr), parent(nullptr) {}   // pocz¹tkowo ustawia na nullptr ¿eby nie mieæ œmieci w pamiêci

};


class BST {

private:
	BSTNode* root;  // wskaŸnik na korzeñ drzewa
	int count;		// liczba wêz³ów w drzewie
	BSTNode* removeNode(BSTNode* x);	// funkcja do usuwania wêz³a
	void destroy(BSTNode* x);			// funkcja do niszczenia drzewa (usuwania wszystkich wêz³ów)


public:
	BST();
	~BST();

	bool insert(int key);	// funkcja do wstawiania klucza do drzewa
	BSTNode* search(int key);		// funkcja do wyszukiwania klucza w drzewie
	BSTNode* minNode(BSTNode* x);	// funkcja do znajdowania najmniejszego wêz³a
	BSTNode* maxNode(BSTNode* x);	// funkcja do znajdowania najwiêkszego wêz³a
	BSTNode* pred(BSTNode* x);		// funkcja do znajdowania poprzednika wêz³a
	BSTNode* succ(BSTNode* x);		// funkcja do znajdowania nastêpnika wêz³a
	void remove(int key);			// funkcja do usuwania klucza z drzewa

	void preorder(BSTNode* node);	//wyœwietlanie w kolejnoœci preorder
	void inorder(BSTNode* node);	//wyœwietlanie w kolejnoœci inorder
	void postorder(BSTNode* node);	//wyœwietlanie w kolejnoœci postorder
	void display();					// funkcja do wyœwietlania drzewa
	BSTNode* getRoot() { return root; }		// funkcja do pobierania korzenia drzewa

};
fghfgh
gfhfg
