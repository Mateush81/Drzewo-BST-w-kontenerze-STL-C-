#include "BST.h"

using namespace std;

BST::BST() : root(nullptr), count(0) {}  //root(nullptr), czyli na pocz¹tku drzewo jest puste
BST::~BST() { destroy(root); }			//niszczenie drzewa przy usuwaniu obiektu BST

void BST::destroy(BSTNode* x) {			// usuwanie rekurencyjnie, czyli: lewe -> prawe -> rodzic -> delete
	if (!x) return;				// jeœli x jest pusty(nullptr), to koñczymy funkcjê
	destroy(x->left);
	destroy(x->right);
	delete x;
}



//wstawianie elementu

bool BST::insert(int key) {
	BSTNode* n = new BSTNode(key);		//nowy wezel 'n'
	BSTNode* y = nullptr;				//'y' oznacza poprzednika
	BSTNode* x = root;					//'x' oznacza obecny wezel (pocz¹tkowo korzeñ)


	while (x) {
		y = x;
		if (key = x->key)
		{
			delete n; return false;
		}
		x = (key < x->key) ? x->left : x->right;	//jeœli klucz jest mniejszy, idziemy w lewo, jeœli wiêkszy, idziemy w prawo		
}


	n->parent = y;						//ustawiamy rodzica nowego wêz³a na 'y'
	if (!y) {							//jeœli drzewo jest puste
		root = n;						//nowy wêze³ staje siê korzeniem
	}
	else if (key < y->key) {			//jeœli klucz jest mniejszy ni¿ klucz 'y'
		y->left = n;					//nowy wêze³ staje siê lewym dzieckiem 'y'
	}
	else {
		y->right = n;					//nowy wêze³ staje siê prawym dzieckiem 'y'
	}
	count++;							//zwiêkszamy licznik wêz³ów
	return true;						//zwracamy true, bo wstawianie siê powiod³o
}


//szukanie elementu
BSTNode* BST::search(int key) {
	BSTNode* x = root;					//'x' oznacza obecny wezel (pocz¹tkowo korzeñ)
	while (x && x->key != key) {		
		x = (key < x->key) ? x->left : x->right;	//jeœli klucz jest mniejszy, idziemy w lewo, jeœli wiêkszy, idziemy w prawo
	}
	return x;							//jeœli równa to zwracamy znaleziony wêze³, a jeœli nie znaleziono to zwracamy nullptr
}


//minimum
BSTNode* BST::minNode(BSTNode* x) {
	while (x && x->left) {				//dopóki istnieje lewe dziecko
		x = x->left;					//idziemy w lewo
	}
	return x;							//zwracamy najmniejszy wêze³
}

//maksimum
BSTNode* BST::maxNode(BSTNode* x) {
	while (x && x->right) {			//dopóki istnieje prawe dziecko
		x = x->right;				//idziemy w prawo
	}
	return x;						//zwracamy najwiêkszy wêze³
}



//poprzednik
BSTNode* BST::pred(BSTNode* x) {
	if (x->left) {					//jeœli istnieje lewe dziecko
		return maxNode(x->left);	//to poprzednik to maksimum w lewym poddrzewie
	}
	BSTNode* y = x->parent;			//'y' oznacza rodzica
	while (y && x == y->left) {		//dopóki 'x' jest lewym dzieckiem 'y'
		x = y;
		y = y->parent;				//idziemy w górê do rodzica
	}
	return y;						//zwracamy poprzednika
}

//nastêpnik
BSTNode* BST::succ(BSTNode* x) {
	if (x->right) {					//jeœli istnieje prawe dziecko
		return minNode(x->right);	//to nastêpnik to minimum w prawym poddrzewie
	}
	BSTNode* y = x->parent;			//'y' oznacza rodzica
	while (y && x == y->right) {	//dopóki 'x' jest prawym dzieckiem 'y'
		x = y;
		y = y->parent;				//idziemy w górê do rodzica
	}
	return y;						//zwracamy nastêpnik
}


//usuwanie wêz³a
void BST::remove(int key) {
	BSTNode* x = search(key);		//szukamy wêz³a do usuniêcia
	if (x) {						//jeœli znaleŸliœmy wêze³
		removeNode(x);				//usuwamy go				--> jest w osobnej funkcji removeNode()
		count--;					//zmniejszamy licznik wêz³ów
	}
	else
	{
		cout << "Wartosc nie znaleziona w drzewie." << endl;
	}
}


//przechodzenie po drzewie:
//preorder -> korzeñ -> lewe poddrzewo -> prawe poddrzewo
//preorder -> lewe poddrzewo -> korzeñ -> prawe poddrzewo
//postorder -> lewe poddrzewo -> prawe poddrzewo -> korzeñ

//inorder
void BST::inorder(BSTNode* x) {
	if (x) {
		inorder(x->left);				//odwiedzamy lewe poddrzewo
		cout << x->key << " ";			//odwiedzamy wêze³
		inorder(x->right);				//odwiedzamy prawe poddrzewo
	}
}



//wyœwietlanie drzewa
void BST::display() {
	cout << "Drzewo BST (inorder): ";
	inorder(root);						//wyœwietlamy drzewo w kolejnoœci inorder
	cout << "\nLiczba wezlow: " << count << endl;	//wyœwietlamy liczbê wêz³ów
}