#include "../device_tests_common.hh"
GENERATE_KERNEL_DOUBLE(norm4d, norm4d(a[x], a[x+1], a[x+2], a[x+3]));
