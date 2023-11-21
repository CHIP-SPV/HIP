#include "../device_tests_common.hh"
GENERATE_KERNEL_FLOAT(__fmaf_rd, __fmaf_rd(a[x], a[x], a[x]));
GENERATE_KERNEL_FLOAT(__fmaf_rn, __fmaf_rn(a[x], a[x], a[x]));
GENERATE_KERNEL_FLOAT(__fmaf_ru, __fmaf_ru(a[x], a[x], a[x]));
GENERATE_KERNEL_FLOAT(__fmaf_rz, __fmaf_rz(a[x], a[x], a[x]));