#include "../device_tests_common.hh"
GENERATE_KERNEL_FLOAT(__fsqrt_rd, __fsqrt_rd(a[x]));
GENERATE_KERNEL_FLOAT(__fsqrt_rn, __fsqrt_rn(a[x]));
GENERATE_KERNEL_FLOAT(__fsqrt_ru, __fsqrt_ru(a[x]));
GENERATE_KERNEL_FLOAT(__fsqrt_rz, __fsqrt_rz(a[x]));