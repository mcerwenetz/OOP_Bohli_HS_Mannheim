#include "gtest/gtest.h"
#include "alltest.h"
#include "Bruch.h"

TEST(bruch, einfach) {
    Bruch b(3, 1);
    EXPECT_EQ(3, b.zaehler());
    EXPECT_EQ(1, b.nenner());
}

TEST(bruch, normalisieren) {
    Bruch b1(4, 2);
    EXPECT_EQ(2, b1.zaehler());
    EXPECT_EQ(1, b1.nenner());
    Bruch b2(9, 12);
    EXPECT_EQ(3, b2.zaehler());
    EXPECT_EQ(4, b2.nenner());
    Bruch b3(10, 10);
    EXPECT_EQ(1, b3.zaehler());
    EXPECT_EQ(1, b3.nenner());
    Bruch b4(-6, 2);
    EXPECT_EQ(-3, b4.zaehler());
    EXPECT_EQ(1, b4.nenner());
    Bruch b5(6, -2);
    EXPECT_EQ(-3, b5.zaehler());
    EXPECT_EQ(1, b5.nenner());
}

TEST(bruch, gleichheit) {
    Bruch b1(1, 2);
    EXPECT_EQ(b1, Bruch(1, 2));
    EXPECT_EQ(Bruch(1, 2), Bruch(1, 2));
    EXPECT_EQ(Bruch(1, 2), Bruch(2, 4));
    EXPECT_EQ(Bruch(2, 4), Bruch(1, 2));
    EXPECT_EQ(Bruch(2, -4), Bruch(-1, 2));
}

TEST(bruch, copyassign) {
    Bruch b1(1, 2);
    Bruch b2(b1);
    EXPECT_EQ(b2, b1);
    Bruch b3(1, 1);
    EXPECT_NE(b3, b1);
    b3 = b2;
    EXPECT_EQ(b3, b1);
}

TEST(bruch, malgleich) {
    Bruch b1(2, 1);
    b1 *= 1;
    EXPECT_EQ(Bruch(2, 1), b1);
    b1 *= 2;
    EXPECT_EQ(Bruch(4, 1), b1);
    b1 *= 3;
    EXPECT_EQ(Bruch(12, 1), b1);
    b1 *= 4;
    EXPECT_EQ(Bruch(48, 1), b1);
}

TEST(bruch, mal) {
    Bruch b1(2, 1);
    Bruch b1c(2, 1);
    Bruch b2(3, 4);
    Bruch b2c(3, 4);
    EXPECT_EQ(Bruch(3, 2), b1*b2);
    EXPECT_EQ(b1c, b1); // no change
    EXPECT_EQ(b2c, b2); // no change
    EXPECT_EQ(Bruch(3, 2), b2*2);
    EXPECT_EQ(Bruch(3, 2), 2*b2);
    EXPECT_EQ(b2c, b2); // no change
}

TEST(bruch, mixint) {
    Bruch b1(2, 1);
    Bruch b2(3, 4);
    EXPECT_EQ(Bruch(4, 1), b1 * 2);
    EXPECT_EQ(Bruch(4, 1), 2 * b1);
    EXPECT_EQ(true, Bruch(2, 1) == b1);
    EXPECT_EQ(true, Bruch(2, 1) == 2);
    EXPECT_EQ(true, 2 == Bruch(2, 1));
    EXPECT_EQ(true, Bruch(2, 1) != b2);
    EXPECT_EQ(true, Bruch(2, 1) != 3);
    EXPECT_EQ(true, 3 != Bruch(2, 1));
}
