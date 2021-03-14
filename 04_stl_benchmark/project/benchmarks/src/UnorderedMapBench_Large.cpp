#include <unordered_map>
#include <benchmark/benchmark.h>
#include "Large.h"

using namespace ::benchmark;

void unorderedMapCreate_baseline_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {
        std::unordered_map<Large,Large> unorderedMap{};
        DoNotOptimize(unorderedMap);

        for(int i=0;i<size;i++) {
            Large a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(unorderedMap.insert({a,b}));
        }

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapCreate_baseline_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void unorderedMapCreateAndSetIterator_baseline_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {
        std::unordered_map<Large,Large> unorderedMap{};
        DoNotOptimize(unorderedMap);

        for(int i=0;i<size;i++) {
            Large a{}, b{};
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

BENCHMARK(unorderedMapCreateAndSetIterator_baseline_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void unorderedMapEmpty_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_map<Large,Large> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size;i++) {
        Large a{}, b{};
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

BENCHMARK(unorderedMapEmpty_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void unorderedMapSize_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_map<Large,Large> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size;i++) {
        Large a{}, b{};
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

BENCHMARK(unorderedMapSize_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void unorderedMapMaxSize_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_map<Large,Large> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size;i++) {
        Large a{}, b{};
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

BENCHMARK(unorderedMapMaxSize_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void unorderedMapClear_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::unordered_map<Large,Large> unorderedMap{};
        DoNotOptimize(unorderedMap);

        for(int i=0;i<size;i++) {
            Large a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(unorderedMap.insert({a,b}));
        }

        unorderedMap.clear();

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapClear_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void unorderedMapInsert_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    Large c{}, d{};
    c.rand();
    d.rand();

    for (auto _ : state) {

        std::unordered_map<Large,Large> unorderedMap{};
        DoNotOptimize(unorderedMap);

        for(int i=0;i<size;i++) {
            Large a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(unorderedMap.insert({a,b}));
        }

        DoNotOptimize(unorderedMap.insert({c,d}));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapInsert_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void unorderedMapErase_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::unordered_map<Large,Large> unorderedMap{};
        DoNotOptimize(unorderedMap);

        for(int i=0;i<size;i++) {
            Large a{}, b{};
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

BENCHMARK(unorderedMapErase_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void unorderedMapSwap_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_map<Large,Large> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size;i++) {
        Large a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(unorderedMap.insert({a,b}));
    }

    std::unordered_map<Large,Large> unorderedMap2{};
    DoNotOptimize(unorderedMap2);

    for(int i=0;i<size;i++) {
        Large a{}, b{};
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

BENCHMARK(unorderedMapSwap_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void unorderedMapAt_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    Large c{}, d{};
    c.data[0] = 1;
    d.rand();

    std::unordered_map<Large,Large> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size-1;i++) {
        Large a{}, b{};
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

BENCHMARK(unorderedMapAt_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void unorderedMapOperatorSquareBrackets_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    Large c{}, d{};
    c.data[0] = 1;
    d.rand();

    std::unordered_map<Large,Large> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size-1;i++) {
        Large a{}, b{};
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

BENCHMARK(unorderedMapOperatorSquareBrackets_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void unorderedMapCount_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_map<Large,Large> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size;i++) {
        Large a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(unorderedMap.insert({a,b}));
    }

    Large key{};
    DoNotOptimize(key);
    key.rand();

    for (auto _ : state) {

        DoNotOptimize(unorderedMap.count(key));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapCount_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void unorderedMapFind_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_map<Large,Large> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size;i++) {
        Large a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(unorderedMap.insert({a,b}));
    }

    Large key{};
    DoNotOptimize(key);
    key.rand();

    for (auto _ : state) {

        DoNotOptimize(unorderedMap.find(key));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapFind_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void unorderedMapEqualRange_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_map<Large,Large> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size;i++) {
        Large a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(unorderedMap.insert({a,b}));
    }

    Large key{};
    DoNotOptimize(key);
    key.rand();

    for (auto _ : state) {

        DoNotOptimize(unorderedMap.equal_range(key));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapEqualRange_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void unorderedMapRehash_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::unordered_map<Large,Large> unorderedMap{};
        DoNotOptimize(unorderedMap);

        for(int i=0;i<size;i++) {
            Large a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(unorderedMap.insert({a,b}));
        }

        unorderedMap.rehash(size);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapRehash_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();

void unorderedMapReserve_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::unordered_map<Large,Large> unorderedMap{};
        DoNotOptimize(unorderedMap);

        for(int i=0;i<size;i++) {
            Large a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(unorderedMap.insert({a,b}));
        }

        unorderedMap.reserve(size);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapReserve_large)->RangeMultiplier(2)->Range(1u, 1u << 6u)->Complexity();
