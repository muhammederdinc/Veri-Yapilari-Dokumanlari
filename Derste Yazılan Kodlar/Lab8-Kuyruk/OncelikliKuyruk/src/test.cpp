#include "Queue.hpp"

int main(){
	Queue<int> *kuyruk = new Queue<int>();
	
	kuyruk->enqueue(724);
	kuyruk->enqueue(1225);
	kuyruk->enqueue(531);
	kuyruk->enqueue(850);
	kuyruk->dequeueMax();
	cout<<kuyruk->peek()<<endl;
	cout<<kuyruk->peekMax()<<endl;
	
	delete kuyruk;
	return 0;
}