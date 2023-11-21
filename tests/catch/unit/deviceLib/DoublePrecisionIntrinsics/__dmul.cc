#include "../device_tests_common.hh"
GENERATE_KERNEL_DOUBLE(__dmul_rd, __dmul_rd(a[x], a[x]));
GENERATE_KERNEL_DOUBLE(__dmul_rn, __dmul_rn(a[x], a[x]));
GENERATE_KERNEL_DOUBLE(__dmul_ru, __dmul_ru(a[x], a[x]));
GENERATE_KERNEL_DOUBLE(__dmul_rz, __dmul_rz(a[x], a[x]));