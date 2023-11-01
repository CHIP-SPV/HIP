#include "../device_tests_common.hh"
GENERATE_KERNEL_FLOAT(rnorm3df, rnorm3df(a[x], a[x+1], a[x+2]));