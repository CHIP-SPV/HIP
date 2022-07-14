#include "../device_tests_common.hh"
GENERATE_KERNEL(__dsqrt_rd, __dsqrt_rd(1.0));
GENERATE_KERNEL(__dsqrt_rn, __dsqrt_rn(1.0));
GENERATE_KERNEL(__dsqrt_ru, __dsqrt_ru(1.0));
GENERATE_KERNEL(__dsqrt_rz, __dsqrt_rz(1.0));