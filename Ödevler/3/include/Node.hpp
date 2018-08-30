//Kuyruğun düğümü
#ifndef NODE_HPP
#define NODE_HPP

#include "iostream"
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data);
    ~Node();
};
#endif
