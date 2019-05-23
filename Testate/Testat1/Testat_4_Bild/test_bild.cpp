#include <iostream>
#include <iomanip>
#include "gtest/gtest.h"
#include "alltest.h"
#include "Bild.h"
using namespace std;

// EXPECT_EQ(a, b): a und b müssen gleich sein, sonst Fehler
// ASSERT_EQ(a, b): a und b müssen gleich sein, sonst Fehler und Abbruch

void range_expect(const unsigned char *mem,
                  unsigned int from, unsigned int to,
                  unsigned char value);
void range_assert(const unsigned char *mem,
                  unsigned int from, unsigned int to,
                  unsigned char value);
void range_expects(const unsigned char *mem,
                   unsigned int from, unsigned int to,
                   const unsigned char *values);
void range_asserts(const unsigned char *mem,
                   unsigned int from, unsigned int to,
                   const unsigned char *values);
void show_memblock(const Bild &b); // zeigt Inhalt des Bilds


TEST(none, construct1) { // ohne Speicherleackcheck
    Bild b;    
    ASSERT_EQ(b.breite(), 4);
    ASSERT_EQ(b.hoehe(), 3);
    int from=0, to=12;
    unsigned char*mem = b.get_img();
    while (from < to) { // musn't use SuspendMemCheck
        ASSERT_EQ(*(mem+from), 0);
        from += 1;
    }
}

TEST_F(AllTest, construct2) { // ab hier alle mit Speicherleakcheck
    Bild b;    
    { SuspendMemCheck smc;
        ASSERT_EQ(b.breite(), 4);
        ASSERT_EQ(b.hoehe(), 3);
    }
    range_assert(b.get_img(), 0, 12, 0x00);
}

TEST_F(AllTest, sizear) {
    const double EPS=0.01;
    Bild b1, b2(16, 9), b3(3000,2000);
    { SuspendMemCheck smc;
        ASSERT_EQ(b1.breite(), 4);
        ASSERT_EQ(b1.hoehe(), 3);
        ASSERT_EQ(b2.breite(), 16);
        ASSERT_EQ(b2.hoehe(), 9);
        ASSERT_EQ(b3.breite(), 3000);
        ASSERT_EQ(b3.hoehe(), 2000);
        ASSERT_EQ(b1.size(), 12);
        ASSERT_EQ(b2.size(), 144);
        ASSERT_EQ(b3.size(), 6000000);
    }
    { SuspendMemCheck smc;
        EXPECT_NEAR(b1.aspect_ratio(), 1.333, EPS);
        EXPECT_NEAR(b2.aspect_ratio(), 1.777, EPS);
        EXPECT_NEAR(b3.aspect_ratio(), 1.5, EPS);
    }
}

TEST_F(AllTest, atfill) {
    Bild b(4, 3);
    range_assert(b.get_img(), 0, 12, 0x00);
    unsigned char g = 0xab;
    b.fuelle(g);
    range_expect(b.get_img(), 0, 12, g);
    for (unsigned int r=0; r<b.hoehe(); r+=1) {
        for (unsigned int c=0; c<b.breite(); c+=1) {
            { SuspendMemCheck smc;
                ASSERT_EQ(b.at(r, c), g);
            }
        }
    }
}

void fill_consecutive(Bild &b, unsigned char sc);
void check_consecutive(const Bild &b, unsigned char sc);
TEST_F(AllTest, atreadwrite) {
    Bild b(4, 3);
    fill_consecutive(b, 17);
    check_consecutive(b, 17);
    { SuspendMemCheck smc;
        const Bild &c=b;
        ASSERT_EQ(c.at(4, 3), 0x00);
        ASSERT_EQ(c.at(1000, 3000), 0x00);
    }    
}

TEST_F(AllTest, copy) {
    Bild b1(7, 6);
    fill_consecutive(b1, 6);
    check_consecutive(b1, 6);
    Bild b2(b1);
    check_consecutive(b2, 6);
    { SuspendMemCheck smc;
        ASSERT_EQ(7, b1.breite());
        ASSERT_EQ(6, b1.hoehe());
        ASSERT_EQ(b2.breite(), b1.breite());
        ASSERT_EQ(b2.hoehe(), b1.hoehe());
    }    
}

TEST_F(AllTest, assign) {
    Bild b1(7, 6);
    fill_consecutive(b1, 1);
    check_consecutive(b1, 1);
    Bild b2(5, 3);
    fill_consecutive(b2, 42);
    check_consecutive(b2, 42);
    b2 = b1;
    { SuspendMemCheck smc;
        EXPECT_EQ(b1.size(), b2.size());
        EXPECT_EQ(b1.hoehe(), b2.hoehe());
        EXPECT_EQ(b1.breite(), b2.breite());
    }
    check_consecutive(b2, 1);    
    b2 = b2; // self
    check_consecutive(b2, 1);    
}

