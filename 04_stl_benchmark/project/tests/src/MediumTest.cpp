#include <vector>
#include <deque>
#include <set>
#include <gtest/gtest.h>

#include "Medium.h"

TEST(MediumTest, LessThenOperator) {

    Medium a{};
    Medium b{};

    EXPECT_FALSE(a < b);
    EXPECT_FALSE(b < a);

    for(int i=0;i<256;i++) {
        a.data[i] = b.data[i] = i+1;
    }

    EXPECT_FALSE(a < b);
    EXPECT_FALSE(b < a);

    a.data[16] = 100;

    EXPECT_FALSE(a < b);
    EXPECT_TRUE(b < a);

    b.data[10] = 100;

    EXPECT_TRUE(a < b);
    EXPECT_FALSE(b < a);
}

TEST(MediumTest, EqualityOperator) {

    Medium a{};
    Medium b{};

    EXPECT_TRUE(a == b);
    EXPECT_TRUE(b == a);

    for (int i = 0; i < 256; i++) {
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

TEST(MediumTest, HashFunction) {

    std::hash<Medium> hash{};

    Medium structures[128];

    int l=1;

    for(auto & structure : structures) {
        for(int i=0;i<Medium::SIZE;i++)
            structure.data[i] = l;

        l++;
    }

    std::set<std::size_t> set{};

    for(Medium & structure : structures)
        set.insert(hash(structure));

    EXPECT_EQ(128, set.size());
}
