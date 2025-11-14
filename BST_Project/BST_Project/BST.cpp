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
	BSTNode* n = new BSTNode(key);		// 'n' czyli, nowy wezel  
	BSTNode* y = nullptr;				// 'y' oznacza poprzednika  
	BSTNode* x = root;					//'x' oznacza obecny wezel (pocz¹tkowo korzeñ)  


	while (x) {
		y = x;
		if (key = x->key)
		{
			delete n;
			return false;
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




//Usuwanie wêz³a

BSTNode* BST::removeNode(BSTNode* x) {
	BSTNode* y = x->parent;
	BSTNode* z;


	if (x->left && x->right)
	{
		z = (rand() % 2) ? removeNode(pred(x)) : removeNode(succ(x));
		z->left = x->left;
		if (z->left)
		{
			z->left->parent = z;
		}

		z->right = x->right;

		if (z->right)
		{
			z->right->parent = z;
		}
		count++;
	}
	else
	{
		z = (x->left) ? x->left : x->right;
	}

	if (z)
	{
		z->parent = y;
	}
	if (!y)
	{
		root = z;
	}
	else if (y->left == x)
	{
		y->left = z;
	}
	else { y->right = z; }

	count--;
	return x;

}






//funkcja do usuwania klucza z drzewa
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

//preorder
void BST::preorder(BSTNode* x) {
	if (x) {
		cout << x->key << " ";			//odwiedzamy wêze³
		preorder(x->left);				//odwiedzamy lewe poddrzewo
		preorder(x->right);				//odwiedzamy prawe poddrzewo
	}
}

//inorder
void BST::inorder(BSTNode* x) {
	if (x) {
		inorder(x->left);				//odwiedzamy lewe poddrzewo
		cout << x->key << " ";			//odwiedzamy wêze³
		inorder(x->right);				//odwiedzamy prawe poddrzewo
	}
}

//postorder
void BST::postorder(BSTNode* x) {
	if (x) {
		postorder(x->left);				//odwiedzamy lewe poddrzewo
		postorder(x->right);			//odwiedzamy prawe poddrzewo
		cout << x->key << " ";			//odwiedzamy wêze³
	}
}





//wyœwietlanie drzewa
void BST::display() {
	cout << "Drzewo BST (inorder): ";
	inorder(root);						//wyœwietlamy drzewo w kolejnoœci inorder
	cout << "\nLiczba wezlow: " << count << endl;	//wyœwietlamy liczbê wêz³ów
}



//œcie¿ka do elementu
void BST::showPathTo(int key) {
	BSTNode* x = root;					//'x' oznacza obecny wezel (pocz¹tkowo korzeñ)
	cout << "Sciezka: ";


	while (x) {
		cout << x->key;			//wyœwietlamy klucz obecnego wêz³a
		if (x->key == key) {			//jeœli znaleŸliœmy klucz
			cout << "(Znaleziono)\n";
			return;						//koñczymy funkcjê
		}
		cout << " -> ";					// 'stzra³ka' pokazuje droge przez kolejne elementy
		x = (key < x->key) ? x->left : x->right;	//jeœli klucz jest mniejszy, idziemy w lewo, jeœli wiêkszy, idziemy w prawo
	}
	cout << "\nWartosc nie znaleziona w drzewie." << endl; //jeœli nie znaleŸliœmy klucza
}




//wpisywanie w kolejnoœci inorder do pliku
void BST::writeInorder(BSTNode* x, std::ofstream& out) const {
	if (!x) return;
	writeInorder(x->left, out);		//odwiedzamy lewe poddrzewo
	out << x->key << " ";			//zapisujemy klucz
	writeInorder(x->right, out);	//odwiedzamy prawe poddrzewo

}


//zapisywanie do pliku tekstowego
bool BST::saveToText(const string& filename) const {
	ofstream out(filename);
	if (!out) return false;					//jeœli nie uda³o siê otworzyæ pliku, zwracamy false

	writeInorder(root, out);			//zapisujemy drzewo w kolejnoœci inorder
	cout << "\n";
	return true;						//zwracamy true, bo zapis siê powiód³
}


//wczytywanie z pliku tekstowego
bool BST::loadFromText(const string& filename) {
	ifstream in(filename);
	if (!in) return false;					//jeœli nie uda³o siê otworzyæ pliku, zwracamy false

	destroy(root);						//niszczymy obecne drzewo
	root = nullptr;						//ustawiamy korzeñ na nullptr
	count = 0;							//zerujemy licznik wêz³ów


	int k;
	while (in >> k) {					//czytamy klucze z pliku
		insert(k);					//wstawiamy klucze do drzewa
	}
	return true;						//zwracamy true, bo wczytywanie siê powiod³o
}



//zapisywanie do pliku binarnego
void BST::saveToBinary(ostream& out) const {
	int n = count;
	out.write((char*)&n, sizeof(n));		//zapisujemy liczbê wêz³ów)

	//inorder
	ofstream* o = (ofstream*)&out;
	writeInorder(root, *o);				//zapisujemy drzewo w kolejnoœci inorder

}


//odczytywanaie z pliku binarnego
void BST::loadFromBinary(istream& in) {
	destroy(root);						//niszczymy obecne drzewo
	root = nullptr;						//ustawiamy korzeñ na nullptr
	count = 0;							//zerujemy licznik wêz³ów

	//inorder
	int n;
	in.read((char*)&n, sizeof(n));		//odczytujemy liczbê wêz³ów

	for (int i = 0; i < n; i++)
	{
		int k;
		in.read((char*)&k, sizeof(k));	//odczytujemy klucz
		insert(k);					//wstawiamy klucz do drzewa
	}
}