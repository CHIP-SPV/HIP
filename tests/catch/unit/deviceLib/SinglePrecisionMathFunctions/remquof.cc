#include "../device_tests_common.hh"
GENERATE_KERNEL_FLOAT(remquof, remquof(a[x], a[x+1], reinterpret_cast<int*>(a)));