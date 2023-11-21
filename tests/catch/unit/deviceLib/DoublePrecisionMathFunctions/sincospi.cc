#include "../device_tests_common.hh"

__device__ double sin_cospi(double* a, size_t x) {
  sincospi(a[x], &a[x+1], &a[x+2]);
  return a[x+1];
}

GENERATE_KERNEL_DOUBLE(sincospi, sin_cospi(a, x));
