#include "../device_tests_common.hh"
GENERATE_KERNEL_FLOAT(powf, powf(a[x], a[x+1]));