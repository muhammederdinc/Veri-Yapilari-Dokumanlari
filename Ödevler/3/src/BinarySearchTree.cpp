
#include "BinarySearchTree.hpp"
void BinarySearchTree:: AraveEkle(Dugum *&cocuk,Queue *gelen)
    {

			if(cocuk == NULL) cocuk = new Dugum (gelen);
			else if(gelen->toplam() < cocuk->veri->toplam())
				AraveEkle(cocuk->sol,gelen);
			else if(gelen->toplam() > cocuk->veri->toplam())
				AraveEkle(cocuk->sag,gelen);
			else return;
	}
void BinarySearchTree:: Inorder(Dugum *cocuk) {
			if(cocuk != NULL){
				Inorder(cocuk->sol);
				cout<<cocuk->veri->toplam()<<" ";
				Inorder(cocuk->sag);
			}
		}
void BinarySearchTree::  Preorder(Dugum *cocuk) {
			if(cocuk != NULL){
				cout<<cocuk->veri->toplam()<<" ";
				Preorder(cocuk->sol);
				Preorder(cocuk->sag);
			}
		}
void BinarySearchTree:: Postorder(Dugum *cocuk){
			if(cocuk != NULL){
				Postorder(cocuk->sol);
				Postorder(cocuk->sag);
				cout<<cocuk->veri->toplam()<<" ";
			}
		}

    void BinarySearchTree::ekle(Queue *data)
    {
        AraveEkle(root,data);
    }
    void BinarySearchTree:: Inorder() {
				Inorder(root);
			}
    void BinarySearchTree:: Preorder() {
				Preorder(root);
			}
	void BinarySearchTree:: Postorder(){
				Postorder(root);
			}
BinarySearchTree :: ~BinarySearchTree()
	{
		
	}	
