#include "../device_tests_common.hh"
GENERATE_KERNEL(__frcp_rd, __frcp_rd(1.0f));
GENERATE_KERNEL(__frcp_rn, __frcp_rn(1.0f));
GENERATE_KERNEL(__frcp_ru, __frcp_ru(1.0f));
GENERATE_KERNEL(__frcp_rz, __frcp_rz(1.0f));