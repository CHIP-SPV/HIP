#include "../device_tests_common.hh"
GENERATE_KERNEL_DOUBLE(pow, pow(a[x], a[x+1]));