#include "BST.h"
using namespace std;


BST::BST() : root(nullptr), count(0) {}  //root(nullptr), czyli na pocz¹tku drzewo jest puste (brak korzenia, licznik = 0)

BST::~BST() { destroy(root); }			//niszczenie drzewa przy usuwaniu obiektu BST





// 1. Zejœcie max. w lewo
// 2. Zejœcie max. w prawo
// 3. Gdy brak dzieci, usuwamy wêze³ i wracamy do rodzica

/*
	 8
	/ \
   3   10
  / \
 1   6

 - destroy(8) bêdzie wywo³ywaæ destroy(3) i destroy(10)
 - destroy(3) bêdzie wywo³ywaæ destroy(1) i destroy(6)
 - destroy(1) nie ma dzieci, wiêc usuwamy 1
 - destroy(6) nie ma dzieci, wiêc usuwamy 6
 - Po usuniêciu 1 i 6, wracamy do destroy(3) i usuwamy 3
 - destroy(10) nie ma dzieci, wiêc usuwamy 10
 - Po usuniêciu 3 i 10, wracamy do destroy(8) i usuwamy 8
*/


void BST::destroy(BSTNode* x) {			// usuwanie rekurencyjnie, czyli: lewe -> prawe -> rodzic -> delete
	if (!x) return;				// jeœli x jest pusty(nullptr), to koñczymy funkcjê
	destroy(x->left);
	destroy(x->right);
	delete x;
}



//wstawianie elementu

bool BST::insert(int key) {

	// Tworzymy nowy wêze³ z dan¹ wartoœci¹
	BSTNode* n = new BSTNode(key);		// 'n' czyli, nowy wezel  
	
	
	// y = wêze³ poprzedni (rodzic), x = aktualnie przegl¹dany
	BSTNode* y = nullptr;				  
	BSTNode* x = root;					//'x' oznacza obecny wezel (pocz¹tkowo korzeñ)  


	// Szukamy miejsca, w które nowy element pasuje
	while (x) {
		y = x;					// zapamiêtujemy poprzednika
		if (key == x->key)		// // jeœli wartoœæ ju¿ jest w drzewie -> nie dodajemy
		{
			delete n;
			return false;
		}

		//jeœli klucz jest mniejszy, idziemy w lewo, jeœli wiêkszy, idziemy w prawo
		x = (key < x->key) ? x->left : x->right;	
	}


	//ustawiamy rodzica nowego wêz³a na 'y'
	n->parent = y;	


	// Jeœli drzewo by³o puste
	if (!y) {							
		root = n;						//nowy wêze³ staje siê korzeniem
	}

	// Jeœli nowy klucz ('y') jest mniejszy od rodzica -> idzie na lewo
	else if (key < y->key) {			
		y->left = n;					//nowy wêze³ staje siê lewym dzieckiem 'y'
	}

	// w przeciwnym razie na prawo
	else {
		y->right = n;					//nowy wêze³ staje siê prawym dzieckiem 'y'
	}
	count++;							//zwiêkszamy licznik wêz³ów
	return true;						//zwracamy true, bo wstawianie siê powiod³o
}


//szukanie elementu
BSTNode* BST::search(int key) {
	BSTNode* x = root;					//'x' oznacza obecny wezel (pocz¹tkowo korzeñ)
	
	
	// Idziemy w dó³ drzewa porównuj¹c wartoœci
	while (x && x->key != key) {
		x = (key < x->key) ? x->left : x->right;	//jeœli klucz jest mniejszy, idziemy w lewo, jeœli wiêkszy, idziemy w prawo
	}
	return x;							//jeœli równa to zwracamy znaleziony wêze³, a jeœli nie znaleziono to zwracamy nullptr
}



//min i max
BSTNode* BST::minNode(BSTNode* x) {

	// Minimum to element najbardziej na lewo

	while (x && x->left) {					//dopóki istnieje lewe dziecko
		x = x->left;					//idziemy w lewo
	}
	return x;							//zwracamy najmniejszy wêze³
}


BSTNode* BST::maxNode(BSTNode* x) {

	// Maksimum to element najbardziej na prawo

	while (x && x->right) {				//dopóki istnieje prawe dziecko
		x = x->right;					//idziemy w prawo
	}
	return x;							//zwracamy najwiêkszy wêze³
}











//poprzednik (wartoœæ zaraz przed x [z lewej strony])
BSTNode* BST::pred(BSTNode* x) {

	// Jeœli istnieje lewe poddrzewo 
	if (x->left) {					
		return maxNode(x->left);	//-> to  tam szukamy najwiêkszego
	}


	// W innym przypadku idziemy w górê drzewa
	// dopóki idziemy „z lewej strony”
	BSTNode* y = x->parent;			//'y' oznacza rodzica



	while (y && x == y->left) {		//dopóki 'x' jest lewym dzieckiem 'y'
		x = y;
		y = y->parent;				//idziemy w górê do rodzica
	}
	return y;						//zwracamy poprzednika, ewntualnie nullptr
}

//nastêpnik (najmniejsza wartoœc wiêksza od X)
BSTNode* BST::succ(BSTNode* x) {

	// Jeœli istnieje prawe poddrzewo
	if (x->right) {					
		return minNode(x->right);	//-> to  tam szukamy najmniejszego
	}


	// W przeciwnym razie wchodzimy wy¿ej,
	// dopóki idziemy „od prawej strony”
	BSTNode* y = x->parent;			//'y' oznacza rodzica



	while (y && x == y->right) {	//dopóki 'x' jest prawym dzieckiem 'y'
		x = y;
		y = y->parent;				//idziemy w górê do rodzica
	}
	return y;						//zwracamy nastêpnik
}




//Usuwanie wêz³a

BSTNode* BST::removeNode(BSTNode* x) {

	BSTNode* y = x->parent;		// 'y' to rodzic
	BSTNode* z;					// ¿eby usun¹æ wêze³ to najpierw musimy znaleŸæ wêze³ do zast¹pienia
								// tutaj 'z' bêdzie tym wêz³em ('z' za miejsce x)

	//PRZYPADKI:

	//1. Wêze³ ma dwoje dzieci
	if (x->left && x->right)
	{

		// losowo wybieramy poprzednika lub nastêpnika
		z = (rand() % 2) ? removeNode(pred(x)) : removeNode(succ(x));


		// przepinamy lewe dziecko
		z->left = x->left;
		if (z->left)
		{
			z->left->parent = z;
		}

		// przepinamy prawe dziecko
		z->right = x->right;

		if (z->right)
		{
			z->right->parent = z;
		}


		// removeNode zmniejszy³ liczbê elementów,
		// musimy j¹ z powrotem zwiêkszyæ
		count++;
	}


	//2. Wêze³ ma jedno dziecko lub nie ma dzieci
	else
	{	
		// wybieramy istniej¹ce dziecko
		z = (x->left) ? x->left : x->right;
	}

	// ustawiamy rodzica z
	if (z)
	{
		z->parent = y;
	}

	// przepinamy z w miejsce x
	if (!y)
	{
		// jeœli usuwamy korzeñ
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


	//szukamy wêz³a do usuniêcia
	BSTNode* x = search(key);	


	if (!x) {	
		cout << "Wartosc nie znaleziona w drzewie.\n";
		return;
	}
	else
	{
		// usuwamy wêze³ i zwalniamy pamiêæ
		BSTNode* del = removeNode(x);	
		delete del;
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


