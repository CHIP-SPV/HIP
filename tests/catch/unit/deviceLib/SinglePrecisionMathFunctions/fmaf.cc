#include "../device_tests_common.hh"
GENERATE_KERNEL_FLOAT(fmaf, fmaf(a[x], a[x], a[x]));