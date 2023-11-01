#include "../device_tests_common.hh"
GENERATE_KERNEL_DOUBLE(remquo, remquo(a[x], a[x+1], reinterpret_cast<int*>(a)));
