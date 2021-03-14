#include <benchmark/benchmark.h>
#include "Small.h"

using namespace ::benchmark;

static void small_LessThanOperator(State& state) {

    Small a{};
    Small b{};

    a.rand();
    b.rand();

    for (auto _ : state) {

        DoNotOptimize(a < b);
    }
}

BENCHMARK(small_LessThanOperator);

static void small_EqualityOperator(State& state) {

    Small a{};
    Small b{};

    a.rand();
    b.rand();

    for (auto _ : state) {

        DoNotOptimize(a == b);
    }
}

BENCHMARK(small_EqualityOperator);

static void small_Hash(State& state) {

    Small a{};
    std::hash<Small> hash{};

    a.rand();

    for (auto _ : state) {

        DoNotOptimize(hash(a));
    }
}

BENCHMARK(small_Hash);
