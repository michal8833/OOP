#include <QtTest>
#include <QDebug>
#include "Acceleration.h"
#include "Displacement.h"
#include "Speed.h"

class DisplacementTest : public QObject
{
    Q_OBJECT

private slots:
    void Set_NotEnoughValues() {

        observer::Displacement displacement;
        observer::Speed speed;
        observer::Acceleration acceleration;

        QObject::connect(&displacement, SIGNAL(send(float)),
                         &speed, SLOT(receive(float)));
        QObject::connect(&displacement, SIGNAL(send(float)),
                         &acceleration, SLOT(receive(float)));

        bool speedException, accelerationException;
        speedException = accelerationException = false;

        try {
            speed.get();
        } catch (std::runtime_error&) {
            speedException = true;
        }

        try {
            acceleration.get();
        } catch (std::runtime_error&) {
            accelerationException = true;
        }

        QCOMPARE(true, speedException);
        QCOMPARE(true, accelerationException);

        speedException = accelerationException = false;
        displacement.set(1);

        try {
            speed.get();
        } catch (std::runtime_error&) {
            speedException = true;
        }

        try {
            acceleration.get();
        } catch (std::runtime_error&) {
            accelerationException = true;
        }

        QCOMPARE(true, speedException);
        QCOMPARE(true, accelerationException);

        speedException = accelerationException = false;
        displacement.set(2);

        try {
            speed.get();
        } catch (std::runtime_error&) {
            speedException = true;
        }

        try {
            acceleration.get();
        } catch (std::runtime_error&) {
            accelerationException = true;
        }

        QCOMPARE(false, speedException);
        QCOMPARE(true, accelerationException);

        speedException = accelerationException = false;
        displacement.set(4);

        try {
            speed.get();
        } catch (std::runtime_error&) {
            speedException = true;
        }

        try {
            acceleration.get();
        } catch (std::runtime_error&) {
            accelerationException = true;
        }

        QCOMPARE(false, speedException);
        QCOMPARE(false, accelerationException);

        QCOMPARE(2.0, speed.get());
        QCOMPARE(1.0, acceleration.get());
    }

    void Set_ExampleValues() {

        observer::Displacement displacement;
        observer::Speed speed;
        observer::Acceleration acceleration;

        QObject::connect(&displacement, SIGNAL(send(float)),
                         &speed, SLOT(receive(float)));
        QObject::connect(&displacement, SIGNAL(send(float)),
                         &acceleration, SLOT(receive(float)));

        displacement.set(1);
        displacement.set(2);
        displacement.set(4);

        QCOMPARE(2.0, speed.get());
        QCOMPARE(1.0, acceleration.get());

        displacement.set(5);
        displacement.set(6);
        displacement.set(7);

        QCOMPARE(1.0, speed.get());
        QCOMPARE(0.0, acceleration.get());

        displacement.set(1);
        displacement.set(2);
        displacement.set(4);

        QCOMPARE(2.0, speed.get());
        QCOMPARE(1.0, acceleration.get());

        displacement.set(10);
        displacement.set(12);
        displacement.set(17);

        QCOMPARE(5.0, speed.get());
        QCOMPARE(3.0, acceleration.get());

        displacement.set(20);
        displacement.set(25);
        displacement.set(27);

        QCOMPARE(2.0, speed.get());
        QCOMPARE(-3.0, acceleration.get());

        displacement.set(145);
        displacement.set(145);
        displacement.set(145);

        QCOMPARE(0.0, speed.get());
        QCOMPARE(0.0, acceleration.get());
    }

    void Set_OtherValues() {

        observer::Displacement displacement;
        observer::Speed speed;
        observer::Acceleration acceleration;

        QObject::connect(&displacement, SIGNAL(send(float)),
                         &speed, SLOT(receive(float)));
        QObject::connect(&displacement, SIGNAL(send(float)),
                         &acceleration, SLOT(receive(float)));

        displacement.set(6.4);
        displacement.set(7.0);
        displacement.set(7.6);

        QVERIFY(qFuzzyCompare((float)0.6, speed.get()));
        QVERIFY(qFuzzyCompare((float)0.0, acceleration.get()));

        displacement.set(8.0);
        displacement.set(8.8);
        displacement.set(10.4);

        QVERIFY(qFuzzyCompare((float)1.6, speed.get()));
        QVERIFY(qFuzzyCompare((float)0.8, acceleration.get()));

        displacement.set(10.2);
        displacement.set(11);
        displacement.set(12.1);

        QVERIFY(qFuzzyCompare((float)1.1, speed.get()));
        QVERIFY(qFuzzyCompare((float)0.3, acceleration.get()));

        displacement.set(10.9);
        displacement.set(15.3);
        displacement.set(25.55);

        QVERIFY(qFuzzyCompare((float)10.25, speed.get()));
        QVERIFY(qFuzzyCompare((float)5.85, acceleration.get()));

        displacement.set(20);
        displacement.set(23.2);
        displacement.set(21.0);

        QVERIFY(qFuzzyCompare((float)(-2.2), speed.get()));
        QVERIFY(qFuzzyCompare((float)(-5.4), acceleration.get()));

        displacement.set(76.345);
        displacement.set(76.345);
        displacement.set(76.345);

        QVERIFY(qFuzzyCompare((float)0.0, speed.get()));
        QVERIFY(qFuzzyCompare((float)0.0, acceleration.get()));
    }

};

QTEST_APPLESS_MAIN(DisplacementTest)

#include "tst_displacementtest.moc"
