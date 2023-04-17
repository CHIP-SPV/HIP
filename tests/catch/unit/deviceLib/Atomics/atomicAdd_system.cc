#include "../device_tests_common.hh"
GENERATE_KERNEL_ATOMICS(atomicAdd_system_int, int, atomicAdd_system((int*)nullptr, (int)1))
GENERATE_KERNEL_ATOMICS(atomicAdd_system_usigned_int, unsigned int, atomicAdd_system((unsigned int*)nullptr, (unsigned int)1))
GENERATE_KERNEL_ATOMICS(atomicAdd_system_unsigned_long_long, unsigned long long, atomicAdd_system((unsigned long long*)nullptr, (unsigned long long)1))
GENERATE_KERNEL_ATOMICS(atomicAdd_system_float, float, atomicAdd_system((float*)nullptr, (float)1))
GENERATE_KERNEL_ATOMICS(atomicAdd_system_double, double, atomicAdd_system((double*)nullptr, (double)1))

