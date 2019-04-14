#include "GraphicObject.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "ooptool.h"
#include "ooptoolg.h"
#include <iostream>
using namespace std;

Pixels pxs(600); // hierauf zeichnen wir

void show(GraphicObject *go, const sf::Color &color) {
    for (int y=0; y < pxs.height(); y+=1) {
        for (int x=0; x < pxs.width(); x+=1) {
            if (go->is_in(x, y)) {
                pxs.set(x, y, color);
            }
        }
    }
}

void hide(GraphicObject *go) {
    for (int y=0; y < pxs.height(); y+=1) {
        for (int x=0; x < pxs.width(); x+=1) {
            if (go->is_in(x, y)) {
                pxs.set(x, y, Schwarz);
            }
        }
    }
}

int main() {
    const sf::Color *colors[] = { // colors do not copy ??
        &Rot, &Gruen, &Blau, &Gelb, &Magenta, &Cyan,
        &Rot, &Gruen, &Blau, &Gelb, &Magenta, &Cyan
    };
    int coloridx = 0;
    pxs.add_text(0, 0, "draw GraphicObject's");
	Square square_a(10 , 10 , 100);
	Square square_b(60 , 60 , 50 );
	Square square_c(120, 10 , 100);
	Circle circle_a(170, 60 , 50 );
	Circle circle_b(170, 60 , 25 );
	Circle circle_c(170, 170, 50 );

    int idt1 = pxs.add_text(0, 20, "draw squares");    
	show(&square_a, *colors[coloridx++]);
	show(&square_b, *colors[coloridx++]);
	show(&square_c, *colors[coloridx++]);
    schlafeMs(1000);
    int idt2 = pxs.add_text(0, 40, "draw circles");
	show(&circle_a, *colors[coloridx++]);
	show(&circle_b, *colors[coloridx++]);
	show(&circle_c, *colors[coloridx++]);
    schlafeMs(3000);
    pxs.change_text(idt1, "hide square");
    pxs.change_text(idt2, "");
	hide(&square_b);
    schlafeMs(1000);
    pxs.change_text(idt2, "hide circle");
	hide(&circle_a);
    schlafeMs(3000);
    pxs.quit();
}

