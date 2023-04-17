#include "../device_tests_common.hh"
GENERATE_KERNEL_ATOMICS(atomicAnd_int, int, atomicAdd((int*)nullptr, (int)1))
GENERATE_KERNEL_ATOMICS(atomicAnd_unsigned_int, unsigned int, atomicAdd((unsigned int*)nullptr, (unsigned int)1))
GENERATE_KERNEL_ATOMICS(atomicAnd_unsigned_long_long, unsigned long long, atomicAdd((unsigned long long*)nullptr, (unsigned long long)1))
