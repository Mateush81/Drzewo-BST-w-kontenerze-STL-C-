#pragma once
#include <iostream>
#include <fstream>
#include <string>


/**
* @file BST.h
* @brief Definicja klasy BST (Binary Search Tree) oraz struktury BSTNode.
* 
* Jak dzia³a drzewo BST:
*  - lewe poddrzewo zawiera wartoœci mniejsze ni¿ wartoœæ wêz³a
*  - korzen (root) jest pocz¹tkiem drzewa
*  - prawe poddrzewo zawiera wartoœci wiêksze ni¿ wartoœæ wêz³a
* 
* 
* Przejscia drzewa: (np. dla inorder - wartoœci w kolejnoœci rosn¹cej)
*  - lewe poddrzewo -> wêze³ -> prawe poddrzewo
*/



struct BSTNode {
	int key;     /**< wartoœæ(czyli liczba, po której sortujemy) */
	BSTNode* left;  /**< wskaŸnik na lewe dziecko(mniejsze) */
	BSTNode* right;  /**< wskaŸnik na prawe dziecko (wiêksze) */
	BSTNode* parent;  /**< wskaŸnik na rodzica (¿eby ³atwiej szukaæ poprzednika i nastêpnika, usuwac itp.) */
	


	/**
	 * @brief Konstruktor inicjalizuj¹cy wêze³.
	 * @param k wartoœæ przechowywana w wêŸle
	 */
	BSTNode(int k) : key(k), left(nullptr), right(nullptr), parent(nullptr) {}   // pocz¹tkowo ustawia na nullptr ¿eby nie mieæ œmieci w pamiêci

};




/**
 * @class BST
 * @brief Klasa implementuj¹ca drzewo BST (Binary Search Tree).
 *
 * Zawiera metody do dodawania, usuwania, wyszukiwania,
 * wypisywania drzewa, zapisu do pliku i odczytu.
 * 
 */

class BST {

private:
	BSTNode* root;  /**< wskaŸnik na korzeñ drzewa */
	int count;		/**< liczba wêz³ów w drzewie */



	/**
	 * @brief Funkcja removeNode sluzy do usuwania konkretnego wêz³a.
	 * @param x wskaŸnik na wêze³, który chcemy usun¹æ
	 * @return zwraca wskaŸnik do usuniêtego wêz³a (do póŸniejszego delete)
	 */
	BSTNode* removeNode(BSTNode* x);	// funkcja do usuwania konkretnego wêz³a



	/**
	 * @brief Usuwa ca³e drzewo
	 * @param x bie¿¹cy wêze³ do usuniêcia
	 */
	void destroy(BSTNode* x);			// funkcja do niszczenia drzewa (usuwania wszystkich wêz³ów)



	/**
	 * @brief Funkcja zapisuj¹ca drzewo w kolejnoœci inorder do pliku.
	 * @param x aktualny wêze³
	 * @param out strumieñ pliku tekstowego
	 */
	void writeInorder(BSTNode* x, std::ofstream& out) const;




public:
	/**
	 * @brief Konstruktor – tworzy puste drzewo.
	 */
	BST();
	/**
	 * @brief Destruktor – usuwa ca³e drzewo.
	 */
	~BST();


	/**
	* Wstawia nowy klucz do drzewa BST.
	* @param key wartoœæ do wstawienia
	* return true jeœli wstawienie siê powiod³o
	* return false jeœli klucz ju¿ istnieje
	*/
	bool insert(int key);	// funkcja do wstawiania klucza do drzewa


	/**
	 * @brief Usuwa wezel o podanym kluczu z drzewa BST.
	 * @param key wartoœæ do usuniêcia
	 */
	void remove(int key);			// funkcja do usuwania klucza z drzewa


	/**
	 * @brief Wyszukuje wêze³ o podanym kluczu w drzewie BST.
	 * @param key wartoœæ do wyszukania
	 * @return wskaŸnik na znaleziony wêze³ lub nullptr jeœli nie znaleziono
	 */
	BSTNode* search(int key);		// funkcja do wyszukiwania klucza w drzewie


