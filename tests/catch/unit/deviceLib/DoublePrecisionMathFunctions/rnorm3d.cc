#include "../device_tests_common.hh"
GENERATE_KERNEL_DOUBLE(rnorm3d, rnorm3d(a[x], a[x+1], a[x+2]));