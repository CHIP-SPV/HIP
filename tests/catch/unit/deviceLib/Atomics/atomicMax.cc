#include "../device_tests_common.hh"
GENERATE_KERNEL_ATOMICS(atomicMax_int, int, atomicMax((int*)nullptr, (int)1))
GENERATE_KERNEL_ATOMICS(atomicMax_usigned_int, unsigned int, atomicMax((unsigned int*)nullptr, (unsigned int)1))
GENERATE_KERNEL_ATOMICS(atomicMax_unsigned_long_long, unsigned long long, atomicMax((unsigned long long*)nullptr, (unsigned long long)1))