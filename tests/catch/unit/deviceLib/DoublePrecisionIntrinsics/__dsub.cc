#include "../device_tests_common.hh"
GENERATE_KERNEL_DOUBLE(__dsub_rd, __dsub_rd(a[x], a[x]));
GENERATE_KERNEL_DOUBLE(__dsub_rn, __dsub_rn(a[x], a[x]));
GENERATE_KERNEL_DOUBLE(__dsub_ru, __dsub_ru(a[x], a[x]));
GENERATE_KERNEL_DOUBLE(__dsub_rz, __dsub_rz(a[x], a[x]));