#include "../device_tests_common.hh"
GENERATE_KERNEL_DOUBLE(rnorm4d, rnorm4d(a[x], a[x+1], a[x+2], a[x+3]));