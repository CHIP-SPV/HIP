#include "../device_tests_common.hh"
GENERATE_KERNEL_DOUBLE(norm3d, norm3d(a[x], a[x+1], a[x+2]));