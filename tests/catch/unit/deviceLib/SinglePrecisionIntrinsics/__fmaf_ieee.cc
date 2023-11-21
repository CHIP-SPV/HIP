#include "../device_tests_common.hh"
GENERATE_KERNEL_FLOAT(__fmaf_ieee_rd, __fmaf_ieee_rd(a[x], a[x], a[x]));
GENERATE_KERNEL_FLOAT(__fmaf_ieee_rn, __fmaf_ieee_rn(a[x], a[x], a[x]));
GENERATE_KERNEL_FLOAT(__fmaf_ieee_ru, __fmaf_ieee_ru(a[x], a[x], a[x]));
GENERATE_KERNEL_FLOAT(__fmaf_ieee_rz, __fmaf_ieee_rz(a[x], a[x], a[x]));