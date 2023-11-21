#include "../device_tests_common.hh"
GENERATE_KERNEL_FLOAT(__frcp_rd, __frcp_rd(a[x]));
GENERATE_KERNEL_FLOAT(__frcp_rn, __frcp_rn(a[x]));
GENERATE_KERNEL_FLOAT(__frcp_ru, __frcp_ru(a[x]));
GENERATE_KERNEL_FLOAT(__frcp_rz, __frcp_rz(a[x]));