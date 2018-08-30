
#include "Queue.hpp"
Queue :: Queue()
    {
        front=back=NULL;
        lenght=0;
    }
bool Queue:: isEmpty()
    {
        return lenght==0;
    }
void Queue:: enqueue(const int& data)
    {
        Node *enson= new Node(data);
        if(isEmpty()) front=back=enson;
        else
            {
                back->next=enson;
                back=enson;
            }
            lenght++;
    }
int Queue:: toplam()
    {
        Node *temp=front;
        int topla=0;
        while(temp!=NULL)
        {
            topla+=temp->data;
            temp=temp->next;
        }
        return topla;
    }
Queue :: ~Queue()
{
	
}
