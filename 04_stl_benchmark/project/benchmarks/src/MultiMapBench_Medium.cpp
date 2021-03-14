#include <map>
#include <benchmark/benchmark.h>
#include "Medium.h"

using namespace ::benchmark;

void multimapCreate_baseline_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::multimap<Medium,Medium> multimap{};
        DoNotOptimize(multimap);

        for(int i=0;i<size;i++) {
            Medium a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(multimap.insert({a,b}));
        }

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapCreate_baseline_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void multimapCreateAndSetIterator_baseline_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::multimap<Medium,Medium> multimap{};
        DoNotOptimize(multimap);

        for(int i=0;i<size;i++) {
            Medium a{}, b{};
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

BENCHMARK(multimapCreateAndSetIterator_baseline_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void multimapEmpty_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Medium,Medium> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Medium a{}, b{};
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

BENCHMARK(multimapEmpty_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void multimapSize_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Medium,Medium> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Medium a{}, b{};
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

BENCHMARK(multimapSize_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void multimapMaxSize_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Medium,Medium> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Medium a{}, b{};
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

BENCHMARK(multimapMaxSize_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void multimapClear_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::multimap<Medium,Medium> multimap{};
        DoNotOptimize(multimap);

        for(int i=0;i<size;i++) {
            Medium a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(multimap.insert({a,b}));
        }

        multimap.clear();

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapClear_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void multimapInsert_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    Medium c{}, d{};
    c.rand();
    d.rand();

    for (auto _ : state) {

        std::multimap<Medium,Medium> multimap{};
        DoNotOptimize(multimap);

        for(int i=0;i<size;i++) {
            Medium a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(multimap.insert({a,b}));
        }

        DoNotOptimize(multimap.insert({c,d}));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapInsert_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void multimapErase_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::multimap<Medium,Medium> multimap{};
        DoNotOptimize(multimap);

        for(int i=0;i<size;i++) {
            Medium a{}, b{};
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

BENCHMARK(multimapErase_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void multimapSwap_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Medium,Medium> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Medium a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(multimap.insert({a,b}));
    }

    std::multimap<Medium,Medium> multimap2{};
    DoNotOptimize(multimap2);

    for(int i=0;i<size;i++) {
        Medium a{}, b{};
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

BENCHMARK(multimapSwap_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void multimapCount_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Medium,Medium> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Medium a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(multimap.insert({a,b}));
    }

    Medium key{};
    DoNotOptimize(key);

    key.rand();

    for (auto _ : state) {

        DoNotOptimize(multimap.count(key));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapCount_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void multimapFind_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Medium,Medium> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Medium a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(multimap.insert({a,b}));
    }

    Medium key{};
    DoNotOptimize(key);
    key.rand();

    for (auto _ : state) {

        DoNotOptimize(multimap.find(key));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapFind_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void multimapEqualRange_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Medium,Medium> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Medium a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(multimap.insert({a,b}));
    }

    Medium key{};
    DoNotOptimize(key);
    key.rand();

    for (auto _ : state) {

        DoNotOptimize(multimap.equal_range(key));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapEqualRange_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void multimapLowerBound_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Medium,Medium> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Medium a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(multimap.insert({a,b}));
    }

    Medium key{};
    DoNotOptimize(key);
    key.rand();

    for (auto _ : state) {

        DoNotOptimize(multimap.lower_bound(key));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapLowerBound_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void multimapUpperBound_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::multimap<Medium,Medium> multimap{};
    DoNotOptimize(multimap);

    for(int i=0;i<size;i++) {
        Medium a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(multimap.insert({a,b}));
    }

    Medium key{};
    DoNotOptimize(key);
    key.rand();

    for (auto _ : state) {

        DoNotOptimize(multimap.upper_bound(key));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(multimapUpperBound_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();
