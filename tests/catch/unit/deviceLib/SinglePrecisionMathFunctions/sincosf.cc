#include "../device_tests_common.hh"

__device__ float sin_cos(float* a, size_t x) {
  sincosf(a[x], &a[x+1], &a[x+2]);
  return a[x+1];
}

GENERATE_KERNEL_FLOAT(sincosf, sin_cos(a, x) );

