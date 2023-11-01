#include "../device_tests_common.hh"

__device__ float sin_cospif(float* a, size_t x) {
  sincospif(a[x], &a[x+1], &a[x+2]);
  return a[x+1];
}

GENERATE_KERNEL_FLOAT(sincospif, sin_cospif(a, x));
