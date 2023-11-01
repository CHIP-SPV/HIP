#include "../device_tests_common.hh"
GENERATE_KERNEL_FLOAT(nextafterf, nextafterf(a[x], a[x+1]));