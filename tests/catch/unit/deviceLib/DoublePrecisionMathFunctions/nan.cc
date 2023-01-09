#include "../device_tests_common.hh"
GENERATE_KERNEL_DOUBLE(nan, nan(const_cast<char*>(reinterpret_cast<char*>(a))));