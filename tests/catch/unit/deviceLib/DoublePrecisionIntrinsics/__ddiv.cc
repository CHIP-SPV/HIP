#include "../device_tests_common.hh"
GENERATE_KERNEL_DOUBLE(__ddiv_rd, __ddiv_rd(a[x], a[x]));
GENERATE_KERNEL_DOUBLE(__ddiv_rn, __ddiv_rn(a[x], a[x]));
GENERATE_KERNEL_DOUBLE(__ddiv_ru, __ddiv_ru(a[x], a[x]));
GENERATE_KERNEL_DOUBLE(__ddiv_rz, __ddiv_rz(a[x], a[x]));