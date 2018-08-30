#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "Node.hpp"
class Queue
{
private :
    Node *front;
    Node *back;
    int lenght;
public:
    Queue();
    bool isEmpty();
    void enqueue(const int& data);
    int toplam();
	~Queue();
};
#endif
