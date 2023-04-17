#include "../device_tests_common.hh"
GENERATE_KERNEL_ATOMICS(atomicCAS_system_int, int, atomicCAS_system((int*)nullptr, (int)1, (int)1))
GENERATE_KERNEL_ATOMICS(atomicCAS_system_unsigned_int, unsigned int, atomicCAS_system((unsigned int*)nullptr, (unsigned int)1, (unsigned int)1))
GENERATE_KERNEL_ATOMICS(atomicCAS_system_unsigned_long_long, unsigned long long, atomicCAS_system((unsigned long long*)nullptr, (unsigned long long)1, (unsigned long long)1))
