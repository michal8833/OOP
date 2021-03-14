#include "observer/Acceleration.h"
#include "observer/Displacement.h"
#include "observer/Speed.h"
#include <gtest/gtest.h>

TEST(Observer, SpeedAndAcceleration_MainTest) {

    observer::Displacement displacement;
    observer::Speed speed;
    observer::Acceleration acceleration;

    displacement.registerObserver(&speed);
    displacement.registerObserver(&acceleration);

    displacement.set(10);
    displacement.set(11);
    displacement.set(13);

    EXPECT_EQ(2.0, speed.get());
    EXPECT_EQ(1.0, acceleration.get());
}

TEST(Observer, SpeedAndAcceleration_DifferentDisplacementValues) {

    observer::Displacement displacement;
    observer::Speed speed;
    observer::Acceleration acceleration;

    displacement.registerObserver(&speed);
    displacement.registerObserver(&acceleration);

    displacement.set(0);
    displacement.set(1.3);
    displacement.set(4.7);
    displacement.set(8.2);
    displacement.set(8.8);
    displacement.set(9.1);

    EXPECT_NEAR(0.3, speed.get(), 0.01);
    EXPECT_NEAR(-0.3, acceleration.get(), 0.01);
}

TEST(Observer, SpeedAndAcceleration_NegativeResults) {

    observer::Displacement displacement;
    observer::Speed speed;
    observer::Acceleration acceleration;

    displacement.registerObserver(&speed);
    displacement.registerObserver(&acceleration);

    displacement.set(5);
    displacement.set(10);
    displacement.set(17);
    displacement.set(2);

    EXPECT_EQ(-15.0, speed.get());
    EXPECT_EQ(-22.0, acceleration.get());
}

TEST(Observer, SpeedAndAcceleration_ThrowException) {

    observer::Displacement displacement;
    observer::Speed speed;
    observer::Acceleration acceleration;

    displacement.registerObserver(&speed);
    displacement.registerObserver(&acceleration);

    float s = 0.0;
    float a = 0.0;

    bool exception = false;

    try {
        s = speed.get();
        a = acceleration.get();
    }
    catch (std::runtime_error&) {
        exception = true;
    }

    EXPECT_TRUE(exception);
    exception = false;

    displacement.set(10);

    try {
        s = speed.get();
        a = acceleration.get();
    }
    catch (std::runtime_error&) {
        exception = true;
    }

    EXPECT_TRUE(exception);
    exception = false;

    displacement.set(11);

    try {
        s = speed.get();
        a = acceleration.get();
    }
    catch (std::runtime_error&) {
        exception = true;
    }

    EXPECT_TRUE(exception);
    exception = false;
    EXPECT_EQ(1.0, s);

    displacement.set(13);

    try {
        s = speed.get();
        a = acceleration.get();
    }
    catch (std::runtime_error&) {
        exception = true;
    }

    EXPECT_FALSE(exception);
    EXPECT_EQ(2.0, s);
    EXPECT_EQ(1.0, a);
}

TEST(Observer, SpeedAndAcceleration_DisplacementNotChanging) {

    observer::Displacement displacement;
    observer::Speed speed;
    observer::Acceleration acceleration;

    displacement.registerObserver(&speed);
    displacement.registerObserver(&acceleration);

    displacement.set(10);
    displacement.set(10);
    displacement.set(10);
    displacement.set(10);
    displacement.set(10);
    displacement.set(10);

    EXPECT_EQ(0.0, speed.get());
    EXPECT_EQ(0.0, acceleration.get());
}

