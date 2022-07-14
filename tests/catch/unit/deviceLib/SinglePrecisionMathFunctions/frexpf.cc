#include "../device_tests_common.hh"
GENERATE_KERNEL(frexpf, frexpf(1.0f, reinterpret_cast<int*>(a)));