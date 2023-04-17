#include "../device_tests_common.hh"
GENERATE_KERNEL_ATOMICS(atomicExch_int, int, atomicExch((int*)nullptr, (int)1))
GENERATE_KERNEL_ATOMICS(atomicExch_usigned_int, unsigned int, atomicExch((unsigned int*)nullptr, (unsigned int)1))
GENERATE_KERNEL_ATOMICS(atomicExch_unsigned_long_long, unsigned long long, atomicExch((unsigned long long*)nullptr, (unsigned long long)1))
GENERATE_KERNEL_ATOMICS(atomicExch_float, float, atomicExch((float*)nullptr, (float)1))