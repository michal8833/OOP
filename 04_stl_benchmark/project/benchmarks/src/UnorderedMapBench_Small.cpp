#include <unordered_map>
#include <benchmark/benchmark.h>
#include "Small.h"

using namespace ::benchmark;

void unorderedMapCreate_baseline_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {
        std::unordered_map<Small,Small> unorderedMap{};
        DoNotOptimize(unorderedMap);

        for(int i=0;i<size;i++) {
            Small a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(unorderedMap.insert({a,b}));
        }

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapCreate_baseline_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void unorderedMapCreateAndSetIterator_baseline_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {
        std::unordered_map<Small,Small> unorderedMap{};
        DoNotOptimize(unorderedMap);

        for(int i=0;i<size;i++) {
            Small a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(unorderedMap.insert({a,b}));
        }

        auto it = unorderedMap.begin();
        DoNotOptimize(it);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapCreateAndSetIterator_baseline_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void unorderedMapEmpty_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_map<Small,Small> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size;i++) {
        Small a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(unorderedMap.insert({a,b}));
    }

    for (auto _ : state) {

        DoNotOptimize(unorderedMap.empty());

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapEmpty_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void unorderedMapSize_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_map<Small,Small> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size;i++) {
        Small a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(unorderedMap.insert({a,b}));
    }

    for (auto _ : state) {

        DoNotOptimize(unorderedMap.size());

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapSize_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void unorderedMapMaxSize_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_map<Small,Small> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size;i++) {
        Small a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(unorderedMap.insert({a,b}));
    }

    for (auto _ : state) {

        DoNotOptimize(unorderedMap.max_size());

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapMaxSize_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void unorderedMapClear_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::unordered_map<Small,Small> unorderedMap{};
        DoNotOptimize(unorderedMap);

        for(int i=0;i<size;i++) {
            Small a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(unorderedMap.insert({a,b}));
        }

        unorderedMap.clear();

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapClear_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void unorderedMapInsert_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    Small c{}, d{};
    c.rand();
    d.rand();

    for (auto _ : state) {

        std::unordered_map<Small,Small> unorderedMap{};
        DoNotOptimize(unorderedMap);

        for(int i=0;i<size;i++) {
            Small a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(unorderedMap.insert({a,b}));
        }

        DoNotOptimize(unorderedMap.insert({c,d}));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapInsert_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void unorderedMapErase_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::unordered_map<Small,Small> unorderedMap{};
        DoNotOptimize(unorderedMap);

        for(int i=0;i<size;i++) {
            Small a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(unorderedMap.insert({a,b}));
        }
        auto it = unorderedMap.begin();
        DoNotOptimize(it);

        DoNotOptimize(unorderedMap.erase(it));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapErase_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void unorderedMapSwap_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_map<Small,Small> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size;i++) {
        Small a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(unorderedMap.insert({a,b}));
    }

    std::unordered_map<Small,Small> unorderedMap2{};
    DoNotOptimize(unorderedMap2);

    for(int i=0;i<size;i++) {
        Small a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(unorderedMap2.insert({a,b}));
    }

    for (auto _ : state) {

        unorderedMap.swap(unorderedMap2);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapSwap_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void unorderedMapAt_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    Small c{}, d{};
    c.data[0] = 1;
    d.rand();

    std::unordered_map<Small,Small> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size-1;i++) {
        Small a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(unorderedMap.insert({a,b}));
    }

    DoNotOptimize(unorderedMap.insert({c,d}));

    for (auto _ : state) {

        DoNotOptimize(unorderedMap.at(c));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapAt_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void unorderedMapOperatorSquareBrackets_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    Small c{}, d{};
    c.data[0] = 1;
    d.rand();

    std::unordered_map<Small,Small> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size-1;i++) {
        Small a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(unorderedMap.insert({a,b}));
    }

    DoNotOptimize(unorderedMap.insert({c,d}));

    for (auto _ : state) {

        DoNotOptimize(unorderedMap[c]);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapOperatorSquareBrackets_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void unorderedMapCount_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_map<Small,Small> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size;i++) {
        Small a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(unorderedMap.insert({a,b}));
    }

    Small key{};
    DoNotOptimize(key);
    key.rand();

    for (auto _ : state) {

        DoNotOptimize(unorderedMap.count(key));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapCount_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void unorderedMapFind_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_map<Small,Small> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size;i++) {
        Small a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(unorderedMap.insert({a,b}));
    }

    Small key{};
    DoNotOptimize(key);
    key.rand();

    for (auto _ : state) {

        DoNotOptimize(unorderedMap.find(key));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapFind_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void unorderedMapEqualRange_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_map<Small,Small> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size;i++) {
        Small a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(unorderedMap.insert({a,b}));
    }

    Small key{};
    DoNotOptimize(key);
    key.rand();

    for (auto _ : state) {

        DoNotOptimize(unorderedMap.equal_range(key));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapEqualRange_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void unorderedMapRehash_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::unordered_map<Small,Small> unorderedMap{};
        DoNotOptimize(unorderedMap);

        for(int i=0;i<size;i++) {
            Small a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(unorderedMap.insert({a,b}));
        }

        unorderedMap.rehash(size);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapRehash_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void unorderedMapReserve_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::unordered_map<Small,Small> unorderedMap{};
        DoNotOptimize(unorderedMap);

        for(int i=0;i<size;i++) {
            Small a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(unorderedMap.insert({a,b}));
        }

        unorderedMap.reserve(size);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapReserve_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();
