#include "../device_tests_common.hh"

__device__ double sin_cos(double* a, size_t x) {
  sincos(a[x], &a[x+1], &a[x+2]);
  return a[x+1];
}


GENERATE_KERNEL_DOUBLE(sincos, sin_cos(a, x));
