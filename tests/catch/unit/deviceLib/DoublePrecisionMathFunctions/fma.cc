#include "../device_tests_common.hh"
GENERATE_KERNEL_DOUBLE(fma, fma(a[x], a[x], a[x]));
