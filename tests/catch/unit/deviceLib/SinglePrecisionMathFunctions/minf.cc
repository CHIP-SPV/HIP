#include "../device_tests_common.hh"
// this file is named minf.cc to not duplicate CMake target names
GENERATE_KERNEL_FLOAT(min, min(a[x], a[x]));