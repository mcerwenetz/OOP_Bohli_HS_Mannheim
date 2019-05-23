#include <iostream>
#include "gtest/gtest.h"
#include "alltest.h"
#include "Texter.h"
using namespace std;

// EXPECT_EQ(a, b): a und b müssen gleich sein, sonst Fehler
// ASSERT_EQ(a, b): a und b müssen gleich sein, sonst Fehler und Abbruch

TEST(AllTest, construct1) {
    Texter t;
    Texter a("a");
    Texter b("b");
    Texter b2(nullptr, "b2");
    Texter c("ab", "c");
    
    EXPECT_EQ(nullptr, t.first());
    EXPECT_EQ(nullptr, t.second());
    EXPECT_STREQ("a", a.first());
    EXPECT_EQ(nullptr, a.second());
    EXPECT_STREQ("b", b.first());
    EXPECT_EQ(nullptr, b.second());
    EXPECT_EQ(nullptr, b2.first());
    EXPECT_STREQ("b2", b2.second());
    EXPECT_STREQ("ab", c.first());
    EXPECT_STREQ("c", c.second());    
}

TEST(AllTest, construct2) {
    Texter t;
    Texter t2(t);
    Texter a("a");
    Texter a2(a);
    Texter ab("a", "b");
    Texter ab2(ab);
    
    EXPECT_EQ(nullptr, t.first());
    EXPECT_EQ(nullptr, t.second());
    EXPECT_EQ(nullptr, t2.first());
    EXPECT_EQ(nullptr, t2.second());
    EXPECT_STREQ("a", a.first());
    EXPECT_EQ(nullptr, a.second());
    EXPECT_STREQ("a", a2.first());
    EXPECT_EQ(nullptr, a2.second());
    EXPECT_STREQ(a.first(), a2.first());
    EXPECT_STREQ("a", ab.first());
    EXPECT_STREQ("b", ab.second());
    EXPECT_STREQ("a", ab2.first());
    EXPECT_STREQ("b", ab2.second());
    EXPECT_STREQ(ab.first(), ab2.first());
    EXPECT_STREQ(ab.second(), ab2.second());
}

TEST(AllTest, assign1) {
    Texter t;
    Texter a("a");
    Texter ab("a", "b");
    EXPECT_STREQ("a", a.first());
    EXPECT_STREQ("a", ab.first());
    EXPECT_STREQ("b", ab.second());
    a = ab;
    EXPECT_STREQ(ab.first(), a.first());
    EXPECT_STREQ(ab.second(), a.second());
    t = a;
    EXPECT_STREQ(t.first(), a.first());
    EXPECT_STREQ(t.second(), a.second());    
    Texter b("b");
    Texter ba("b", "a");
    ba = b;
    EXPECT_STREQ(ba.first(), b.first());
    EXPECT_EQ(nullptr, ba.second());
    Texter t2;
    t = t2;
    EXPECT_EQ(nullptr, t.first());    
    EXPECT_EQ(nullptr, t.second());    
}

TEST(AllTest, length) {
    Texter t1("ab", "cde");
    EXPECT_EQ(5, t1.entire_length());
    EXPECT_EQ(2, t1.length_smallest());
    EXPECT_EQ(3, t1.length_largest());
    Texter t2("ab");
    EXPECT_EQ(2, t2.entire_length());
    EXPECT_EQ(0, t2.length_smallest());
    EXPECT_EQ(2, t2.length_largest());
    Texter t3(nullptr, "abc");
    EXPECT_EQ(3, t3.entire_length());
    EXPECT_EQ(0, t3.length_smallest());
    EXPECT_EQ(3, t3.length_largest());    
}

TEST(AllTest, flip) {
    const char *s1 = "a";
    const char *s2 = "bc";
    Texter t(s1, s2);
    EXPECT_STREQ(s1, t.first());
    EXPECT_STREQ(s2, t.second());
    t.flip();
    EXPECT_STREQ(s2, t.first());
    EXPECT_STREQ(s1, t.second());
    t.flip();
    EXPECT_STREQ(s1, t.first());
    EXPECT_STREQ(s2, t.second());
    Texter te(nullptr, s2);
    EXPECT_EQ(nullptr, te.first());
    EXPECT_STREQ(s2, te.second());
    te.flip();
    EXPECT_STREQ(s2, te.first());
    EXPECT_EQ(nullptr, te.second());
    te.flip();
    EXPECT_EQ(nullptr, te.first());
    EXPECT_STREQ(s2, te.second());
}

