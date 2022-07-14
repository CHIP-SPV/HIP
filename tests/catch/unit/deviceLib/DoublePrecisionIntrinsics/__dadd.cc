#include "../device_tests_common.hh"
GENERATE_KERNEL(__dadd_rd, __dadd_rd(1.0, 1.0));
GENERATE_KERNEL(__dadd_rn, __dadd_rn(1.0, 1.0));
GENERATE_KERNEL(__dadd_ru, __dadd_ru(1.0, 1.0));
GENERATE_KERNEL(__dadd_rz, __dadd_rz(1.0, 1.0));