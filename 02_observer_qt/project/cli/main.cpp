#include <QCoreApplication>
#include <QDebug>
#include <QObject>
#include <stdexcept>

#include "Acceleration.h"
#include "Displacement.h"
#include "Speed.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    observer::Displacement displacement;
    observer::Speed speed;
    observer::Acceleration acceleration;

    QObject::connect(&displacement, SIGNAL(send(float)),
                     &speed, SLOT(receive(float)));
    QObject::connect(&displacement, SIGNAL(send(float)),
                     &acceleration, SLOT(receive(float)));

    displacement.set(10.8);
    displacement.set(11.3);
    displacement.set(11.8);

    try {
        qDebug() << "Result: speed: " << speed.get() << ", acceleration: " << acceleration.get();
    } catch (std::runtime_error&) {
        qDebug() << "std::runtime_error exception";
    }

    displacement.set(12.3);
    displacement.set(13);

    try {
        qDebug() << "Result: speed: " << speed.get() << ", acceleration: " << acceleration.get();
    } catch (std::runtime_error&) {
        qDebug() << "std::runtime_error exception";
    }

    displacement.set(15);
    displacement.set(15);

    try {
        qDebug() << "Result: speed: " << speed.get() << ", acceleration: " << acceleration.get();
    } catch (std::runtime_error&) {
        qDebug() << "std::runtime_error exception";
    }

    displacement.set(15);
    displacement.set(13);

    try {
        qDebug() << "Result: speed: " << speed.get() << ", acceleration: " << acceleration.get();
    } catch (std::runtime_error&) {
        qDebug() << "std::runtime_error exception";
    }

    displacement.set(13);
    displacement.set(13);

    try {
        qDebug() << "Result: speed: " << speed.get() << ", acceleration: " << acceleration.get();
    } catch (std::runtime_error&) {
        qDebug() << "std::runtime_error exception";
    }

    return a.exec();
}

