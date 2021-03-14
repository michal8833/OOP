#include <QtTest>
#include "Acceleration.h"

class AccelerationTest : public QObject
{
    Q_OBJECT

private slots:
    void ThrowException() {

        observer::Acceleration acceleration{};
        float accelerationValue;

        bool exception = false;

        try {
            accelerationValue = acceleration.get();
        } catch (std::runtime_error&) {
            exception = true;
        }

        QCOMPARE(true, exception);

        exception = false;
        acceleration.receive(1);

        try {
            accelerationValue = acceleration.get();
        } catch (std::runtime_error&) {
            exception = true;
        }

        QCOMPARE(true, exception);

        exception = false;
        acceleration.receive(2);

        try {
            accelerationValue = acceleration.get();
        } catch (std::runtime_error&) {
            exception = true;
        }

        QCOMPARE(true, exception);
        exception = false;
        acceleration.receive(4);

        try {
            accelerationValue = acceleration.get();
        } catch (std::runtime_error&) {
            exception = true;
        }

        QCOMPARE(false, exception);

        QCOMPARE(1.0, accelerationValue);
    }

    void ReceiveExampleValues() {

        observer::Acceleration acceleration{};

        acceleration.receive(3);
        acceleration.receive(4);
        acceleration.receive(5);

        QCOMPARE(0.0, acceleration.get());

        acceleration.receive(6);
        acceleration.receive(8);

        QCOMPARE(1.0, acceleration.get());

        acceleration.receive(10);
        acceleration.receive(12);

        QCOMPARE(0.0, acceleration.get());

        acceleration.receive(14);
        acceleration.receive(20);

        QCOMPARE(4.0, acceleration.get());

        acceleration.receive(25);
        acceleration.receive(26);

        QCOMPARE(-4.0, acceleration.get());
    }

    void ReceiveOtherValues() {

        observer::Acceleration acceleration{};

        acceleration.receive(11.4);
        acceleration.receive(12.0);
        acceleration.receive(12.6);

        QVERIFY(qFuzzyCompare((float)0.0, acceleration.get()));

        acceleration.receive(13.2);
        acceleration.receive(13.9);

        QVERIFY(qFuzzyCompare((float)0.1, acceleration.get()));

        acceleration.receive(15.0);
        acceleration.receive(16.1);

        QVERIFY(qFuzzyCompare((float)0.0, acceleration.get()));

        acceleration.receive(18.0);
        acceleration.receive(25.3);

        QVERIFY(qFuzzyCompare((float)5.4, acceleration.get()));

        acceleration.receive(28.9);
        acceleration.receive(29.8);

        QVERIFY(qFuzzyCompare((float)(-2.7), acceleration.get()));
    }

};

QTEST_APPLESS_MAIN(AccelerationTest)

#include "tst_accelerationtest.moc"
