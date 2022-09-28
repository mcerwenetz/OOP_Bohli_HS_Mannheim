#ifndef OOPTOOL_H
#define OOPTOOL_H

/** @file
 * @brief Unterstützung für Objektorientierte Programmierung (OOP)
 * Hilfsroutinen und Hilfsklassen für Objektorientierte Programmierung (OOP),
 * um Routineaufgaben zu vereinfachen und sich je nach 
 * Aufgabenstellung auf das Wesentliche zu konzentrieren.
 * Es gibt Hilfestellungen um Dateien einzulesen, Zeiten zu messen,
 * Kommandozeilenparameter zu verarbeiten und Zufallszahlen zu erzeugen.
 * Spezifische Unterstützung gibt es um Ihr Sortierverfahren zu testen
 * und zu evaluieren.
 * Verwendung: Beide Quell-Dateien ooptool.(h|cpp) in das Projekt kopieren
 */

#include <chrono>
#include <exception>
#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <vector>

/** Ausnahme, wenn etwas schiefgeht wird diese Ausnahme von
 * den Funktionen geworfen.
 */
struct ooptool_exception : public std::exception {
    std::string cause;
    ooptool_exception(const std::string& cause);
    ooptool_exception(const std::string& cause, int val);
    ooptool_exception(const std::string& cause, long val);
    ooptool_exception(const std::string& cause, const std::string& val);
    const char *what() const noexcept;
};

/** Beginnt ein String mit einem Präfix?
 * @param s zu durchsuchender String
 * @param prefix der Präfix
 * @return wahr gdw prefix ist Präfix von s
 */
bool starts_with(const std::string& s, const std::string& prefix);

/** Formatiert ein long mit minimaler Anzahl an Zeichen 
 * @param val zu formatierender Wert
 * @param length Anzahl der Zeichen
 * @param fill_char mit welchem Zeichen wird aufgefüllt
 * @return formatierter String
 */
// must come before inline int
std::string format(long val, int length=0, char fill_char=' ');

/** Formatiert ein int mit minimaler Anzahl an Zeichen 
 * @param val zu formatierender Wert
 * @param length Anzahl der Zeichen
 * @param fill_char mit welchem Zeichen wird aufgefüllt
 * @return formatierter String
 */
inline std::string format(int val, int length=0, char fill_char=' ') {
    return format((long) val, length, fill_char);
}

/** Prüft, ob Datei existiert durch Öffnen der Datei
 * @param filename Dateiname der zu prüfenden Datei
 * @return wahr gdw Datei war lesbar
 */
bool file_exists(const std::string& filename);

/** Vollständiges Einlesen einer Datei als vector<char>
 * @param filename Dateiname der einzulesenden Datei
 * @return binärer Inhalt der Datei
 */ 
std::vector<char> read_bytes(const std::string& filename);

/** Vollständiges Lesen einer Textdatei als vector<string>,
 * Kommentarzeilen (#..) ignorieren, leere Zeilen ignorieren,
 * Zeilen mit whitespaces sind nicht leer
 * @param filename Dateiname der einzulesenden Datei
 * @return Zeilen der Datei
 */
std::vector<std::string> read_lines(const std::string& filename);

/** Wortweises Lesen einer Textdatei als vector<string>,
 * alphanumerische deutsche Worte, Satzzeichen etc. entfernen,
 * Kommentarzeilen (#..) ignorieren, leere Zeilen ignorieren,
 * Zeilen mit whitespaces sind nicht leer
 * @param filename Dateiname der einzulesenden Datei
 * @return Wörter der Datei
 */
std::vector<std::string> read_words(const std::string& filename);

/** Einlesen von Zahlen als vector<int>,
 * numerische Wörter zu int konvertiert, Satzzeichen entfernen
 * Kommentarzeilen (#..) ignorieren, leere Zeilen ignorieren,
 * @param filename Dateiname der einzulesenden Datei
 * @return ints der Datei
 */
std::vector<int> read_ints(const std::string& filename);

/** Einlesen von Zahlen als vector<long>,
 * numerische Wörter zu long konvertiert, Satzzeichen entfernen
 * Kommentarzeilen (#..) ignorieren, leere Zeilen ignorieren,
 * @param filename Dateiname der einzulesenden Datei
 * @return longs der Datei
 */
std::vector<long> read_longs(const std::string& filename);

/** Einlesen von Zahlen als vector<double>,
 * numerische Wörter zu double konvertiert, Satzzeichen entfernen
 * Kommentarzeilen (#..) ignorieren, leere Zeilen ignorieren,
 * @param filename Dateiname der einzulesenden Datei
 * @return doubles der Datei
 */
std::vector<double> read_doubles(const std::string& filename);

