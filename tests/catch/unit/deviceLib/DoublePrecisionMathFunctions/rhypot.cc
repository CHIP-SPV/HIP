#include "../device_tests_common.hh"
GENERATE_KERNEL_DOUBLE(rhypot, rhypot(a[x], a[x+1]));