#include "../device_tests_common.hh"
GENERATE_KERNEL_DOUBLE(__dadd_rd, __dadd_rd(a[x], a[x]));
GENERATE_KERNEL_DOUBLE(__dadd_rn, __dadd_rn(a[x], a[x]));
GENERATE_KERNEL_DOUBLE(__dadd_ru, __dadd_ru(a[x], a[x]));
GENERATE_KERNEL_DOUBLE(__dadd_rz, __dadd_rz(a[x], a[x]));