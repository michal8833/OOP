#pragma once

#include <random>

struct Medium {

    constexpr static unsigned SIZE = 256u;
    int data[SIZE];

    void clear() {
        std::fill_n(data, SIZE, 0);
    }

    void rand() {
        static std::random_device rand{};
        static std::uniform_int_distribution<int> dist{};

        for (int &i : data)
            i = dist(rand);
    }

    bool operator<(const Medium &rhs) const {

        for(int i=0;i<SIZE;i++)
            if(data[i] != rhs.data[i])
                return data[i] < rhs.data[i];

        return false;
    }

    bool operator==(const Medium &rhs) const {

        for(int i=0;i<SIZE;i++)
            if(data[i] != rhs.data[i])
                return false;

        return true;
    }
};

namespace std {
    template<>
    struct hash<Medium> {
        std::size_t operator()(const Medium &d) const {

            std::hash<int> hash{};

            std::size_t sum = 0;
            for(int i : d.data)
                sum += hash(i);

            return sum;
        }
    };
}