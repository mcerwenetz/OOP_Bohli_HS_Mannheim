#ifndef TEXTER_H
#define TEXTER_H
// Sie dürfen in der Header-Datei private Methoden hinzunehmen
// aber vorhandenen Methoden oder Attribute nicht ändern

#include <string>

// Texter hält zwei Zeiger auf Texte, die der Instanz gehören
class Texter {
public:
    Texter(const char *s1=nullptr, const char *s2=nullptr);
    Texter(const Texter &);
    ~Texter();
    Texter &operator=(const Texter &);
    // Gesamtlänge der beiden Zeichenketten
    unsigned entire_length() const;
    // Länge der kürzeren der beiden Zeichenketten
    unsigned length_smallest() const;
    // Länge der längeren der beiden Zeichenketten
    unsigned length_largest() const;
    // Tauscht beide Zeichenketten.
    void flip();
    // Fasst beide Zeichenketten in der ersten zusammen durch
    // Anhängen der zweiten. Die zweite wird der nullptr.
    void merge();
    // Tauscht jeweils beide Zeichenketten.
    void swap_both(Texter &texter);
    // Tauscht die jeweils längere Zeichenkette.
    void swap_largest_length(Texter &texter);
    // Gleichheit
    bool operator==(const Texter&);
    
    // die nächsten zwei Methoden nicht ändern
    const char *first() { return _text1; }
    const char *second() { return _text2; }
private:
    // >>> Hier können, aber müssen nicht, eigene Methoden deklariert werden

    // <<<
    char *_text1;
    char *_text2;
};

#endif /* TEXTER_H */
