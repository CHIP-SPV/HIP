#include "../device_tests_common.hh"
GENERATE_KERNEL(nanf, nanf(const_cast<char*>(reinterpret_cast<char*>(a))));