#include "../device_tests_common.hh"
GENERATE_KERNEL_DOUBLE(remainder, remainder(a[x], a[x+1]));
