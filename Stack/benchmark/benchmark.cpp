#include <benchmark/benchmark.h>

#include "stack-impl.hpp"
#include "stack.hpp"

const size_t MaxSize = 10000000;

const size_t MaxCoefExpand = 10;
const size_t MinCoefExpand = 1;

void TestExpand(benchmark::State& state)
{
    for (auto _ : state)
    {
        stack::Stack<size_t> mystk;
        mystk.change_coef_expand(1.0 + state.range() / 10.0);
        
        for (size_t i = 0; i < MaxSize; ++i)
        {
            mystk.push(i);
        }
    }
}

BENCHMARK(TestExpand)
    ->DenseRange(MinCoefExpand, MaxCoefExpand)
    ->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();