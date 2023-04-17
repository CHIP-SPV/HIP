#include "../device_tests_common.hh"
GENERATE_KERNEL_ATOMICS(atomicMin_int, int, atomicMin((int*)nullptr, (int)1))
GENERATE_KERNEL_ATOMICS(atomicMin_usigned_int, unsigned int, atomicMin((unsigned int*)nullptr, (unsigned int)1))
GENERATE_KERNEL_ATOMICS(atomicMin_unsigned_long_long, unsigned long long, atomicMin((unsigned long long*)nullptr, (unsigned long long)1))