#include "../device_tests_common.hh"
GENERATE_KERNEL_ATOMICS(atomicCAS_int, int, atomicCAS((int*)nullptr, (int)1, (int)1))
GENERATE_KERNEL_ATOMICS(atomicCAS_unsigned_int, unsigned int, atomicCAS((unsigned int*)nullptr, (unsigned int)1, (unsigned int)1))
GENERATE_KERNEL_ATOMICS(atomicCAS_unsigned_long_long, unsigned long long, atomicCAS((unsigned long long*)nullptr, (unsigned long long)1, (unsigned long long)1))
