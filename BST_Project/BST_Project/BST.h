#pragma once
#include <iostream>


struct BSTNode {
	int key;
	BSTNode* left;
	BSTNode* right;
	BSTNode* parent;
	BSTNode(int k) : key(k), left(nullptr), right(nullptr), parent(nullptr) {}

};


class BST {
public:
	BST();
	~BST();

bool insert(int key);
BSTNode* search(int key);
BSTNode* minNode(BSTNode* x);
BSTNode* maxNode(BSTNode* x);
BSTNode* pred(BSTNode* x);
BSTNode* succ(BSTNode* x);
void remove(int key);

void preorder(BSTNode* node);
void inorder(BSTNode* node);
void postorder(BSTNode* node);
void display();

