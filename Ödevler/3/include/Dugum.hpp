//Ağacın Düğümü
#ifndef DUGUM_HPP       
#define DUGUM_HPP
#include "iostream"
#include "Queue.hpp"
using namespace std;
class Dugum{
public:

	Queue *veri;
	Dugum *sol;
	Dugum *sag;
	Dugum(Queue *vr);
	~Dugum();
};
#endif
