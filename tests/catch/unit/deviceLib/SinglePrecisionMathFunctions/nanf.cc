#include "../device_tests_common.hh"
GENERATE_KERNEL_FLOAT(nanf, nanf(const_cast<char*>(reinterpret_cast<char*>(a))));