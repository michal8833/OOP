#pragma once

#include <random>

struct Small {

    constexpr static unsigned SIZE = 1u;
    char data[SIZE];

    void clear() {
        std::fill_n(data, SIZE, 0);
    }

    void rand() {
        static std::random_device rand{};
        static std::uniform_int_distribution<char> dist{-128, 127};

        for (char &i : data)
            i = dist(rand);
    }

    bool operator<(const Small &rhs) const {

        return data[0] < rhs.data[0];
    }

    bool operator==(const Small &rhs) const {

        return data[0] == rhs.data[0];
    }
};

namespace std {
    template<>
    struct hash<Small> {
        std::size_t operator()(const Small &d) const {

            std::hash<char> hash{};
            return hash(d.data[0]);
        }
    };
}