/** Einlesen von Zahlen als zweidimensionalen Vektor vector<vector<int>>,
 * Je Zeile steht ein Feld, muss nicht rechteckig (gleiche Dimensionen) sein
 * numerische Wörter zu int konvertiert, Satzzeichen entfernen
 * Kommentarzeilen (#..) ignorieren, leere Zeilen ignorieren,
 * @param filename Dateiname der einzulesenden Datei
 * @return ints der Datei
 */
std::vector<std::vector<int>> read_2ints(const std::string& filename);

/** Einlesen von Zahlen als zweidimensionalen Vektor vector<vector<double>>,
 * Je Zeile steht ein Feld, muss nicht rechteckig (gleiche Dimensionen) sein
 * numerische Wörter zu int konvertiert, Satzzeichen entfernen
 * Kommentarzeilen (#..) ignorieren, leere Zeilen ignorieren,
 * @param filename Dateiname der einzulesenden Datei
 * @return ints der Datei
 */
std::vector<std::vector<double>> read_2doubles(const std::string& filename);

/** Einlesen eines Bilds im (ASCII) PGM-Format
 * Die ersten drei Zahlen sind Breite, Höhe, maximale Helligkeit.
 * Die folgenden Zahlen sind zeilenweise die Helligkeitswerte der Pixel
 * http://netpbm.sourceforge.net/doc/pgm.html
 * @param filename Dateiname der einzulesenden PGM-Datei
 * @return vector<int> 3 Meta-Daten und Pixel
 */
std::vector<int> read_pgm(const std::string& filename);

/** Abspeichern eines Bilds im (ASCII) PGM-Format
 * Die ersten drei Zahlen sind Breite, Höhe, maximale Helligkeit.
 * Die folgenden Zahlen sind zeilenweise die Helligkeitswerte der Pixel
 * http://netpbm.sourceforge.net/doc/pgm.html
 * @param filename Dateiname der einzulesenden PGM-Datei
 * @param vector<int> 3 Meta-Daten und Pixel
 */
void save_pgm(const std::string& filename,
              const std::vector<int>& img);


/** Parsen von Kommandozeilenparameter
 * - Flags, ja/nein, Setzen mit führendem -(oder --)
 * - Optionen als Schlüssel/Wert-Paare mit -key=value (oder --key=value)
 * - Alles andere sind Positionswerte
 * nicht mehr.
 * Flags mit bool flag(string key) zum Testen auf ein Flag key
 * Optionen mit string option(string key) oder 
   option(string key, string default_value):
 * - ein default Wert kann angegeben werden
 * - ein numerischer Typ kann erzwungen werden (int, long, double)
 * Alles was nicht Flag oder Option ist, 
 * ist ein Positionswert (kein =), vector.
 * Man sollte nicht Positionsparameter und andere mischen.
 */
