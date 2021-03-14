#include <map>
#include <benchmark/benchmark.h>
#include "Large.h"

using namespace ::benchmark;

void multimapCreate_baseline_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::multimap<Large,Large> multimap{};
        DoNotOptimize(multimap);

        for(int i=0;i<size;i++) {
            Large a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(multimap.insert({a,b}));
        }

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapCreate_baseline_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void multimapCreateAndSetIterator_baseline_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::multimap<Large,Large> multimap{};
        DoNotOptimize(multimap);

        for(int i=0;i<size;i++) {
            Large a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(multimap.insert({a,b}));
        }

        auto it = multimap.begin();
        DoNotOptimize(it);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapCreateAndSetIterator_baseline_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void multimapEmpty_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Large,Large> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Large a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(multimap.insert({a,b}));
    }

    for (auto _ : state) {

        DoNotOptimize(multimap.empty());

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapEmpty_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void multimapSize_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Large,Large> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Large a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(multimap.insert({a,b}));
    }

    for (auto _ : state) {

        DoNotOptimize(multimap.size());

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapSize_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void multimapMaxSize_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Large,Large> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Large a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize( multimap.insert({a,b}));
    }

    for (auto _ : state) {

        DoNotOptimize(multimap.max_size());

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapMaxSize_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void multimapClear_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::multimap<Large,Large> multimap{};
        DoNotOptimize(multimap);

        for(int i=0;i<size;i++) {
            Large a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(multimap.insert({a,b}));
        }

        multimap.clear();

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapClear_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void multimapInsert_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    Large c{}, d{};
    c.rand();
    d.rand();

    for (auto _ : state) {

        std::multimap<Large,Large> multimap{};
        DoNotOptimize(multimap);

        for(int i=0;i<size;i++) {
            Large a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(multimap.insert({a,b}));
        }

        DoNotOptimize(multimap.insert({c,d}));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapInsert_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void multimapErase_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::multimap<Large,Large> multimap{};
        DoNotOptimize(multimap);

        for(int i=0;i<size;i++) {
            Large a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(multimap.insert({a,b}));
        }
        auto it = multimap.begin();
        DoNotOptimize(it);

        DoNotOptimize(multimap.erase(it));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapErase_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void multimapSwap_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Large,Large> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Large a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(multimap.insert({a,b}));
    }

    std::multimap<Large,Large> multimap2{};
    DoNotOptimize(multimap2);

    for(int i=0;i<size;i++) {
        Large a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(multimap2.insert({a,b}));
    }

    for (auto _ : state) {

        multimap.swap(multimap2);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapSwap_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void multimapCount_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Large,Large> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Large a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(multimap.insert({a,b}));
    }

    Large key{};
    DoNotOptimize(key);

    key.rand();

    for (auto _ : state) {

        DoNotOptimize(multimap.count(key));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapCount_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void multimapFind_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Large,Large> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Large a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(multimap.insert({a,b}));
    }

    Large key{};
    DoNotOptimize(key);
    key.rand();

    for (auto _ : state) {

        DoNotOptimize(multimap.find(key));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapFind_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void multimapEqualRange_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Large,Large> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Large a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(multimap.insert({a,b}));
    }

    Large key{};
    DoNotOptimize(key);
    key.rand();

    for (auto _ : state) {

        DoNotOptimize(multimap.equal_range(key));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapEqualRange_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void multimapLowerBound_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Large,Large> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Large a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(multimap.insert({a,b}));
    }

    Large key{};
    DoNotOptimize(key);
    key.rand();

    for (auto _ : state) {

        DoNotOptimize(multimap.lower_bound(key));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapLowerBound_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void multimapUpperBound_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Large,Large> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Large a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(multimap.insert({a,b}));
    }

    Large key{};
    DoNotOptimize(key);
    key.rand();

    for (auto _ : state) {

        DoNotOptimize(multimap.upper_bound(key));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapUpperBound_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();
