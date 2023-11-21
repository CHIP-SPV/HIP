#include "../device_tests_common.hh"
GENERATE_KERNEL_FLOAT(__fdiv_rd, __fdiv_rd(a[x], a[x]));
GENERATE_KERNEL_FLOAT(__fdiv_rn, __fdiv_rn(a[x], a[x]));
GENERATE_KERNEL_FLOAT(__fdiv_ru, __fdiv_ru(a[x], a[x]));
GENERATE_KERNEL_FLOAT(__fdiv_rz, __fdiv_rz(a[x], a[x]));