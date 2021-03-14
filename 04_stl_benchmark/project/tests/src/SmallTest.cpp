#include <vector>
#include <deque>
#include <set>
#include <gtest/gtest.h>

#include "Small.h"

TEST(SmallTest, LessThenOperator) {

    Small a{};
    Small b{};

    EXPECT_FALSE(a < b);
    EXPECT_FALSE(b < a);

    a.data[0] = 1;
    b.data[0] = 2;

    EXPECT_TRUE(a < b);
    EXPECT_FALSE(b < a);

    a.data[0] = 3;
    b.data[0] = 3;

    EXPECT_FALSE(a < b);
    EXPECT_FALSE(b < a);
}

TEST(SmallTest, EqualityOperator) {

    Small a{};
    Small b{};

    EXPECT_TRUE(a == b);
    EXPECT_TRUE(b == a);

    a.data[0] = 1;
    b.data[0] = 2;

    EXPECT_FALSE(a == b);
    EXPECT_FALSE(b == a);

    a.data[0] = 3;
    b.data[0] = 3;

    EXPECT_TRUE(a == b);
    EXPECT_TRUE(b == a);
}

TEST(SmallTest, HashFunction) {

    std::hash<Small> hash{};

    Small structures[128];
    for(int i=0;i<128;i++)
        structures[i].data[0] = i;

    std::set<std::size_t> set{};

    for(Small & structure : structures)
        set.insert(hash(structure));

    EXPECT_EQ(128, set.size());
}


