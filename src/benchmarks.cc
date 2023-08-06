#include "CMakeFiles/neon_sandbox_ispc.dir/texture_ispc.h"
#include "benchmark/benchmark.h"
#include "texture.h"

namespace ns {

static constexpr UPoint kBenchmarkCanvasSize = {1 << 14, 1 << 14};

static void DoNothing(benchmark::State& state) {
  while (state.KeepRunning()) {
    //
  }
}
BENCHMARK(DoNothing)->Unit(benchmark::TimeUnit::kMillisecond);

static void Clear(benchmark::State& state) {
  Texture texture;
  NS_ASSERT(texture.Resize(kBenchmarkCanvasSize));
  while (state.KeepRunning()) {
    texture.Clear(kColorBlue);
  }
}
BENCHMARK(Clear)->Unit(benchmark::TimeUnit::kMillisecond);

static void ToRGBA(benchmark::State& state) {
  Texture texture;
  Texture rgba;
  NS_ASSERT(texture.Resize(kBenchmarkCanvasSize));
  NS_ASSERT(rgba.Resize(kBenchmarkCanvasSize));
  texture.Clear(kColorBlue);
  while (state.KeepRunning()) {
    texture.CopyRGBA(rgba);
  }
}
BENCHMARK(ToRGBA)->Unit(benchmark::TimeUnit::kMillisecond);

static void Grayscale(benchmark::State& state) {
  Texture texture;
  NS_ASSERT(texture.Resize(kBenchmarkCanvasSize));
  while (state.KeepRunning()) {
    texture.ToGrayscale();
  }
}
BENCHMARK(Grayscale)->Unit(benchmark::TimeUnit::kMillisecond);

static void Invert(benchmark::State& state) {
  Texture texture;
  NS_ASSERT(texture.Resize(kBenchmarkCanvasSize));
  while (state.KeepRunning()) {
    texture.Invert();
  }
}
BENCHMARK(Invert)->Unit(benchmark::TimeUnit::kMillisecond);

static void Exposure(benchmark::State& state) {
  Texture texture;
  NS_ASSERT(texture.Resize(kBenchmarkCanvasSize));
  while (state.KeepRunning()) {
    texture.Exposure(2.0f);
  }
}
BENCHMARK(Exposure)->Unit(benchmark::TimeUnit::kMillisecond);

static void Brightness(benchmark::State& state) {
  Texture texture;
  NS_ASSERT(texture.Resize(kBenchmarkCanvasSize));
  while (state.KeepRunning()) {
    texture.Brightness(0.5f);
  }
}
BENCHMARK(Brightness)->Unit(benchmark::TimeUnit::kMillisecond);

static void RGBALevels(benchmark::State& state) {
  Texture texture;
  NS_ASSERT(texture.Resize(kBenchmarkCanvasSize));
  while (state.KeepRunning()) {
    texture.RGBALevels(0.5f, 1.0, 0.0, 1.0f);
  }
}
BENCHMARK(RGBALevels)->Unit(benchmark::TimeUnit::kMillisecond);

static void Swizzle(benchmark::State& state) {
  Texture texture;
  NS_ASSERT(texture.Resize(kBenchmarkCanvasSize));
  while (state.KeepRunning()) {
    texture.Swizzle(Component::kAlpha,  //
                    Component::kRed,    //
                    Component::kGreen,  //
                    Component::kAlpha   //
    );
  }
}
BENCHMARK(Swizzle)->Unit(benchmark::TimeUnit::kMillisecond);

}  // namespace ns

BENCHMARK_MAIN();
