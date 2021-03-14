#pragma once

#include <QObject>
#include <set>

namespace observer {

    class Speed : public QObject {
        Q_OBJECT
    public:
        Speed();
        float get();

    public slots:
        void receive(float value);

    private:
        float firstValue;
        float secondValue;

        bool hasFirstValue;
        bool hasSecondValue;
    };
}
