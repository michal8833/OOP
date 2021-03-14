#include <vector>
#include <deque>
#include <set>
#include <gtest/gtest.h>
#include "Large.h"

TEST(LargeTest, LessThenOperator) {

    Large a{};
    Large b{};

    EXPECT_FALSE(a < b);
    EXPECT_FALSE(b < a);

    for(int i=0;i<128u*1024u;i++) {
        a.data[i] = b.data[i] = i+1;
    }

    EXPECT_FALSE(a < b);
    EXPECT_FALSE(b < a);

    a.data[3000] = 4000;

    EXPECT_FALSE(a < b);
    EXPECT_TRUE(b < a);

    b.data[2300] = 2500;

    EXPECT_TRUE(a < b);
    EXPECT_FALSE(b < a);
}

TEST(LargeTest, EqualityOperator) {

    Large a{};
    Large b{};

    EXPECT_TRUE(a == b);
    EXPECT_TRUE(b == a);

    for (int i = 0; i < 128u*1024u; i++) {
        a.data[i] = b.data[i] = i + 1;
    }

    EXPECT_TRUE(a == b);
    EXPECT_TRUE(b == a);

    a.data[135] = 3;

    EXPECT_FALSE(a == b);
    EXPECT_FALSE(b == a);

    b.data[135] = 3;

    EXPECT_TRUE(a == b);
    EXPECT_TRUE(b == a);

    a.clear();

    EXPECT_FALSE(a == b);
    EXPECT_FALSE(b == a);
}

TEST(LargeTest, HashFunction) {

    std::hash<Large> hash{};

    Large structures[4];

    double l = 1.0;

    for(auto & structure : structures) {
        for(int i=0;i<Large::SIZE;i++)
            structure.data[i] = l;

        l = l + 0.5;
    }

    std::set<std::size_t> set{};

    for(Large & structure : structures)
        set.insert(hash(structure));

    EXPECT_EQ(4, set.size());
}

