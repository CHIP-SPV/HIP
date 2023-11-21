#include "../device_tests_common.hh"
GENERATE_KERNEL_DOUBLE(frexp, frexp(a[x], reinterpret_cast<int*>(a)));
