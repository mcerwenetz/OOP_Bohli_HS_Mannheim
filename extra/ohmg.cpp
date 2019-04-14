#include <iostream>
#include "Widerstandsnetz.h"
#include "ooptool.h"
#include "ooptoolg.h"
using namespace std;

Pixels pxs(600);

int main() {
    Poti p1(100); // erster Widerstand durch Poti ersetzt
    Resistor r2(200), r3(300); 
    Parallel par(&p1, &r2); // Poti (statt R1) und R2 parallel
    Serial ser(&par, &r3); // R1 || R2 seriell mit R3
    cout << "Widerstandsnetz1, R1 als Poti zwischen 0 und 600" << endl;
    cout << "  wird bei 300..450 Ohm sein" << endl;
    pxs.add_text(0, 0, "Widerstandsnetz");
    pxs.add_text(0, 20, "Poti 0..600");
    for (int x=0; x < pxs.width(); ++x) {
        p1.set_ohm((double) x);
        int y = ser.ohm()-150; // verschiebe auf 150..300
        pxs.set(x, pxs.height()-y, Rot); // Anzeige, Nullpunkt nach unten
    }
    schlafeMs(5000);
}    
