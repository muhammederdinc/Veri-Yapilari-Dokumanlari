#ifndef KUYRUK_HPP
#define KUYRUK_HPP

#include "KuyrukBos.hpp"
#include <cmath>

template <typename Object>
class Queue{
	private:
		int front;
		int back;
		int capacity;
		int length;
		Object *items;
		
		void reserve(int yeniKapasite){
			Object *temp = new Object[yeniKapasite];
			for(int i=front,j=0;j<length; j++,i++){
				temp[j] = items[i]; 
			}
			capacity = yeniKapasite;
			delete[] items;
			items = temp;
			front = 0;
			back = length - 1;
		}
	public:
		Queue(){
			capacity=1;
			front=0;
			back=-1;
			length=0;			
			items=new Object[capacity];
		}
		void clear(){			
			front=0;
			back=-1;
			length=0;
		}
		int count() const{
			return length;
		}
		bool isEmpty() const {
			return length == 0;
		}
		const Object& peek() const throw(KuyrukBos){
			if(isEmpty()) throw KuyrukBos();
			return items[front];
		}
		void enqueue(const Object& item){
			if(back == capacity-1) reserve(2*capacity);
			back++; 
			items[back] = item;
			length++;
		}
		void dequeue() throw(KuyrukBos){
			if(isEmpty()) throw KuyrukBos();			
			front++;
			length--;
		}
		~Queue(){
			delete[] items;
		}		
};
#endif