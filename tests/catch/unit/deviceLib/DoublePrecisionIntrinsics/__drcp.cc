#include "../device_tests_common.hh"
GENERATE_KERNEL_DOUBLE(__drcp_rd, __drcp_rd(a[x]));
GENERATE_KERNEL_DOUBLE(__drcp_rn, __drcp_rn(a[x]));
GENERATE_KERNEL_DOUBLE(__drcp_ru, __drcp_ru(a[x]));
GENERATE_KERNEL_DOUBLE(__drcp_rz, __drcp_rz(a[x]));