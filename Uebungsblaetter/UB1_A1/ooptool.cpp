#include "ooptool.h"
#include <cstdlib>
#include <functional>
#include <fstream>
#include <memory>
#include <thread>

// @OOP: Das müssen Sie alles nicht lesen oder verstehen, nur verwenden
// @OOP: You are not required to read nor understand that, just use it

using namespace std;


static const long MAX_FILESIZE = 1073741824; // one GByte, for binary

ooptool_exception::ooptool_exception(const string& cause) {
    this->cause = "ooptool exception:: " + cause;
}

ooptool_exception::ooptool_exception(const string& cause, int val) {
    this->cause = "ooptool exception:: " + cause
        + " : " + to_string(val);
}

ooptool_exception::ooptool_exception(const string& cause, long val) {
    this->cause = "ooptool exception:: " + cause
        + " : " + to_string(val);
}

ooptool_exception::ooptool_exception(const string& cause,
                                     const string& val) {
    this->cause = "ooptool exception:: " + cause + " : " + val;
}

const char *ooptool_exception::what() const noexcept {
    return cause.c_str();
}

// internal, called on error 
static ooptool_exception error(const string& cause) {
    cerr << "ERROR: " << cause << endl;
    return ooptool_exception(cause);
}

// internal, error formatting
// stackoverflow.com/questions/2342162/stdstring-formatting-like-sprintf
// c++11 way, still ugly that the caller needs to use .c_str() on strings
template<typename ... Args>
static string format(const string& fmt, Args ... args) {
    const char *cfmt = fmt.c_str();
    // Extra space for '\0'
    size_t size = snprintf(nullptr, 0, cfmt, args ... )+1; 
    unique_ptr<char[]> buf(new char[size]);
    snprintf(buf.get(), size, cfmt, args ...);
    // We don't want the '\0' inside
    return string(buf.get(), buf.get()+size-1); 
}

bool starts_with(const string& s, const string& prefix) {
    return equal(prefix.begin(), prefix.end(), s.begin());
}

std::string format(long val, int length, char fill_char) {
    std::ostringstream ostr;
    if (val < 0) {
        ostr << '-';
        if (length > 0) {
            length -= 1;
        }
        val *= -1;
    }
    ostr << std::setfill(fill_char) << std::setw(length) << val;
    return ostr.str();
}

// -- general utilities --

// -- file reading --

bool file_exists(const string& filename) {
    ifstream f(filename.c_str());
    return f.good();
}

vector<char> read_bytes(const string& filename) {
    ifstream is(filename, ifstream::binary);
    if (!is) {
        throw error(format("read_bytearray: filename=%s nicht lesbar",
                           filename.c_str()));
    }
    is.seekg(0, is.end); // end of file
    streamsize length = is.tellg(); // length/size of file
    is.seekg (0, is.beg); // start of file
    if (length > MAX_FILESIZE || length < 0) {
        throw error(format("read_bytearray: filename=%s zu gross",
                           filename.c_str()));
    }
    vector<char> buffer(length);
    is.read(buffer.data(), length); // read completely
    if (!is.good()) {
        throw error(format("read_bytearray: filename=%s Einlesefehler",
                           filename.c_str()));
    }
    is.close();
    return buffer; // should not be copied, move semantics
}

static string COMMENT_PREFIX("#");
vector<string> read_lines(const string& filename) {
    ifstream is(filename);
    if (!is) {
        throw error(format("read_lines: filename=%s nicht lesbar",
                           filename.c_str()));
    }
    vector<string> lines;
    string line;
    while (getline(is, line))    {
        if (starts_with(line, COMMENT_PREFIX)) {
            continue;
        }
        if (line.empty()) {
            continue;
        }
        lines.push_back(line);
    }
    return lines;
}

