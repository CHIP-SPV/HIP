#include "../device_tests_common.hh"
GENERATE_KERNEL_ATOMICS(atomicMin_system_int, int, atomicMin_system((int*)nullptr, (int)1))
GENERATE_KERNEL_ATOMICS(atomicMin_system_usigned_int, unsigned int, atomicMin_system((unsigned int*)nullptr, (unsigned int)1))