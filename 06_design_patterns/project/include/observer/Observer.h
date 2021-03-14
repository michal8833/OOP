#pragma once

namespace observer {

    class Observer {
    public:
        virtual ~Observer() = default;
        virtual void notify(float value) = 0;
    };
}