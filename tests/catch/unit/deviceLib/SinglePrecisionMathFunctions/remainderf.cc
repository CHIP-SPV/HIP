#include "../device_tests_common.hh"
GENERATE_KERNEL_FLOAT(remainderf, remainderf(a[x], a[x+1]));