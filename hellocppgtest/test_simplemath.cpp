#include "gtest/gtest.h"
#include "simplemath.h"

TEST(testMath, einfach) {
    EXPECT_EQ(100, quadrat(10));
    EXPECT_EQ(1000, kubik(10));
    EXPECT_EQ(10000, hoch4(10));
}

TEST(testMath, mehr) {
    for (int i=-100; i < 100; i+=1) {
        ASSERT_EQ(i*i, quadrat(i));
        ASSERT_EQ(i*i*i, kubik(i));
        ASSERT_EQ(i*i*i*i, hoch4(i));
    }
}
