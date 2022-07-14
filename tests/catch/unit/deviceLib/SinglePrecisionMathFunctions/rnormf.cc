#include "../device_tests_common.hh"
GENERATE_KERNEL(rnormf, rnormf(1, const_cast<float*>(a)));