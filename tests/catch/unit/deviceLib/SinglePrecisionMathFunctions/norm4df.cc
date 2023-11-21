#include "../device_tests_common.hh"
GENERATE_KERNEL_FLOAT(norm4df, norm4df(a[x], a[x+1], a[x+2], a[x+3]));