#include "Noisy.h"

using namespace std;

int main()
{
/*
 * Noisy *nprt = new Noisy("n");
	delete nprt;
 */
	Noisy *anprt= new Noisy [100];
	delete [] anprt;
}
