#include "../device_tests_common.hh"
GENERATE_KERNEL_DOUBLE(nextafter, nextafter(a[x], a[x+1]));