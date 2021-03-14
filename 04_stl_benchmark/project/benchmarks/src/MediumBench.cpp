#include <benchmark/benchmark.h>
#include "Medium.h"

using namespace ::benchmark;

static void medium_LessThanOperator(State& state) {

    Medium a{};
    Medium b{};

    a.rand();
    b.rand();

    for (auto _ : state) {

        DoNotOptimize(a < b);
    }
}

BENCHMARK(medium_LessThanOperator);

static void medium_EqualityOperator(State& state) {

    Medium a{};
    Medium b{};

    a.rand();
    b.rand();

    for (auto _ : state) {

        DoNotOptimize(a == b);
    }
}

BENCHMARK(medium_EqualityOperator);

static void medium_Hash(State& state) {

    Medium a{};
    std::hash<Medium> hash{};

    a.rand();

    for (auto _ : state) {

        DoNotOptimize(hash(a));
    }
}

BENCHMARK(medium_Hash);
