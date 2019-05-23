#ifndef BILD_H
#define BILD_H
// Sie dürfen in der Header-Datei private Methoden hinzunehmen
// aber vorhandenen Methoden oder Attribute nicht ändern

// Bild hält einen Zeiger auf ein unsigned char Array, das der Instanz gehört
class Bild {
public:
    Bild(unsigned int breite=4, unsigned int hoehe=3);
    Bild(const Bild &);
    ~Bild();
    Bild &operator=(const Bild &);
    unsigned int size() const; // Anzahl der Grauwerte
    double aspect_ratio() const; // Verhaeltnis Breite zu Hoehe
    // Grauwert an Bild[zeile,spalte]; bei 4x3-Bild maximal zeile=2,spalte=3
    unsigned char &at(unsigned int zeile, unsigned int spalte);
    // nur Lesen, ausserhalb gueltigen Bereichs ist es 0x00
    unsigned char at(unsigned int zeile, unsigned int spalte) const;
    void fuelle(unsigned char gray); // alle Pixel gray
    void zeile(unsigned int row, unsigned char gray); // Eine Zeile gray
    void spalte(unsigned int col, unsigned char gray); // Eine Spalte gray
    void breiter(unsigned char gray); // Eine Spalte mehr und diese gray
    void flip(Bild &bild); // Tauscht alle Bildinhalte
    
    // die nächsten dreiMethoden nicht ändern
    unsigned char *get_img() { return img; }
    unsigned int breite() const { return width; }
    unsigned int hoehe() const { return height; }
private:
    // >>> Hier können, aber müssen nicht, eigene Methoden deklariert werden

    // <<<
    unsigned char *img; // alle Bildpunkte
    unsigned int width; // breite
    unsigned int height; // hoehe
};

#endif /* BILD_H */
