#include "../device_tests_common.hh"
GENERATE_KERNEL_ATOMICS(atomicAdd_int, int, atomicAdd((int*)nullptr, (int)1))
GENERATE_KERNEL_ATOMICS(atomicAdd_usigned_int, unsigned int, atomicAdd((unsigned int*)nullptr, (unsigned int)1))
GENERATE_KERNEL_ATOMICS(atomicAdd_unsigned_long_long, unsigned long long, atomicAdd((unsigned long long*)nullptr, (unsigned long long)1))
GENERATE_KERNEL_ATOMICS(atomicAdd_float, float, atomicAdd((float*)nullptr, (float)1))
GENERATE_KERNEL_ATOMICS(atomicAdd_double, double, atomicAdd((double*)nullptr, (double)1))