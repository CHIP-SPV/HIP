#include "../device_tests_common.hh"
// this file is named maxf.cc to not duplicate CMake target names
GENERATE_KERNEL_FLOAT(max, max(a[x], a[x]));