class argsp_t {
private:
    std::string _program;
    std::vector<std::string> _positionals;
    std::vector<std::string> _flags;
    std::map<std::string, std::string> _options;
public:
    /** Konstruktor mit Argumenten von main, muss const... int main sein 
     * @param argc Anzahl der Argumente
     * @param argv konstantes Feld von Char-Zeigern
     */
    argsp_t(int argc, const char *argv[]);
    /** Der Programmname, argv[0] 
     * @return Programmname wie es aufgerufen wurde, argv[0]
     */
    std::string program();
    /** Check, ob flag key gesetzt ist
     * @param key zu testender Schlüssel  
     * @return true gdw flag key gesetzt ist 
     */
    bool flag(const std::string& key);
    /** Wie viele Flags (mit - oder -- beginnend) sind gesetzt 
     * @return Anzahl der gesetzten Flags
     */
    int no_flags();
    /** Menge der (mit - oder -- beginnend) gesetzten Flags
     * @return Menge der gesetzten Flags
     */
    std::vector<std::string> flags();
    /** Gab es eine Option key=value (beinhaltet =) in den Argumenten
     * @param key gesetzter Schlüssel  
     * @return true gdw key=value wurde gesetzt
     */
    bool has_option(const std::string& key);
    /** Anzahl der Optionen key=value (beinhaltet =) in den Argumenten
     * @return Anzahl der Optionen
     */
    int no_options();
    /** Menge aller Schlüssel aller gesetzten Optionen key=value
     * @return Menge der Schlüssel aller gesetzten Optionen
     */
    std::vector<std::string> options();
    /** Greife auf Option key=value zu, Ausnahme bei nicht gesetztem key
     * @param key gesetzter Schlüssel  
     * @return value von Optione key=value
     */
    std::string option(const std::string& key);
    /** Greife auf Option key=value zu, Default-Wert bei nicht gesetztem key
     * @param key gesetzter Schlüssel  
     * @param defval Vorgabewert falls Schlüssel nicht gesetzt ist
     * @return value von Optione key=value 
     */
    std::string option(const std::string& key, const std::string& defval);
    /** Greife auf Integer-Option key=value zu, value konvertiert zu int
     * Ausnahme bei nicht gesetztem key
     * @param key gesetzter Schlüssel  
     * @return value von Option key=value zu int konvertiert
     */
    int int_option(const std::string& key);
    /** Greife auf Integer-Option key=value zu, value konvertiert zu int
     * Default-Wert bei nicht gesetztem key
     * @param key gesetzter Schlüssel  
     * @param defval Vorgabewert falls Schlüssel nicht gesetzt ist
     * @return value von Option key=value zu int konvertiert
     */
    int int_option(const std::string& key, int defval);
    /** Greife auf Long-Option key=value zu, value konvertiert zu long
     * Ausnahme bei nicht gesetztem key
     * @param key gesetzter Schlüssel  
     * @return value von Option key=value zu long konvertiert
     */
    long long_option(const std::string& key);
    /** Greife auf Long-Option key=value zu, value konvertiert zu long
     * Default-Wert bei nicht gesetztem key
     * @param key gesetzter Schlüssel  
     * @param defval Vorgabewert falls Schlüssel nicht gesetzt ist
     * @return value von Option key=value zu long konvertiert
     */
    long long_option(const std::string& key, long defval);
    /** Greife auf Double-Option key=value zu, value konvertiert zu double
     * Default-Wert bei nicht gesetztem key
     * @param key gesetzter Schlüssel  
     * @return value von Option key=value zu double konvertiert
     */
    double double_option(const std::string& key);
    /** Greife auf Double-Option key=value zu, value konvertiert zu double
     * Ausnahme bei nicht gesetztem key
     * @param key gesetzter Schlüssel  
     * @param defval Vorgabewert falls Schlüssel nicht gesetzt ist
     * @return value von Option key=value zu double konvertiert
     */
    double double_option(const std::string& key, double defval);
    /** Alle Argumente außer Programmname, Optionen und Flags (positionals)
     * @return Menge der Argumente, die weder 
     *         Programmname, Option oder Flag sind
     */
    std::vector<std::string> positionals();
    /** ites Element aller positionals (Nicht-Opts/Flags)
     * Ausnahme, falls ites Element nicht existiert
     * @param idx das wievielte Element, ites
     * @return iter Wert der Positionals als String
     */    
    std::string pos(size_t idx);
    /** ites Element aller positionals (Nicht-Opts/Flags)
     * @param idx das wievielte Element, ites
     * @param defval Vorgabewert falls ites nicht existiert
     * @return iter Wert der Positionals als String oder defval
     */
    std::string pos(size_t idx, const std::string& defval);
    /** Alle Argumente als int 
     * außer Programmname, Optionen und Flags (positionals)
     * @return Menge der Argumente als int, die weder 
     *         Programmname, Option oder Flag sind
     */
    std::vector<int> int_positionals();    
    /** ites Element aller positionals (Nicht-Opts/Flags) zu int konvertiert
     * Ausnahme, falls ites Element nicht existiert
     * @param idx das wievielte Element, ites
     * @return iter Wert der Positionals als int
     */
    int int_pos(size_t idx);
    /** ites Element aller positionals (Nicht-Opts/Flags) zu int konvertiert
     * @param idx das wievielte Element, ites
     * @param defval Vorgabewert falls ites nicht existiert
     * @return iter Wert der Positionals als int oder defval
     */
    int int_pos(size_t idx, int defval);
    /** Alle Argumente als long
     * außer Programmname, Optionen und Flags (positionals)
     * @return Menge der Argumente als long, die weder 
     *         Programmname, Option oder Flag sind
     */
    std::vector<long> long_positionals();    
    /** ites Element aller positionals (Nicht-Opts/Flags) zu long konvertiert
     * @param idx das wievielte Element, ites
     * @return iter Wert der Positionals als long
     */
    long long_pos(size_t idx);
    /** ites Element aller positionals (Nicht-Opts/Flags) zu long konvertiert
     * Ausnahme, falls ites Element nicht existiert
     * @param idx das wievielte Element, ites
     * @param defval Vorgabewert, falls ites nicht existiert
     * @return iter Wert der Positionals als long
     */
    long long_pos(size_t idx, long defval);
    /** Alle Argumente als double
     * außer Programmname, Optionen und Flags (positionals)
     * @return Menge der Argumente als double, die weder 
     *         Programmname, Option oder Flag sind
     */
    std::vector<double> double_positionals();    
    /** ites Element aller positionals (Nicht-Opts/Flags) zu double konvertiert
     * Ausnahme, falls ites Element nicht existiert
     * @param idx das wievielte Element, ites
     * @return iter Wert der Positionals als double
     */
    double double_pos(size_t idx);
    /** ites Element aller positionals (Nicht-Opts/Flags) zu double konvertiert
     * @param idx das wievielte Element, ites
     * @param defval Vorgabewert, falls ites nicht existiert
     * @return iter Wert der Positionals als double oder defval
     */
    double double_pos(size_t idx, double defval);
};


