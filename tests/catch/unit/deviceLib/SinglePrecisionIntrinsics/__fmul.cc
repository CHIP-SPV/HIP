#include "../device_tests_common.hh"
GENERATE_KERNEL_FLOAT(__fmul_rd, __fmul_rd(a[x], a[x]));
GENERATE_KERNEL_FLOAT(__fmul_rn, __fmul_rn(a[x], a[x]));
GENERATE_KERNEL_FLOAT(__fmul_ru, __fmul_ru(a[x], a[x]));
GENERATE_KERNEL_FLOAT(__fmul_rz, __fmul_rz(a[x], a[x]));