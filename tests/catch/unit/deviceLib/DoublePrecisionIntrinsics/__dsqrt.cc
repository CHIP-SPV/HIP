#include "../device_tests_common.hh"
GENERATE_KERNEL_DOUBLE(__dsqrt_rd, __dsqrt_rd(a[x]));
GENERATE_KERNEL_DOUBLE(__dsqrt_rn, __dsqrt_rn(a[x]));
GENERATE_KERNEL_DOUBLE(__dsqrt_ru, __dsqrt_ru(a[x]));
GENERATE_KERNEL_DOUBLE(__dsqrt_rz, __dsqrt_rz(a[x]));