#include <list>
#include <benchmark/benchmark.h>
#include "Small.h"

using namespace ::benchmark;

void listCreate_baseline_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::list<Small> list(size);
        DoNotOptimize(list);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listCreate_baseline_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void listWithoutSizeCreate_baseline_small(State& state) {

    auto N = state.range(0);

    for (auto _ : state) {

        std::list<Small> list;
        DoNotOptimize(list);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listWithoutSizeCreate_baseline_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void listCreateAndSetIterator_baseline_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::list<Small> list(size);
        auto listIterator = list.begin();
        DoNotOptimize(list);
        DoNotOptimize(listIterator);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listCreateAndSetIterator_baseline_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void listFront_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Small> list(size);
    DoNotOptimize(list);

    for (auto _ : state) {

        DoNotOptimize(list.front());

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listFront_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void listBack_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Small> list(size);
    DoNotOptimize(list);

    for (auto _ : state) {

        DoNotOptimize(list.back());

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listBack_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void listEmpty_small(State& state) {

    auto N = state.range(0);

    std::list<Small> list;
    DoNotOptimize(list);

    for (auto _ : state) {

        DoNotOptimize(list.empty());

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listEmpty_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void listSize_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Small> list(size);
    DoNotOptimize(list);

    for (auto _ : state) {

        DoNotOptimize(list.size());

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listSize_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void listMaxSize_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Small> list(size);

    for (auto _ : state) {

        DoNotOptimize(list.max_size());

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listMaxSize_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void listClear_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {
        std::list<Small> list(size);
        DoNotOptimize(list);

        list.clear();

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listClear_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void listInsert_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::list<Small> list(size);
        auto listIterator = list.begin();
        DoNotOptimize(list);
        DoNotOptimize(listIterator);

        DoNotOptimize(list.insert(listIterator,Small{}));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listInsert_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void listErase_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::list<Small> list(size);
        auto it = list.begin();
        DoNotOptimize(list);
        DoNotOptimize(it);

        DoNotOptimize(list.erase(it));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listErase_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void listPushBack_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Small> list(size);
    DoNotOptimize(list);

    Small a{};
    DoNotOptimize(a);

    for (auto _ : state) {

        list.push_back(a);
        list.pop_back();

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listPushBack_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void listPushFront_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Small> list(size);
    DoNotOptimize(list);

    Small a{};
    DoNotOptimize(a);

    for (auto _ : state) {

        list.push_front(a);
        list.pop_front();

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listPushFront_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void listPopFront_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Small> list(size);
    DoNotOptimize(list);

    Small a{};
    DoNotOptimize(a);

    for (auto _ : state) {

        list.pop_front();
        list.push_front(a);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listPopFront_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void listResize_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::list<Small> list;
        DoNotOptimize(list);

        list.resize(size);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listResize_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void listSwap_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::list<Small> list(size);
        std::list<Small> list2(size);
        DoNotOptimize(list);
        DoNotOptimize(list2);

        list.swap(list2);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listSwap_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void listMerge_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::list<Small> list(size);
        std::list<Small> list2(size);
        DoNotOptimize(list);
        DoNotOptimize(list2);

        list.merge(list2);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listMerge_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void listSplice_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Small> list(size);
    std::list<Small> list2(size);
    DoNotOptimize(list);
    DoNotOptimize(list2);

    for (auto _ : state) {

        list.splice(list.begin(),list2);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listSplice_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void listRemove_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    Small a{};
    a.data[0] = 1;
    DoNotOptimize(a.data);

    Small b{};
    b.data[0] = 2;
    DoNotOptimize(b.data);

    std::list<Small> list;
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

BENCHMARK(listRemove_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void listRemoveIf_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    Small a{};
    a.data[0] = 1;
    DoNotOptimize(a.data);

    Small b{};
    b.data[0] = 2;
    DoNotOptimize(b.data);

    std::list<Small> list;
    DoNotOptimize(list);

    list.push_back(a);
    for(int i=1;i<size;i++) {
        list.push_back(b);
    }

    for (auto _ : state) {

        list.remove_if([](Small n){ return n.data[0] == 1; });
        list.push_front(a);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listRemoveIf_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void listReverse_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Small> list;
    DoNotOptimize(list);

    for(int i=0;i<size;i++) {
        Small a{};
        a.rand();
        list.push_back(a);
    }

    for (auto _ : state) {

        list.reverse();

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listReverse_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void listUnique_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Small> list;
    DoNotOptimize(list);

    for(int i=0;i<size;i++) {
        Small a{};
        a.rand();
        list.push_back(a);
    }

    for (auto _ : state) {

        list.unique();

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listUnique_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void listSort_small(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Small> list;
    DoNotOptimize(list);

    for(int i=0;i<size;i++) {
        Small a{};
        a.rand();
        list.push_back(a);
    }

    for (auto _ : state) {

        list.sort();

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listSort_small)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();