/** Erzeugt ein Feld von Zufallszahlen
 * @param how_many wie viele Zufallszahlen
 * @param lower kleinste Zahl, default -1048576
 * @param upper größte Zahl, default 1048575
 * @return ints genau howmany Zufallszahlen
 */
std::vector<int> create_randints(int how_many,
                                 int lower=-1048576, int upper=1048575);

/** Erzeugt ein Feld von Zufallszahlen, immer die gleichen 
 * (fester seed, zum testen)
 * @param how_many wie viele Zufallszahlen
 * @param lower kleinste Zahl, default -1048576
 * @param upper größte Zahl, default 1048575
 * @return ints genau howmany Zufallszahlen mit festem seed
 */
std::vector<int> create_same_randints(int how_many,
                                      int lower=-1048576, int upper=1048575);

/** Sortierfunktion für ints
 */
typedef void (* sort_function)(std::vector<int>& a);

/** prüft, ob ein Feld aufsteigend sortiert ist
 *  @param a zu prüfendes Feld
 *  @param first_error falls nicht sortiert index des ersten 
           falschen Elements, 0 sonst
 *  @return wahr gdw Feld ist aufsteigend sortiert
 */
bool is_sorted(std::vector<int>& a, int& first_error);

/** Prüft eine Sortierfunktion mit Beispielen, mit Ausgaben
 * @param sort die zu testende Funktion
 * @param timing Zeitmessung, default false
 * @param large große Probleme, default false
 * @param verbose wie gesprächig, default 1
 * @return wahr gdw all tests das jeweilige Feld sortiert haben
 */
bool check_sort(sort_function sort, bool timing=false,
                bool large=false, int verbose=1);

/** swap von zwei elementen, zählt wie häufig gerufen
 * @param a feld in dem geswappt wird
 * @param i eine Stelle, die geswapped wird
 * @param j andere Stelle, die geswapped wird
 */
void swap(std::vector<int>& a, int i, int j);

/** wie oft wurde swap gerufen seit letztem reset (nicht threadsafe)
 * @return wie oft swap gerufen
 */
int get_swaps();

/** wie oft wurde swap gerufen seit letztem reset (nicht threadsafe) 
 * und auf 0 setzen
 * @return wie oft swap gerufen
 */
int reset_swaps();

/** Timer, um verbrauchte CPU-Zeit zu messen. 
 */
class Timer {
private:
    std::chrono::system_clock::time_point start;
public:
    Timer();
    double measure() const; //> in Sekunden
    long measureMs() const; //> in Millisekunden 
    long measureUs() const; //> in Mikrosekunden
    long measureNs() const; //> in Nanosekunden
    void restart(); // Neustart
    std::string humanMeasure() const; // für Menschen lesbarer String
};

/** Schlafe ein paar Millisekunden
 * @param ms wieviele Millisekunden zu schlafen
 */
void schlafeMs(int ms);

/** Schlafe ein paar Mikrosekunden
 * @param ms wieviele Mikrosekunden zu schlafen
 */
void schlafeUs(int us);

/** Ausgabe von vector<T>, default eines pro Zeile
 * @param tvec der Vector von Ts
 * @param per_line wie viele Elemente je Zeile, default 1
 * @param width Mindestbreite, default 0 (keine)
 * @param show_linenum Angabe der Zeilennummer: default nein
 */
template<typename T> void show_tvec(const std::vector<T>& tvec,
        int per_line=1, int width=0, bool show_linenum=false) {
    int i=0;
    int line_no=0;
    const std::string separator = " ";
    int no_lines = (tvec.size()+(per_line-1))/per_line;
    int line_no_width = std::to_string(no_lines).length();
    for (T val : tvec) {
        if (i%per_line == 0) {
            if (i > 0) {
                std::cout << std::endl;
            }
            line_no += 1;
            if (show_linenum) {
                std::cout << std::setw(line_no_width) << line_no << ": ";
            }
        }
        if (width > 0) {
            std::cout << std::setw(width);
        }
        std::cout << val << separator;
        i += 1;
    }
    if (!tvec.empty()) {
        std::cout << std::endl;
    }
}


#endif
