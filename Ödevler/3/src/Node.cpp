
#include "Node.hpp"

Node :: Node(int data)
{
    this->data=data;
    this->next=NULL;
}
Node ::~Node()
{
	delete next;
}
