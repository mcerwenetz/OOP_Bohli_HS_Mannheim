#include <stdio.h>

int sum(int fro, int to) {
	int erg = 0;
	for (int i=fro; i <= to; i+=1) {
		erg += i;
	}
	return erg;
}

int main(int argc, char *argv[]) {
	printf("Hello C world\n");
	int fro=1, to=100;
	printf("sum(from=%d, to=%d) = %d\n", fro, to, sum(fro, to));
	fflush(stdout);
	return 0;
}
