#include <benchmark/benchmark.h>
#include "Large.h"

using namespace ::benchmark;

static void large_LessThanOperator(State& state) {

    Large a{};
    Large b{};

    a.rand();
    b.rand();

    for (auto _ : state) {

        DoNotOptimize(a < b);
    }
}

BENCHMARK(large_LessThanOperator);

static void large_EqualityOperator(State& state) {

    Large a{};
    Large b{};

    a.rand();
    b.rand();

    for (auto _ : state) {

        DoNotOptimize(a == b);
    }
}

BENCHMARK(large_EqualityOperator);

static void large_Hash(State& state) {

    Large a{};
    std::hash<Large> hash{};

    a.rand();

    for (auto _ : state) {

        DoNotOptimize(hash(a));
    }
}

BENCHMARK(large_Hash);
