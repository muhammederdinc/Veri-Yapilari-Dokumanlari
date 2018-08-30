#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP
#include "iostream"
#include "queue.hpp"
#include "Dugum.hpp"
using namespace std;

class BinarySearchTree
{
private :
    Dugum *root;
    void AraveEkle(Dugum *&cocuk,Queue *gelen);
    void Inorder(Dugum *cocuk);
    void Preorder(Dugum *cocuk);
	void Postorder(Dugum *cocuk);
public:
    void ekle( Queue *data);
    void Inorder();
    void Preorder();
	void Postorder();
	~BinarySearchTree();
};
#endif
