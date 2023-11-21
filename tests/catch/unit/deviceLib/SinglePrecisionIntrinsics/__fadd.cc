#include "../device_tests_common.hh"
GENERATE_KERNEL_FLOAT(__fadd_rd, __fadd_rd(a[x], a[x]));
GENERATE_KERNEL_FLOAT(__fadd_rn, __fadd_rn(a[x], a[x]));
GENERATE_KERNEL_FLOAT(__fadd_ru, __fadd_ru(a[x], a[x]));
GENERATE_KERNEL_FLOAT(__fadd_rz, __fadd_rz(a[x], a[x]));