// unfortunately, regular expressions let compile time explode
// thus, we parse manually, which is awful
static string CHARS_DELIM(" \t,;'\"\0"); // what are delimiters
static string CHARS_GERMAN_WORDS("abcdefghijklmnopqrstuvwxyz"
                                 "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                 "0123456789äöüßÄÖÜ"); // what may remain
static string CHARS_INTEGRAL_WORDS("-+0123456789");

// private, words as changeable parameter, for reuse
static void read_accept_str_vec(const string& line, const string& accept,
                                vector<string> &words) {
    size_t prev=0, pos;
    while ((pos = line.find_first_of(CHARS_DELIM, prev)) != string::npos) {
        if (pos > prev) {
            string word = line.substr(prev, pos-prev);
            if (word.size() > 0 && // nonempty, only of acceptable chars
                word.find_first_not_of(accept) == string::npos) {
                words.push_back(word);
            }
        }
        prev = pos+1;
    }
    // something remaining, do not forget last match
    string word = line.substr(prev);
    // double that code
    if (word.size() > 0 && // nonempty, only of acceptable chars
        word.find_first_not_of(accept) == string::npos) {
        words.push_back(word);
    }
}

static vector<string> read_accept_str(const string& line,
                                      const string& accept) {
    vector<string> words;
    read_accept_str_vec(line, accept, words);
    return words;
}

static vector<string> read_accept_file(const string& filename,
                                       const string& accept) {
    vector<string> words;
    for (string line : read_lines(filename)) {
        read_accept_str_vec(line, accept, words);
    }
    return words;
}

vector<string> read_words(const string& filename) {
    return read_accept_file(filename, CHARS_GERMAN_WORDS);
}

vector<int> read_ints(const string& filename) {
    vector<int> ints;
    for (string iword : read_accept_file(filename, CHARS_INTEGRAL_WORDS)) {
        try {
            int val = stoi(iword);
            ints.push_back(val);
        } catch (const invalid_argument& err) {
            throw error(format("read_ints: kein int %s, %s",
                               iword.c_str(), err.what()));
        }
    }
    return ints;
}

vector<long> read_longs(const string& filename) {
    vector<long> longs;
    for (string lword : read_accept_file(filename, CHARS_INTEGRAL_WORDS)) {
        try {
            long val = stol(lword);
            longs.push_back(val);
        } catch (const invalid_argument& err) {
            throw error(format("read_longs: kein long %s, %s",
                               lword.c_str(), err.what()));
        }
    }
    return longs;
}

static string CHARS_FLOAT_WORDS("-+0123456789.");
vector<double> read_doubles(const string& filename) {
    vector<double> doubles;
    for (string dword : read_accept_file(filename, CHARS_FLOAT_WORDS)) {
        try {
            double val = stod(dword);
            doubles.push_back(val);
        } catch (const invalid_argument& err) {
            throw error(format("read_doubles: kein double %s, %s",
                               dword.c_str(), err.what()));
        }
    }
    return doubles;
}

vector<vector<int>> read_2ints(const string& filename) {
    vector<vector<int>> intss;
    for (string line : read_lines(filename)) {
        vector<int> row;
        for (string iword : read_accept_str(line, CHARS_INTEGRAL_WORDS)) {
            try {
                int val = stoi(iword);
                row.push_back(val);
            } catch (const invalid_argument& err) {
                throw error(format("read_2ints: kein int %s, %s",
                                   iword.c_str(), err.what()));
            }
        }
        intss.push_back(row);
    }
    return intss;
}

vector<vector<double>> read_2doubles(const string& filename) {
    vector<vector<double>> doubless;
    for (string line : read_lines(filename)) {
        vector<double> row;
        for (string dword : read_accept_str(line, CHARS_FLOAT_WORDS)) {
            try {
                double val = stod(dword);
                row.push_back(val);
            } catch (const invalid_argument& err) {
                throw error(format("read_2doubles: kein double %s, %s",
                                   dword.c_str(), err.what()));
            }
        }
        doubless.push_back(row);
    }
    return doubless;
}

static bool str2int(string& word, int& val) {
    if (word.size() == 0) {
        return false;
    }
    if (word.find_first_not_of(CHARS_INTEGRAL_WORDS) != string::npos) {
        return false;
    }
    // does not caputre +/- within digits
    val = stoi(word); 
    return true;
}

std::vector<int> read_pgm(const std::string& filename) {
    vector<string> raw_lines = read_lines(filename);
    vector<string> lines;
    // no STL remove_if, as the compile time explodes
    for (string line : raw_lines) {
        if (!starts_with(line, "#")) { // ignore comments
            if (line.find_first_of(CHARS_GERMAN_WORDS) 
                != string::npos) { // ignore empty lines
                lines.push_back(line);
            }
        }
    }
    vector<string> words;
    auto lit = lines.begin();
    while (lit != lines.end() && words.size() < 4) {
        if (words.size() == 0) {
            read_accept_str_vec(*lit, CHARS_GERMAN_WORDS, words); // magic
        } else {
            read_accept_str_vec(*lit, CHARS_INTEGRAL_WORDS, words);
        }
        ++lit;
    }
    if (words.size() < 4) {
        throw ooptool_exception("keine PGM-Datei, zu kurz: ", filename);
    }
    // we have enough to identify the file
    if (words[0] != "P2") { // we use plain format
        // for(auto word : words) { cout << word << " "; }; cout << endl;
        throw ooptool_exception("keine PGM-Datei, kein P2-magic: ", filename);
    }
    int width, height, maxbright;
    if (!str2int(words[1], width)) {
        throw ooptool_exception("keine PGM-Datei, Breite fehlt: ", filename);
    }
    if (!str2int(words[2], height)) {
        throw ooptool_exception("keine PGM-Datei, Hoehe fehlt: ", filename);
    }
    if (!str2int(words[3], maxbright)) {
        throw ooptool_exception("keine PGM-Datei, keine maximale Helligkeit",
                                filename);
    }
    // cout << "w=" << width << ", h=" << height;
    // cout << ", mb=" << maxbright << endl;
    vector<int> img;
    img.reserve(width*height+3);
    img.push_back(width);
    img.push_back(height);
    img.push_back(maxbright);
    words.erase(words.begin(), words.begin()+4);
    while (lit != lines.end()) {
        read_accept_str_vec(*lit, CHARS_INTEGRAL_WORDS, words);
        for (auto word: words) {
            int val;
            if (!str2int(word, val)) {
                throw ooptool_exception("Keine PGM-Datei, Pixel: ", word);
            }
            img.push_back(val);
        }
        words.clear();
        ++lit;
    }
    if (img.size() != (unsigned int) width*height+3) {
        throw ooptool_exception("Keine PGM-Datei, falsch Anzahl Pixel: ",
                                (int) img.size());
    }
    return img;
}

static bool is_pgm(const vector<int>& img) {
    size_t imgsize = img.size();
    if (imgsize < 3) {
        cerr << "is_pgm: nicht gross genug" << endl;
        return false;
    }
    if (imgsize != ((size_t) (img[0]*img[1]+3))) {
        cerr << "is_pgm: falsche Dimension: ";
        cerr << img[0] << "x" << img[1] << endl;
        return false;
    }
    int maxbright = img[2];
    for (size_t idx=3; idx<imgsize; idx+=1) {
        if (img[idx] > maxbright) {
            cerr << "is_pgm: Pixel zu hell: @" << idx << endl;;
            return false;
        }
        if (img[idx] < 0) {
            cerr << "is_pgm: Pixel zu dunkel: @" << idx << endl;;
            return false;
        }
    }
    return true;
}

void save_pgm(const string& filename,
              const vector<int>& img) {
    if (!is_pgm(img)) {
        throw ooptool_exception("save_pgm, keine PGM-Datei: ", filename);
    }
    ofstream out(filename);
    if (!out.is_open()) {
        throw ooptool_exception("save_pgm, kann nicht schreiben: ", filename);
    }
    out << "P2" << "\n";
    out << img[0] << " " << img[1] << "\n"; // dimension
    out << img[2] << "\n"; // max brightness
    // with 10 per line we are below 70 chars if max digits is 6
    int count = 0;
    for (auto it = img.begin()+3; it != img.end(); ++it) {
        out << *it;
        count += 1;
        if (count%10 == 0) {
            out << "\n";
        } else {
            out << " ";
        }
    }
    out.close();
}

// avoid include algorithm (reduce compile time)
static bool contains(const vector<string> &svec, const string &ele) {
    for (const string &s : svec) {
        if (s == ele) {
            return true;
        }
    }
    return false;
}

// the argsp arguments parser
argsp_t::argsp_t(int argc, const char *argv[]) {
    _program = argv[0];
    for (int i=1; i < argc; i+=1) {
        string arg(argv[i]);
        auto it = arg.find("=");
        if (starts_with(arg, "-") || starts_with(arg, "--")) {
            arg = arg.substr(1);
            if (starts_with(arg, "-")) {
                arg = arg.substr(1);
            }
            if (!contains(_flags, arg)) {
                _flags.push_back(arg);
            }
        } else if (it != string::npos) {
            string key = arg.substr(0, it);
            string val = arg.substr(it+1);
            _options[key] = val;
        } else {
            _positionals.push_back(arg);
        }
    }
}

string argsp_t::program() {
    return _program;
}

bool argsp_t::flag(const string& key) {
    return contains(_flags, key);
}

int argsp_t::no_flags() {
    return _flags.size();
}

vector<string> argsp_t::flags() {
    vector<string> ret = _flags; // a copy
    return ret; // move semantics prevent second copy
}

bool argsp_t::has_option(const string& key) {
    return _options.find(key) != _options.end();
}

int argsp_t::no_options() {
    return _options.size();
}

vector<string> argsp_t::options() {
    vector<string> ret;
    for (auto it : _options) {
        ret.push_back(it.first);
    }
    return ret;
}

string argsp_t::option(const string& key) {
    auto it = _options.find(key);
    if (it == _options.end()) {
        throw error(format("argsp::option: no key %s", key.c_str()));
    }
    return it->second;
}

string argsp_t::option(const string& key, const string& defval) {
    auto it = _options.find(key);
    if (it == _options.end()) {
        return defval;
    }
    return it->second;
}

int argsp_t::int_option(const string& key) {
    auto it = _options.find(key);
    if (it == _options.end()) {
        throw error(format("argsp::int_option: no %s", key.c_str()));
    }
    try {
        return stoi(it->second);
    } catch (const invalid_argument& err) {
        throw error(format("argsp::int_option(%s): no int %s",
                           key.c_str(), it->second.c_str()));
    }
}

int argsp_t::int_option(const string& key, int defval) {
    auto it = _options.find(key);
    if (it == _options.end()) {
        return defval;
    }
    try {
        return stoi(it->second);
    } catch (const invalid_argument& err) {
        throw error(format("argsp::int_option(%s, %d): no int %s",
                           key.c_str(), defval, it->second.c_str()));
    }
}

long argsp_t::long_option(const string& key) {
    auto it = _options.find(key);
    if (it == _options.end()) {
        throw error(format("argsp::long_option: no %s", key.c_str()));
    }
    try {
        return stol(it->second);
    } catch (const invalid_argument& err) {
        throw error(format("argsp::long_option(%s): no long %s",
                           key.c_str(), it->second.c_str()));
    }
}

long argsp_t::long_option(const string& key, long defval) {
    auto it = _options.find(key);
    if (it == _options.end()) {
        return defval;
    }
    try {
        return stol(it->second);
    } catch (const invalid_argument& err) {
        throw error(format("argsp::long_option(%s): no long %s",
                           key.c_str(), it->second.c_str()));
    }
}

double argsp_t::double_option(const string& key) {
    auto it = _options.find(key);
    if (it == _options.end()) {
        throw error(format("argsp::double_option: no %s", key.c_str()));
    }
    try {
        return stod(it->second);
    } catch (const invalid_argument& err) {
        throw error(format("argsp::double_option(%s): no double %s",
                           key.c_str(), it->second.c_str()));
    }
}

double argsp_t::double_option(const string& key, double defval) {
    auto it = _options.find(key);
    if (it == _options.end()) {
        return defval;
    }
    try {
        return stod(it->second);
    } catch (const invalid_argument& err) {
        throw error(format("argsp::double_option(%s): no double %s",
                           key.c_str(), it->second.c_str()));
    }
}

vector<string> argsp_t::positionals() {
    return _positionals; // a copy on purpose
}

string argsp_t::pos(size_t idx) {
    if (idx >= _positionals.size()) {
        throw error(format("argsp::pos: no idx %zu", idx));
    }
    return _positionals[idx];
}

string argsp_t::pos(size_t idx, const string& defval) {
    if (idx >= _positionals.size()) {
        return defval;
    }
    return _positionals[idx];
}

vector<int> argsp_t::int_positionals() {
    vector<int> ret;
    for (size_t idx=0; idx < _positionals.size(); idx+=1) {
        ret.push_back(int_pos(idx));
    }
    return ret;
}

int argsp_t::int_pos(size_t idx) {
    if (idx >= _positionals.size()) {
        throw error(format("argsp::int_pos: no idx %zu", idx));
    }
    try {
        return stoi(_positionals[idx]);
    } catch (const invalid_argument& err) {
        throw error(format("argsp::int_pos(%d): no int %s",
                           idx, _positionals[idx].c_str()));
    }
}

int argsp_t::int_pos(size_t idx, int defval) {
    if (idx >= _positionals.size()) {
        return defval;
    }
    try {
        return stoi(_positionals[idx]);
    } catch (const invalid_argument& err) {
        throw error(format("argsp::int_pos(%zu): no int %s",
                           idx, _positionals[idx].c_str()));
    }
}

vector<long> argsp_t::long_positionals() {
    vector<long> ret;
    for (size_t idx=0; idx < _positionals.size(); idx+=1) {
        ret.push_back(long_pos(idx));
    }
    return ret;
}

long argsp_t::long_pos(size_t idx) {
    if (idx >= _positionals.size()) {
        throw error(format("argsp::long_pos: no idx %zu", idx));
    }
    try {
        return stol(_positionals[idx]);
    } catch (const invalid_argument& err) {
        throw error(format("argsp::long_pos(%zu): no long %s",
                           idx, _positionals[idx].c_str()));
    }
}

long argsp_t::long_pos(size_t idx, long defval) {
    if (idx >= _positionals.size()) {
        return defval;
    }
    try {
        return stol(_positionals[idx]);
    } catch (const invalid_argument& err) {
        throw error(format("argsp::long_pos(%zu): no long %s",
                           idx, _positionals[idx].c_str()));
    }
}

vector<double> argsp_t::double_positionals() {
    vector<double> ret;
    for (size_t idx=0; idx < _positionals.size(); idx+=1) {
        ret.push_back(double_pos(idx));
    }
    return ret;
}

double argsp_t::double_pos(size_t idx) {
    if (idx >= _positionals.size()) {
        throw error(format("argsp::double_pos: no idx %zu", idx));
    }
    try {
        return stod(_positionals[idx]);
    } catch (const invalid_argument& err) {
        throw error(format("argsp::double_pos(%zu): no double %s",
                           idx, _positionals[idx].c_str()));
    }
}

double argsp_t::double_pos(size_t idx, double defval) {
    if (idx >= _positionals.size()) {
        return defval;
    }
    try {
        return stod(_positionals[idx]);
    } catch (const invalid_argument& err) {
        throw error(format("argsp::double_pos(%zu): no double %s",
                           idx, _positionals[idx].c_str()));
    }
}

static vector<int> _create_randints(int how_many,
                                    int lower, int upper) {
    vector<int> ret(how_many);
    int modulo = (upper-lower)+1;
    if (modulo < 0) {
        modulo = upper;
    }
    for (int i=0; i < how_many; i+=1) {
        ret[i] = (((int) rand()) % modulo) + lower;
    }
    return ret;
}

vector<int> create_randints(int how_many, int lower, int upper) {
    chrono::high_resolution_clock::time_point beginning =
        chrono::high_resolution_clock::now();
    int seed = beginning.time_since_epoch().count() % 2097152;
    srand(seed);
    return _create_randints(how_many, lower, upper);
}

vector<int> create_same_randints(int how_many, int lower, int upper) {
    srand(1234567); // default seed fixed number
    return _create_randints(how_many, lower, upper);
}

bool is_sorted(vector<int>& a, int& first_error) {
    size_t asize = a.size();
    for (size_t i=1; i < asize; i+=1) {
        if (a[i-1] > a[i]) {
            first_error = i;
            return false;
        }
    }
    first_error=0;
    return true;
}

static bool _check_sort_one(sort_function sort, int size,
                            bool timing=false, int verbose=1) {
    vector<int> a = create_randints(size);
    int first_error;
    if (is_sorted(a, first_error)) {
        if (verbose > 10) {
            cout << "Warnung, ursprüngliches Feld schon sortiert";
        }
    }
    Timer timer;
    reset_swaps();
    sort(a);
    int swaps = get_swaps();
    string measure = timer.humanMeasure();
    if (!is_sorted(a, first_error)) {
        cout << "Fehler: Feld a[" << a.size() << "] nicht sortiert, ";
        cout << "a[" << first_error-1 << "]=" << a[first_error-1] << " > ";
        cout << "a[" << first_error << "]=" << a[first_error] << endl;
        return false;
    }
    if (verbose >= 1) {
        cout << "a[" << setw(8) << size << "]: sorted ";
        if (timing) {
            cout << " " << measure;
        }
        if (swaps > 0) { // assume it is used
            cout << " swaps=" << setw(10) << swaps;
        }
        cout << endl;
    }
    return true;
}

bool check_sort(sort_function sort, bool timing, bool large, int verbose) {
    vector<int> sizes = {10, 100, 1000, 10000, 20000, 40000, 60000};
    for (int size : sizes) {
        if (!_check_sort_one(sort, size, timing, verbose)) {
            return false;
        }
    }
    if (large) {
        vector<int> sizes = {80000, 100000, 200000, 400000, 800000, 1000000};
        for (int size : sizes) {
            if (!_check_sort_one(sort, size, timing, verbose)) {
                return false;
            }
        }
    }
    return true;
}

static int _swaps = 0;
void swap(vector<int>& a, int i, int j) {
    int h = a[i];
    a[i] = a[j];
    a[j] = h;
    _swaps += 1;
}
int get_swaps() {
    return _swaps;
}
int reset_swaps() {
    int ret = _swaps;
    _swaps = 0;
    return ret;
}


Timer::Timer() {
    restart();
}

double Timer::measure() const {
    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed = end-start;
    return elapsed.count();
}

long Timer::measureMs() const {
    auto end = chrono::system_clock::now();
    auto elapsed =
        chrono::duration_cast<chrono::milliseconds>(end - start);
    return elapsed.count();
}

long Timer::measureUs() const {
    auto end = chrono::system_clock::now();
    auto elapsed =
        chrono::duration_cast<chrono::microseconds>(end - start);
    return elapsed.count();
}

long Timer::measureNs() const {
    auto end = chrono::system_clock::now();
    auto elapsed =
        chrono::duration_cast<chrono::nanoseconds>(end - start);
    return elapsed.count();
}

void Timer::restart() {
    start = chrono::system_clock::now();
}

string Timer::humanMeasure() const {
    long nanos = measureNs();
    long mikros = measureUs(); // need to for 32 bit systems
    long millis = measureMs(); // need to for 32 bit systems
    // check for millis to prevent overflow on 32 bit systems
    if (millis == 0 && nanos <= 999) {
      return format("%3dns", nanos);
    }
    if (millis == 0 && nanos <= 9999) {
      return format("%1d.%1dns", nanos/1000, (nanos/100) % 10);
    }
    if (millis == 0 && mikros <= 999) {
        return format("%3dus", mikros);
    }
    if (millis >= 1 && mikros <= 9999) {
        return format("%1d.%1dms", mikros/1000, (mikros/100) % 10);
    }
    if (millis <= 999) {
        return format("%3dms", millis);
    }
    if (millis <= 99999) {
        return format("%2d.%1ds", millis/1000, (millis/100) % 10);
    }
    long seconds = millis/1000;
    return format("%ds", seconds);
}

void schlafeMs(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void schlafeUs(int us) {
    std::this_thread::sleep_for(std::chrono::microseconds(us));
}
