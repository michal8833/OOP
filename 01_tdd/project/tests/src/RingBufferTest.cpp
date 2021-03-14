#include "RingBuffer.h"
#include <gtest/gtest.h>

TEST(RingBuffer, Constructor) {

    RingBuffer ringBuffer{};
}

TEST(RingBuffer, Constructor_PassCapacityInConstructor) {

    RingBuffer ringBuffer{5};
}

TEST(RingBuffer, GetCapacity) {

    RingBuffer ringBuffer{5};
    EXPECT_EQ(5, ringBuffer.getCapacity());
}

TEST(RingBuffer, GetOtherCapacity) {

    RingBuffer ringBuffer{10};
    EXPECT_EQ(10, ringBuffer.getCapacity());
}

TEST(RingBuffer, AddFunction) {

    RingBuffer ringBuffer{5};
    ringBuffer.add(1);
}

TEST(RingBuffer, GetValueFunction) {

    RingBuffer ringBuffer{5};
    EXPECT_EQ(NULL, ringBuffer.getValue(0));
}

TEST(RingBuffer, AddOneValue) {

    RingBuffer ringBuffer{5};
    ringBuffer.add(1);
    EXPECT_EQ(1, ringBuffer.getValue(0));
}

TEST(RingBuffer, AddTwoValues) {

    RingBuffer ringBuffer{5};
    ringBuffer.add(1);
    ringBuffer.add(8);
    EXPECT_EQ(1, ringBuffer.getValue(0));
    EXPECT_EQ(8, ringBuffer.getValue(1));
}

TEST(RingBuffer, AddSixValues) {

    RingBuffer ringBuffer{5};
    ringBuffer.add(1);
    ringBuffer.add(2);
    ringBuffer.add(3);
    ringBuffer.add(4);
    ringBuffer.add(5);
    ringBuffer.add(6);
    EXPECT_EQ(6, ringBuffer.getValue(0));
    EXPECT_EQ(2, ringBuffer.getValue(1));
    EXPECT_EQ(3, ringBuffer.getValue(2));
    EXPECT_EQ(4, ringBuffer.getValue(3));
    EXPECT_EQ(5, ringBuffer.getValue(4));
}

TEST(RingBuffer, RemoveOneValue) {

    RingBuffer ringBuffer{5};
    ringBuffer.add(1);
    ringBuffer.add(2);
    ringBuffer.remove();
    EXPECT_EQ(NULL, ringBuffer.getValue(0));
    EXPECT_EQ(2, ringBuffer.getValue(1));
}

TEST(RingBuffer, ReturnRemovedValue) {

    RingBuffer ringBuffer{5};
    ringBuffer.add(1);
    ringBuffer.add(2);

    EXPECT_EQ(1, ringBuffer.remove());
}

TEST(RingBuffer, RemoveTwoValues) {

    RingBuffer ringBuffer{5};
    ringBuffer.add(1);
    ringBuffer.add(2);
    ringBuffer.remove();
    ringBuffer.remove();
    EXPECT_EQ(NULL, ringBuffer.getValue(0));
    EXPECT_EQ(NULL, ringBuffer.getValue(1));
}

TEST(RingBuffer, RemoveThreeValues) {

    RingBuffer ringBuffer{5};
    ringBuffer.add(1);
    ringBuffer.add(2);
    ringBuffer.add(3);
    ringBuffer.add(4);
    ringBuffer.add(5);
    ringBuffer.add(6);
    ringBuffer.add(7);
    ringBuffer.add(8);
    ringBuffer.remove();
    ringBuffer.remove();
    ringBuffer.remove();
    EXPECT_EQ(NULL, ringBuffer.getValue(0));
    EXPECT_EQ(7, ringBuffer.getValue(1));
    EXPECT_EQ(8, ringBuffer.getValue(2));
    EXPECT_EQ(NULL, ringBuffer.getValue(3));
    EXPECT_EQ(NULL, ringBuffer.getValue(4));
}

TEST(RingBuffer, RemoveThreeValuesThenAddThreeValues) {

    RingBuffer ringBuffer{5};
    ringBuffer.add(1);
    ringBuffer.add(2);
    ringBuffer.add(3);
    ringBuffer.add(4);
    ringBuffer.add(5);
    ringBuffer.add(6);
    ringBuffer.add(7);
    ringBuffer.add(8);

    EXPECT_EQ(4, ringBuffer.remove());
    EXPECT_EQ(5, ringBuffer.remove());
    EXPECT_EQ(6, ringBuffer.remove());

    ringBuffer.add(9);
    ringBuffer.add(10);
    ringBuffer.add(11);

    EXPECT_EQ(11, ringBuffer.getValue(0));
    EXPECT_EQ(7, ringBuffer.getValue(1));
    EXPECT_EQ(8, ringBuffer.getValue(2));
    EXPECT_EQ(9, ringBuffer.getValue(3));
    EXPECT_EQ(10, ringBuffer.getValue(4));
}





