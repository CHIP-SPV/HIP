#include "../device_tests_common.hh"
GENERATE_KERNEL_DOUBLE(__fma_rd, __fma_rd(a[x], a[x], a[x]));
GENERATE_KERNEL_DOUBLE(__fma_rn, __fma_rn(a[x], a[x], a[x]));
GENERATE_KERNEL_DOUBLE(__fma_ru, __fma_ru(a[x], a[x], a[x]));
GENERATE_KERNEL_DOUBLE(__fma_rz, __fma_rz(a[x], a[x], a[x]));