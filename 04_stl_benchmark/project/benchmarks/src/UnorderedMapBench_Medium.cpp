#include <unordered_map>
#include <benchmark/benchmark.h>
#include "Medium.h"

using namespace ::benchmark;

void unorderedMapCreate_baseline_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {
        std::unordered_map<Medium,Medium> unorderedMap{};
        DoNotOptimize(unorderedMap);

        for(int i=0;i<size;i++) {
            Medium a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(unorderedMap.insert({a,b}));
        }

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapCreate_baseline_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void unorderedMapCreateAndSetIterator_baseline_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {
        std::unordered_map<Medium,Medium> unorderedMap{};
        DoNotOptimize(unorderedMap);

        for(int i=0;i<size;i++) {
            Medium a{}, b{};
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

BENCHMARK(unorderedMapCreateAndSetIterator_baseline_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void unorderedMapEmpty_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_map<Medium,Medium> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size;i++) {
        Medium a{}, b{};
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

BENCHMARK(unorderedMapEmpty_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void unorderedMapSize_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_map<Medium,Medium> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size;i++) {
        Medium a{}, b{};
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

BENCHMARK(unorderedMapSize_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void unorderedMapMaxSize_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_map<Medium,Medium> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size;i++) {
        Medium a{}, b{};
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

BENCHMARK(unorderedMapMaxSize_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void unorderedMapClear_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::unordered_map<Medium,Medium> unorderedMap{};
        DoNotOptimize(unorderedMap);

        for(int i=0;i<size;i++) {
            Medium a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(unorderedMap.insert({a,b}));
        }

        unorderedMap.clear();

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapClear_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void unorderedMapInsert_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    Medium c{}, d{};
    c.rand();
    d.rand();

    for (auto _ : state) {

        std::unordered_map<Medium,Medium> unorderedMap{};
        DoNotOptimize(unorderedMap);

        for(int i=0;i<size;i++) {
            Medium a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(unorderedMap.insert({a,b}));
        }

        DoNotOptimize(unorderedMap.insert({c,d}));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapInsert_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void unorderedMapErase_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::unordered_map<Medium,Medium> unorderedMap{};
        DoNotOptimize(unorderedMap);

        for(int i=0;i<size;i++) {
            Medium a{}, b{};
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

BENCHMARK(unorderedMapErase_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void unorderedMapSwap_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_map<Medium,Medium> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size;i++) {
        Medium a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(unorderedMap.insert({a,b}));
    }

    std::unordered_map<Medium,Medium> unorderedMap2{};
    DoNotOptimize(unorderedMap2);

    for(int i=0;i<size;i++) {
        Medium a{}, b{};
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

BENCHMARK(unorderedMapSwap_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void unorderedMapAt_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    Medium c{}, d{};
    c.data[0] = 1;
    d.rand();

    std::unordered_map<Medium,Medium> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size-1;i++) {
        Medium a{}, b{};
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

BENCHMARK(unorderedMapAt_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void unorderedMapOperatorSquareBrackets_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    Medium c{}, d{};
    c.data[0] = 1;
    d.rand();

    std::unordered_map<Medium,Medium> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size-1;i++) {
        Medium a{}, b{};
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

BENCHMARK(unorderedMapOperatorSquareBrackets_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void unorderedMapCount_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_map<Medium,Medium> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size;i++) {
        Medium a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(unorderedMap.insert({a,b}));
    }

    Medium key{};
    DoNotOptimize(key);
    key.rand();

    for (auto _ : state) {

        DoNotOptimize(unorderedMap.count(key));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapCount_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void unorderedMapFind_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_map<Medium,Medium> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size;i++) {
        Medium a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(unorderedMap.insert({a,b}));
    }

    Medium key{};
    DoNotOptimize(key);
    key.rand();

    for (auto _ : state) {

        DoNotOptimize(unorderedMap.find(key));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapFind_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void unorderedMapEqualRange_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_map<Medium,Medium> unorderedMap{};
    DoNotOptimize(unorderedMap);

    for(int i=0;i<size;i++) {
        Medium a{}, b{};
        a.rand();
        b.rand();
        DoNotOptimize(unorderedMap.insert({a,b}));
    }

    Medium key{};
    DoNotOptimize(key);
    key.rand();

    for (auto _ : state) {

        DoNotOptimize(unorderedMap.equal_range(key));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapEqualRange_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void unorderedMapRehash_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::unordered_map<Medium,Medium> unorderedMap{};
        DoNotOptimize(unorderedMap);

        for(int i=0;i<size;i++) {
            Medium a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(unorderedMap.insert({a,b}));
        }

        unorderedMap.rehash(size);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapRehash_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void unorderedMapReserve_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::unordered_map<Medium,Medium> unorderedMap{};
        DoNotOptimize(unorderedMap);

        for(int i=0;i<size;i++) {
            Medium a{}, b{};
            a.rand();
            b.rand();
            DoNotOptimize(unorderedMap.insert({a,b}));
        }

        unorderedMap.reserve(size);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(unorderedMapReserve_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();
