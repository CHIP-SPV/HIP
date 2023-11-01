#include "../device_tests_common.hh"
GENERATE_KERNEL_FLOAT(frexpf, frexpf(a[x], reinterpret_cast<int*>(a)));