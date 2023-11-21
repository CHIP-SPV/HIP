#include "../device_tests_common.hh"

__device__ float __sin_cosf(float* a, size_t x) {
  __sincosf(a[x], &a[x+1], &a[x+2]);
  return a[x+1];
}


GENERATE_KERNEL_FLOAT(__sincosf, __sin_cosf(a, x)); 
