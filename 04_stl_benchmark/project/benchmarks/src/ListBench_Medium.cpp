#include <list>
#include <benchmark/benchmark.h>
#include "Medium.h"

using namespace ::benchmark;

void listCreate_baseline_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::list<Medium> list(size);
        DoNotOptimize(list);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listCreate_baseline_medium)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void listWithoutSizeCreate_baseline_medium(State& state) {

    auto N = state.range(0);

    for (auto _ : state) {

        std::list<Medium> list;
        DoNotOptimize(list);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listWithoutSizeCreate_baseline_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void listCreateAndSetIterator_baseline_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::list<Medium> list(size);
        auto listIterator = list.begin();
        DoNotOptimize(list);
        DoNotOptimize(listIterator);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listCreateAndSetIterator_baseline_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void listFront_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Medium> list(size);
    DoNotOptimize(list);

    for (auto _ : state) {

        DoNotOptimize(list.front());

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listFront_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void listBack_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Medium> list(size);
    DoNotOptimize(list);

    for (auto _ : state) {

        DoNotOptimize(list.back());

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listBack_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void listEmpty_medium(State& state) {

    auto N = state.range(0);

    std::list<Medium> list;
    DoNotOptimize(list);

    for (auto _ : state) {

        DoNotOptimize(list.empty());

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listEmpty_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void listSize_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Medium> list(size);
    DoNotOptimize(list);

    for (auto _ : state) {

        DoNotOptimize(list.size());

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listSize_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void listMaxSize_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Medium> list(size);

    for (auto _ : state) {

        DoNotOptimize(list.max_size());

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listMaxSize_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void listClear_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {
        std::list<Medium> list(size);
        DoNotOptimize(list);

        list.clear();

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listClear_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void listInsert_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::list<Medium> list(size);
        auto listIterator = list.begin();
        DoNotOptimize(list);
        DoNotOptimize(listIterator);

        DoNotOptimize(list.insert(listIterator,Medium{}));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listInsert_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void listErase_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::list<Medium> list(size);
        auto it = list.begin();
        DoNotOptimize(list);
        DoNotOptimize(it);

        DoNotOptimize(list.erase(it));

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listErase_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void listPushBack_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Medium> list(size);
    DoNotOptimize(list);

    Medium a{};
    DoNotOptimize(a);

    for (auto _ : state) {

        list.push_back(a);
        list.pop_back();

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listPushBack_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void listPushFront_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Medium> list(size);
    DoNotOptimize(list);

    Medium a{};
    DoNotOptimize(a);

    for (auto _ : state) {

        list.push_front(a);
        list.pop_front();

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listPushFront_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void listPopFront_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Medium> list(size);
    DoNotOptimize(list);

    Medium a{};
    DoNotOptimize(a);

    for (auto _ : state) {

        list.pop_front();
        list.push_front(a);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listPopFront_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void listResize_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::list<Medium> list;
        DoNotOptimize(list);

        list.resize(size);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listResize_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void listSwap_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::list<Medium> list(size);
        std::list<Medium> list2(size);
        DoNotOptimize(list);
        DoNotOptimize(list2);

        list.swap(list2);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listSwap_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void listMerge_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::list<Medium> list(size);
        std::list<Medium> list2(size);
        DoNotOptimize(list);
        DoNotOptimize(list2);

        list.merge(list2);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listMerge_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void listSplice_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Medium> list(size);
    std::list<Medium> list2(size);
    DoNotOptimize(list);
    DoNotOptimize(list2);

    for (auto _ : state) {

        list.splice(list.begin(),list2);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listSplice_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void listRemove_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    Medium a{};
    a.data[0] = 1;
    DoNotOptimize(a.data);

    Medium b{};
    b.data[0] = 2;
    DoNotOptimize(b.data);

    std::list<Medium> list;
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

BENCHMARK(listRemove_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void listRemoveIf_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    Medium a{};
    a.data[0] = 1;
    DoNotOptimize(a.data);

    Medium b{};
    b.data[0] = 2;
    DoNotOptimize(b.data);

    std::list<Medium> list;
    DoNotOptimize(list);

    list.push_back(a);
    for(int i=1;i<size;i++) {
        list.push_back(b);
    }

    for (auto _ : state) {

        list.remove_if([](Medium n){ return n.data[0] == 1; });
        list.push_front(a);

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listRemoveIf_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void listReverse_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Medium> list;
    DoNotOptimize(list);

    for(int i=0;i<size;i++) {
        Medium a{};
        a.rand();
        list.push_back(a);
    }

    for (auto _ : state) {

        list.reverse();

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listReverse_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void listUnique_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Medium> list;
    DoNotOptimize(list);

    for(int i=0;i<size;i++) {
        Medium a{};
        a.rand();
        list.push_back(a);
    }

    for (auto _ : state) {

        list.unique();

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listUnique_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();

void listSort_medium(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Medium> list;
    DoNotOptimize(list);

    for(int i=0;i<size;i++) {
        Medium a{};
        a.rand();
        list.push_back(a);
    }

    for (auto _ : state) {

        list.sort();

        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(listSort_medium)->RangeMultiplier(2)->Range(1u, 1u << 10u)->Complexity();





