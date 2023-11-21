#include "../device_tests_common.hh"
GENERATE_KERNEL_FLOAT(__fsub_rd, __fsub_rd(a[x], a[x])); 
GENERATE_KERNEL_FLOAT(__fsub_rn, __fsub_rn(a[x], a[x])); 
GENERATE_KERNEL_FLOAT(__fsub_ru, __fsub_ru(a[x], a[x])); 
GENERATE_KERNEL_FLOAT(__fsub_rz, __fsub_rz(a[x], a[x])); 