	/**
	* @brief Znajduje wêze³ o najmniejszym kluczu w poddrzewie.
	* @param x wskaŸnik na korzeñ poddrzewa
	* @return wskaŸnik na wêze³ z najmniejszym elementem (kluczem)
	*/
	BSTNode* minNode(BSTNode* x);	// funkcja do znajdowania najmniejszego wêz³a




	/**
	* @brief Znajduje wêze³ o najwiêkszym kluczu w poddrzewie.
	* @param x wskaŸnik na korzeñ poddrzewa
	* @return wskaŸnik na wêze³ z najwiêkszym elementem (kluczem)
	*/ 
	BSTNode* maxNode(BSTNode* x);	// funkcja do znajdowania najwiêkszego wêz³a



	/**
	* @brief Znajduje poprzednika wêz³a w drzewie BST (klucz mniejszy bezpoœrednio przed danym kluczem).
	* @param x wskaŸnik na wêze³, dla którego szukamy poprzednika
	* @return wskaŸnik na wêze³ poprzednika lub nullptr jeœli nie istnieje
	*/
	BSTNode* pred(BSTNode* x);		// funkcja do znajdowania poprzednika wêz³a


	/**
	* @brief Znajduje nastêpnika wêz³a w drzewie BST (klucz wiêkszy bezpoœrednio po danym kluczem).
	* @param x wskaŸnik na wêze³, dla którego szukamy nastêpnika
	* @return wskaŸnik na wêze³ nastêpnika lub nullptr jeœli nie istnieje
	*/
	BSTNode* succ(BSTNode* x);		// funkcja do znajdowania nastêpnika wêz³a


	/**
	* @brief Przechodzi drzewo w kolejnoœci preorder i wyœwietla klucze.
	* @param node wskaŸnik na bie¿¹cy wêze³
	*/
	void preorder(BSTNode* node);	//wyœwietlanie w kolejnoœci preorder

	/**
	* @brief Przechodzi drzewo w kolejnoœci inorder i wyœwietla klucze.
	* @param node wskaŸnik na bie¿¹cy wêze³
	*/
	void inorder(BSTNode* node);	//wyœwietlanie w kolejnoœci inorder

	/**
	* @brief Przechodzi drzewo w kolejnoœci postorder i wyœwietla klucze.
	* @param node wskaŸnik na bie¿¹cy wêze³
	*/
	void postorder(BSTNode* node);	//wyœwietlanie w kolejnoœci postorder


	/**
	* @brief Wyswietla cale dzrewo w kolejnosci inorder
	*/
	void display();					// funkcja do wyœwietlania drzewa


	
	/**
	* @brief Wyœwietla œcie¿kê od korzenia do wêz³a o podanym kluczu.
	* @param key wartoœæ docelowego wêz³a
	*/
	void showPathTo(int key);			// funkcja do wyœwietlania œcie¿ki


	/**
	* @brief Zapisuje drzewo do pliku tekstowego.
	* @param filename nazwa pliku do zapisu
	* @return true jeœli zapis siê powiód³
	* @return false jeœli nie uda³o siê otworzyæ pliku
	*/
	bool saveToText(const std::string& filename) const; // funkcja do zapisywania drzewa do pliku tekstowego




	/**
	* @brief Wczytuje drzewo z pliku tekstowego.
	* @param filename nazwa pliku do odczytu
	* @return true jeœli wczytanie siê powiod³o
	*/
	bool loadFromText(const std::string& filename); // funkcja do wczytywania drzewa z pliku tekstowego


	/**
	* @brief Zapisuje drzewo do pliku binarnego.
	* @param out strumien wyjsciowy pliku binarnego
	*/
	void saveToBinary(std::ostream& out) const; // funkcja do zapisywania drzewa do pliku binarnego



	/**
	* @brief Wczytuje drzewo z pliku binarnego.
	* @param in strumien wejsciowy pliku binarnego
	*/
	void loadFromBinary(std::istream& in); // funkcja do wczytywania drzewa z pliku binarnego



	/**
	* @brief Pobiera korzeñ drzewa BST.
	* @return wskaŸnik na korzeñ drzewa
	*/
	BSTNode* getRoot() { return root; } // funkcja do pobierania korzenia drzewa

};