#include <list>
#include <benchmark/benchmark.h>
#include "Large.h"

using namespace ::benchmark;

void listCreate_baseline_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::list<Large> list(size);
        DoNotOptimize(list);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listCreate_baseline_large)->RangeMultiplier(2)->Range(1u, 1u << 8u)->Complexity();

void listWithoutSizeCreate_baseline_large(State& state) {

    auto N = state.range(0);

    for (auto _ : state) {

        std::list<Large> list;
        DoNotOptimize(list);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listWithoutSizeCreate_baseline_large)->RangeMultiplier(2)->Range(1u, 1u << 8u)->Complexity();

void listCreateAndSetIterator_baseline_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::list<Large> list(size);
        auto listIterator = list.begin();
        DoNotOptimize(list);
        DoNotOptimize(listIterator);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listCreateAndSetIterator_baseline_large)->RangeMultiplier(2)->Range(1u, 1u << 8u)->Complexity();

void listFront_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Large> list(size);
    DoNotOptimize(list);

    for (auto _ : state) {

        DoNotOptimize(list.front());

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listFront_large)->RangeMultiplier(2)->Range(1u, 1u << 8u)->Complexity();

void listBack_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Large> list(size);
    DoNotOptimize(list);

    for (auto _ : state) {

        DoNotOptimize(list.back());

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listBack_large)->RangeMultiplier(2)->Range(1u, 1u << 8u)->Complexity();

void listEmpty_large(State& state) {

    auto N = state.range(0);

    std::list<Large> list;
    DoNotOptimize(list);

    for (auto _ : state) {

        DoNotOptimize(list.empty());

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listEmpty_large)->RangeMultiplier(2)->Range(1u, 1u << 8u)->Complexity();

void listSize_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Large> list(size);
    DoNotOptimize(list);

    for (auto _ : state) {

        DoNotOptimize(list.size());

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listSize_large)->RangeMultiplier(2)->Range(1u, 1u << 8u)->Complexity();

void listMaxSize_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Large> list(size);

    for (auto _ : state) {

        DoNotOptimize(list.max_size());

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listMaxSize_large)->RangeMultiplier(2)->Range(1u, 1u << 8u)->Complexity();

void listClear_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {
        std::list<Large> list(size);
        DoNotOptimize(list);

        list.clear();

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listClear_large)->RangeMultiplier(2)->Range(1u, 1u << 8u)->Complexity();

void listInsert_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::list<Large> list(size);
        auto listIterator = list.begin();
        DoNotOptimize(list);
        DoNotOptimize(listIterator);

        DoNotOptimize(list.insert(listIterator,Large{}));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listInsert_large)->RangeMultiplier(2)->Range(1u, 1u << 8u)->Complexity();

void listErase_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::list<Large> list(size);
        auto it = list.begin();
        DoNotOptimize(list);
        DoNotOptimize(it);

        DoNotOptimize(list.erase(it));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listErase_large)->RangeMultiplier(2)->Range(1u, 1u << 8u)->Complexity();

void listPushBack_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Large> list(size);
    DoNotOptimize(list);

    Large a{};
    DoNotOptimize(a);

    for (auto _ : state) {

        list.push_back(a);
        list.pop_back();

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listPushBack_large)->RangeMultiplier(2)->Range(1u, 1u << 8u)->Complexity();

void listPushFront_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Large> list(size);
    DoNotOptimize(list);

    Large a{};
    DoNotOptimize(a);

    for (auto _ : state) {

        list.push_front(a);
        list.pop_front();

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listPushFront_large)->RangeMultiplier(2)->Range(1u, 1u << 8u)->Complexity();

void listPopFront_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Large> list(size);
    DoNotOptimize(list);

    Large a{};
    DoNotOptimize(a);

    for (auto _ : state) {

        list.pop_front();
        list.push_front(a);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listPopFront_large)->RangeMultiplier(2)->Range(1u, 1u << 8u)->Complexity();

void listResize_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::list<Large> list;
        DoNotOptimize(list);

        list.resize(size);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listResize_large)->RangeMultiplier(2)->Range(1u, 1u << 8u)->Complexity();

void listSwap_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::list<Large> list(size);
        std::list<Large> list2(size);
        DoNotOptimize(list);
        DoNotOptimize(list2);

        list.swap(list2);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listSwap_large)->RangeMultiplier(2)->Range(1u, 1u << 8u)->Complexity();

void listMerge_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::list<Large> list(size);
        std::list<Large> list2(size);
        DoNotOptimize(list);
        DoNotOptimize(list2);

        list.merge(list2);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listMerge_large)->RangeMultiplier(2)->Range(1u, 1u << 8u)->Complexity();

void listSplice_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Large> list(size);
    std::list<Large> list2(size);
    DoNotOptimize(list);
    DoNotOptimize(list2);

    for (auto _ : state) {

        list.splice(list.begin(),list2);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listSplice_large)->RangeMultiplier(2)->Range(1u, 1u << 8u)->Complexity();

void listRemove_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    Large a{};
    a.data[0] = 1;
    DoNotOptimize(a.data);

    Large b{};
    b.data[0] = 2;
    DoNotOptimize(b.data);

    std::list<Large> list;
    DoNotOptimize(list);

    list.push_back(a);
    for(int i=1;i<size;i++) {
        list.push_back(b);
    }

    for (auto _ : state) {

        list.remove(list.front());
        list.push_front(a);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listRemove_large)->RangeMultiplier(2)->Range(1u, 1u << 8u)->Complexity();

void listRemoveIf_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    Large a{};
    a.data[0] = 1;
    DoNotOptimize(a.data);

    Large b{};
    b.data[0] = 2;
    DoNotOptimize(b.data);

    std::list<Large> list;
    DoNotOptimize(list);

    list.push_back(a);
    for(int i=1;i<size;i++) {
        list.push_back(b);
    }

    for (auto _ : state) {

        list.remove_if([](Large n){ return n.data[0] == 1; });
        list.push_front(a);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listRemoveIf_large)->RangeMultiplier(2)->Range(1u, 1u << 8u)->Complexity();

void listReverse_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Large> list;
    DoNotOptimize(list);

    for(int i=0;i<size;i++) {
        Large a{};
        a.rand();
        list.push_back(a);
    }

    for (auto _ : state) {

        list.reverse();

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listReverse_large)->RangeMultiplier(2)->Range(1u, 1u << 8u)->Complexity();

void listUnique_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Large> list;
    DoNotOptimize(list);

    for(int i=0;i<size;i++) {
        Large a{};
        a.rand();
        list.push_back(a);
    }

    for (auto _ : state) {

        list.unique();

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listUnique_large)->RangeMultiplier(2)->Range(1u, 1u << 8u)->Complexity();

void listSort_large(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Large> list;
    DoNotOptimize(list);

    for(int i=0;i<size;i++) {
        Large a{};
        a.rand();
        list.push_back(a);
    }

    for (auto _ : state) {

        list.sort();

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listSort_large)->RangeMultiplier(2)->Range(1u, 1u << 8u)->Complexity();




