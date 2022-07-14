#include <hip_test_common.hh>

#define LEN 512
#define SIZE LEN << 2

#define GENERATE_KERNEL(FUNCNAME, FUNC)                                                            \
  __global__ void testKernel_##FUNCNAME(float* a) {                                                \
    int tid = threadIdx.x + blockIdx.x * blockDim.x;                                               \
    FUNC;                                                                                          \
  }                                                                                                \
  TEST_CASE("Unit_deviceFunctions_CompileTest_" #FUNCNAME) {                                       \
    float* Outd;                                                                                   \
    auto res = hipMalloc((void**)&Outd, SIZE);                                                     \
    REQUIRE(res == hipSuccess);                                                                    \
    hipLaunchKernelGGL(testKernel_##FUNCNAME, dim3(LEN, 1, 1), dim3(1, 1, 1), 0, 0, Outd);         \
    HIP_CHECK(hipGetLastError());                                                                  \
    res = hipDeviceSynchronize();                                                                  \
    REQUIRE(res == hipSuccess);                                                                    \
    res = hipGetLastError();                                                                       \
    REQUIRE(res == hipSuccess);                                                                    \
    HIP_CHECK(hipFree(Outd));                                                                      \
  }