TEST(AllTest, merge) {
    const char *s1 = "a";
    const char *s2 = "bc";
    const char *s3 = "abc";
    const char *s4 = "bca";
    Texter t1(s1, s2);
    t1.merge();
    EXPECT_STREQ(s3, t1.first());
    EXPECT_EQ(nullptr, t1.second());
    Texter t2(s2, s1);
    t2.merge();
    EXPECT_STREQ(s4, t2.first());
    EXPECT_EQ(nullptr, t2.second());
    Texter t3(s1);
    t2.merge();
    EXPECT_STREQ(s1, t3.first());
    EXPECT_EQ(nullptr, t3.second());
    Texter t4(nullptr, s1);
    t4.merge();
    EXPECT_STREQ(s1, t4.first());
    EXPECT_EQ(nullptr, t4.second());
}

TEST(AllTest, swap_both) {
    const char *a = "a";
    const char *b = "bb";
    const char *c = "ccc";
    const char *d = "dddd";
    {
        Texter t(a, b);
        Texter s(c, d);
        t.swap_both(s);
        EXPECT_STREQ(a, s.first());
        EXPECT_STREQ(b, s.second());
        EXPECT_STREQ(c, t.first());
        EXPECT_STREQ(d, t.second());
    }
}

TEST(AllTest, swap_largest_length1) {
    const char *a = "a";
    const char *b = "bb";
    const char *c = "ccc";
    const char *d = "dddd";
    {
        Texter t(a, b);
        Texter s(c, d);
        t.swap_largest_length(s);
        EXPECT_STREQ(a, t.first());
        EXPECT_STREQ(d, t.second());
        EXPECT_STREQ(c, s.first());
        EXPECT_STREQ(b, s.second());
    }
}

TEST(AllTest, swap_largest_length2) {
    const char *a = "a";
    const char *b = "bb";
    const char *c = "ccc";
    const char *d = "dddd";
    {
        Texter t(b, a);
        Texter s(c, d);
        t.swap_largest_length(s);
        EXPECT_STREQ(d, t.first());
        EXPECT_STREQ(a, t.second());
        EXPECT_STREQ(c, s.first());
        EXPECT_STREQ(b, s.second());
    }
    {
        Texter t(b, a);
        Texter s(d, c);
        t.swap_largest_length(s);
        EXPECT_STREQ(d, t.first());
        EXPECT_STREQ(a, t.second());
        EXPECT_STREQ(b, s.first());
        EXPECT_STREQ(c, s.second());
    }
}

TEST(AllTest, opequals) {
    const char *a = "a";
    const char *b = "b";
    { Texter s(a, b), t(a, b); EXPECT_EQ(true, s==t); }
    { Texter s(a, nullptr), t(a, nullptr); EXPECT_EQ(true, s==t); }
    { Texter s(nullptr, b), t(nullptr, b); EXPECT_EQ(true, s==t); }
    { Texter s(nullptr, nullptr), t(nullptr, nullptr); EXPECT_EQ(true, s==t); }
    { Texter s(a, b), t(b, a); EXPECT_EQ(false, s==t); }
    { Texter s(a, b), t(a, a); EXPECT_EQ(false, s==t); }
    { Texter s(b, a), t(a, a); EXPECT_EQ(false, s==t); }
    { Texter s(a, b), t(a, nullptr); EXPECT_EQ(false, s==t); }
    { Texter s(nullptr, b), t(a, b); EXPECT_EQ(false, s==t); }
    { Texter s(nullptr, a), t(a, nullptr); EXPECT_EQ(false, s==t); }
    { Texter s(nullptr, nullptr), t(a, nullptr); EXPECT_EQ(false, s==t); }
    { Texter s(nullptr, a), t(nullptr, nullptr); EXPECT_EQ(false, s==t); }
}
