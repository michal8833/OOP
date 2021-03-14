#include <QtTest>
#include <stdexcept>
#include "Speed.h"

class SpeedTest : public QObject
{
    Q_OBJECT

private slots:
    void ThrowException() {

        observer::Speed speed{};
        float speedValue;

        bool exception = false;

        try {
            speedValue = speed.get();
        } catch (std::runtime_error&) {
            exception = true;
        }

        QCOMPARE(true, exception);

        exception = false;
        speed.receive(1);

        try {
            speedValue = speed.get();
        } catch (std::runtime_error&) {
            exception = true;
        }

        QCOMPARE(true, exception);

        exception = false;
        speed.receive(2);

        try {
            speedValue = speed.get();
        } catch (std::runtime_error&) {
            exception = true;
        }

        QCOMPARE(false, exception);
        QCOMPARE(1.0, speedValue);
    }

    void ReceiveExampleValues() {

        observer::Speed speed{};

        speed.receive(3);
        speed.receive(4);

        QCOMPARE(1.0, speed.get());

        speed.receive(5);

        QCOMPARE(1.0, speed.get());

        speed.receive(7);

        QCOMPARE(2.0, speed.get());

        speed.receive(6);

        QCOMPARE(-1.0, speed.get());

        speed.receive(6);

        QCOMPARE(0.0, speed.get());

    }

    void ReceiveOtherValues() {

        observer::Speed speed{};

        speed.receive(1.2);
        speed.receive(2.5);

        QVERIFY(qFuzzyCompare((float)1.3, speed.get()));

        speed.receive(3.8);

        QVERIFY(qFuzzyCompare((float)1.3, speed.get()));

        speed.receive(6.3);

        QVERIFY(qFuzzyCompare((float)2.5, speed.get()));

        speed.receive(5.9);

        QVERIFY(qFuzzyCompare((float)(-0.4), speed.get()));

        speed.receive(5.9);

        QVERIFY(qFuzzyCompare((float)0.0, speed.get()));

    }

};

QTEST_APPLESS_MAIN(SpeedTest)

#include "tst_speedtest.moc"
