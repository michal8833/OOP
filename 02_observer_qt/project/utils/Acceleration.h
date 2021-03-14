#pragma once

#include <QObject>
#include <set>

namespace observer {

    class Acceleration : public QObject {
        Q_OBJECT
    public:
        Acceleration();
        float get();

    public slots:
        void receive(float value);

    private:
        float firstValue;
        float secondValue;
        float thirdValue;

        bool hasFirstValue;
        bool hasSecondValue;
        bool hasThirdValue;
    };
}
