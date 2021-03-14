#pragma once

#include <random>
#include <cmath>

struct Large {

    constexpr static unsigned SIZE = 128u*1024u;

    double data[SIZE];

    void clear() {
        std::fill_n(data, SIZE, 0);
    }

    void rand() {
        static std::random_device rand{};
        static std::uniform_real_distribution<> dist{};

        for (double &i : data) {
            i = dist(rand);
        }
    }

    bool operator<(const Large &rhs) const {

        for(int i=0;i<SIZE;i++)
            if(!areEqual(data[i], rhs.data[i]))
                return data[i] < rhs.data[i];

        return false;
    }

    bool operator==(const Large &rhs) const {

        for(int i=0;i<SIZE;i++)
            if(!areEqual(data[i], rhs.data[i]))
                return false;

        return true;
    }

    static bool areEqual(double x, double y) {
        return std::fabs(x-y) <= std::numeric_limits<double>::epsilon() * std::fabs(x+y) * 2 || std::fabs(x-y) < std::numeric_limits<double>::min();
    }
};

namespace std {
    template<>
    struct hash<Large> {
        std::size_t operator()(const Large &d) const {

            std::hash<double> hash{};

            std::size_t sum = 0;
            for(double i : d.data)
                sum += hash(i);

            return sum;
        }
    };
}
