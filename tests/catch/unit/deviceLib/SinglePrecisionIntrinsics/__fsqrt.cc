#include "../device_tests_common.hh"
GENERATE_KERNEL(__fsqrt_rd, __fsqrt_rd(1.0f));
GENERATE_KERNEL(__fsqrt_rn, __fsqrt_rn(1.0f));
GENERATE_KERNEL(__fsqrt_ru, __fsqrt_ru(1.0f));
GENERATE_KERNEL(__fsqrt_rz, __fsqrt_rz(1.0f));