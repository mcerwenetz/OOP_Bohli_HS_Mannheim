#include <iostream>
using namespace std;

int sum(int fro, int to) {
	int erg = 0;
	for (int i=fro; i <= to; i+=1) {
		erg += i;
	}
	return erg;
}

int main(int argc, char *argv[]) {
	cout << "Hello C++ World" << endl;
	int fro=1, to=100;
	cout << "sum(fro=" << fro << ", to=" << to << ") = ";
	cout << sum(fro, to) << endl;
	return 0;
}
