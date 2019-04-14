#include "simplemath.h"

// Hilfsroutine
// man kann hier auch debuggen
static long hoch(int n, int times) {
    long ret = 1;
    for (int i=0; i < times; i++) {
        ret *= n;
    }
    return ret;
}

long quadrat(long n) {
    return hoch(n, 2);
}

long kubik(long n) {
    return hoch(n, 3);
}

long hoch4(int n) {
    return hoch(n, 4);
}
