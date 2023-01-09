#include <hip_test_common.hh>

#define LEN 512
#define SIZE LEN << 2

#define GENERATE_KERNEL_DOUBLE(FUNCNAME, FUNC)                                                     \
  __global__ void testKernel_##FUNCNAME(double* a) {                                               \
    int tid = threadIdx.x + blockIdx.x * blockDim.x;                                               \
    FUNC;                                                                                          \
  }                                                                                                \
  TEST_CASE("Unit_deviceFunctions_CompileTest_" #FUNCNAME "_double") {                             \
    double* Outd;                                                                                  \
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

#define GENERATE_KERNEL_FLOAT(FUNCNAME, FUNC)                                                      \
  __global__ void testKernel_##FUNCNAME(float* a) {                                                \
    int tid = threadIdx.x + blockIdx.x * blockDim.x;                                               \
    FUNC;                                                                                          \
  }                                                                                                \
  TEST_CASE("Unit_deviceFunctions_CompileTest_" #FUNCNAME "_float") {                              \
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

#define GENERATE_KERNEL_INTEGER(FUNCNAME, FUNC)                                                    \
  __global__ void testKernel_##FUNCNAME(int* a) {                                                  \
    int tid = threadIdx.x + blockIdx.x * blockDim.x;                                               \
    FUNC;                                                                                          \
  }                                                                                                \
  TEST_CASE("Unit_deviceFunctions_CompileTest_" #FUNCNAME "_int") {                                \
    int* Outd;                                                                                     \
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