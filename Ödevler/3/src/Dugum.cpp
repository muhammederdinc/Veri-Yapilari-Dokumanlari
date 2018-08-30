
#include "Dugum.hpp"
Dugum::Dugum(Queue *vr){
		veri=vr;
		sol=NULL;
		sag=NULL;
	}
Dugum ::~Dugum()
{
	delete sol;
	delete sag;
}
