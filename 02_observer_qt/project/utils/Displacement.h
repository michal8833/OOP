#pragma once

#include <QObject>
#include <set>

namespace observer {

    class Displacement : public QObject {
        Q_OBJECT
    public:
        void set(float value);

    private:
        float value;

    signals:
        void send(float value);
    };
}
