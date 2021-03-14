#include <map>
#include <benchmark/benchmark.h>
#include "Small.h"

using namespace ::benchmark;

void multimapCreate_baseline_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::multimap<Small,Small> multimap{};
        DoNotOptimize(multimap);

        for(int i=0;i<size;i++) {
            Small a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(multimap.insert({a,b}));
        }

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapCreate_baseline_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void multimapCreateAndSetIterator_baseline_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::multimap<Small,Small> multimap{};
        DoNotOptimize(multimap);

        for(int i=0;i<size;i++) {
            Small a{}, b{};
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

BENCHMARK(multimapCreateAndSetIterator_baseline_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void multimapEmpty_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Small,Small> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Small a{}, b{};
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

BENCHMARK(multimapEmpty_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void multimapSize_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Small,Small> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Small a{}, b{};
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

BENCHMARK(multimapSize_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void multimapMaxSize_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Small,Small> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Small a{}, b{};
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

BENCHMARK(multimapMaxSize_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void multimapClear_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::multimap<Small,Small> multimap{};
        DoNotOptimize(multimap);

        for(int i=0;i<size;i++) {
            Small a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(multimap.insert({a,b}));
        }

        multimap.clear();

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapClear_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void multimapInsert_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    Small c{}, d{};
    c.rand();
    d.rand();

    for (auto _ : state) {

        std::multimap<Small,Small> multimap{};
        DoNotOptimize(multimap);

        for(int i=0;i<size;i++) {
            Small a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(multimap.insert({a,b}));
        }

        DoNotOptimize(multimap.insert({c,d}));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapInsert_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void multimapErase_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::multimap<Small,Small> multimap{};
        DoNotOptimize(multimap);

        for(int i=0;i<size;i++) {
            Small a{}, b{};
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

BENCHMARK(multimapErase_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void multimapSwap_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Small,Small> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Small a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(multimap.insert({a,b}));
    }

    std::multimap<Small,Small> multimap2{};
    DoNotOptimize(multimap2);

    for(int i=0;i<size;i++) {
        Small a{}, b{};
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

BENCHMARK(multimapSwap_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void multimapCount_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Small,Small> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Small a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(multimap.insert({a,b}));
    }

    Small key{};
    DoNotOptimize(key);

    key.rand();

    for (auto _ : state) {

        DoNotOptimize(multimap.count(key));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapCount_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void multimapFind_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Small,Small> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Small a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(multimap.insert({a,b}));
    }

    Small key{};
    DoNotOptimize(key);
    key.rand();

    for (auto _ : state) {

        DoNotOptimize(multimap.find(key));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapFind_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void multimapEqualRange_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Small,Small> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Small a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(multimap.insert({a,b}));
    }

    Small key{};
    DoNotOptimize(key);
    key.rand();

    for (auto _ : state) {

        DoNotOptimize(multimap.equal_range(key));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapEqualRange_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void multimapLowerBound_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Small,Small> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Small a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(multimap.insert({a,b}));
    }

    Small key{};
    DoNotOptimize(key);
    key.rand();

    for (auto _ : state) {

        DoNotOptimize(multimap.lower_bound(key));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapLowerBound_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void multimapUpperBound_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Small,Small> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Small a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(multimap.insert({a,b}));
    }

    Small key{};
    DoNotOptimize(key);
    key.rand();

    for (auto _ : state) {

        DoNotOptimize(multimap.upper_bound(key));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapUpperBound_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();