void check_zeile(const Bild &b, unsigned int zeile, unsigned char sc);
void check_spalte(const Bild &b, unsigned int spalte, unsigned char sc);
TEST_F(AllTest, zeilespalte) {
    Bild b(4, 3);
    fill_consecutive(b, 42);
    b.spalte(0, 1);
    b.spalte(1, 2);
    b.spalte(2, 3);
    b.spalte(3, 4);
    check_spalte(b, 0, 1);
    check_spalte(b, 1, 2);
    check_spalte(b, 2, 3);
    check_spalte(b, 3, 4);
    fill_consecutive(b, 42);
    b.zeile(0, 1);
    b.zeile(1, 2);
    b.zeile(2, 3);
    check_zeile(b, 0, 1);
    check_zeile(b, 1, 2);
    check_zeile(b, 2, 3);
}

TEST_F(AllTest, breiter) {
    Bild b(4, 3);
    b.fuelle(1);
    // show_memblock(b);
    b.breiter(2);
    // show_memblock(b);
    { SuspendMemCheck smc;
        ASSERT_EQ(15, b.size());
        ASSERT_EQ(5, b.breite());
        ASSERT_EQ(3, b.hoehe());
        check_spalte(b, 4, 2);
    }    
    b.breiter(3);
    { SuspendMemCheck smc;
        ASSERT_EQ(18, b.size());
        ASSERT_EQ(6, b.breite());
        ASSERT_EQ(3, b.hoehe());
        check_spalte(b, 5, 3);
    }    
    b.breiter(4);
    { SuspendMemCheck smc;
        ASSERT_EQ(21, b.size());
        ASSERT_EQ(7, b.breite());
        ASSERT_EQ(3, b.hoehe());
        check_spalte(b, 6, 4);
    }
}

TEST_F(AllTest, flip) {
    Bild b1(4, 3), b2(5, 6);
    fill_consecutive(b1, 1);
    fill_consecutive(b2, 42);
    { SuspendMemCheck smc;
        ASSERT_EQ(4, b1.breite());
        ASSERT_EQ(3, b1.hoehe());
        ASSERT_EQ(5, b2.breite());
        ASSERT_EQ(6, b2.hoehe());
    }
    b1.flip(b2);
    { SuspendMemCheck smc;
        ASSERT_EQ(5, b1.breite());
        ASSERT_EQ(6, b1.hoehe());
        ASSERT_EQ(4, b2.breite());
        ASSERT_EQ(3, b2.hoehe());
    }
    check_consecutive(b2, 1);
    check_consecutive(b1, 42);    
}


void range_expect(const unsigned char *mem,
                  unsigned int from, unsigned int to,
                  unsigned char value) {
    while (from < to) {
        { SuspendMemCheck smc;
            EXPECT_EQ((int) *(mem+from), (int) value);
        }
        from += 1;
    }
}

void range_assert(const unsigned char *mem,
                  unsigned int from, unsigned int to,
                  unsigned char value) {
    while (from < to) {
        { SuspendMemCheck smc;
            ASSERT_EQ((int) *(mem+from), (int) value);
        }
        from += 1;
    }
}

void range_expects(const unsigned char *mem,
                   unsigned int from, unsigned int to,
                   const unsigned char *values) {
    while (from < to) {
        { SuspendMemCheck smc;
            EXPECT_EQ((int) *(mem+from), (int) *(values+from));
        }
        from += 1;
    }
}

void range_asserts(const unsigned char *mem,
                   unsigned int from, unsigned int to,
                   const unsigned char *values) {
    while (from < to) {
        { SuspendMemCheck smc;
            ASSERT_EQ((int) *(mem+from), (int) *(values+from));
        }
        from += 1;
    }
}

void fill_consecutive(Bild &b, unsigned char sc) {
    for (unsigned int x=0; x < b.breite(); x+=1) {
        for (unsigned int y=0; y < b.hoehe(); y+=1) {
            b.at(y, x) = sc;
            sc += 1;
        }
    }
}

void check_consecutive(const Bild &b, unsigned char sc) {
    for (unsigned int x=0; x < b.breite(); x+=1) {
        for (unsigned int y=0; y < b.hoehe(); y+=1) {
            { SuspendMemCheck smc;
                ASSERT_EQ((int) b.at(y, x), (int) sc);
            }
            sc += 1;
        }
    }
}

void check_spalte(const Bild &b, unsigned int spalte, unsigned char sc) {
    for (unsigned int y=0; y < b.hoehe(); y+=1) {
        { SuspendMemCheck smc;
            ASSERT_EQ((int) b.at(y, spalte), (int) sc);
        }
    }
}

void check_zeile(const Bild &b, unsigned int zeile, unsigned char sc) {
    for (unsigned int x=0; x < b.breite(); x+=1) {
        { SuspendMemCheck smc;
            ASSERT_EQ((int) b.at(zeile, x), (int) sc);
        }
    }
}

void show_memblock(const Bild &b) {
    for (unsigned int y=0; y < b.hoehe(); y+=1) {
        for (unsigned int x=0; x < b.breite(); x+=1) {
            std::cout << setw(3) << ((int) b.at(y, x)) << " ";
        }
        std::cout << std::endl;
    }
}
