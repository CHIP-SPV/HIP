#include "../device_tests_common.hh"
GENERATE_KERNEL_FLOAT(__fdividef, __fdividef(a[x], a[x]));