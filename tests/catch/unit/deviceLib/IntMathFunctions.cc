/*
Copyright (c) 2021 - 2021 Advanced Micro Devices, Inc. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include <hip_test_common.hh>

#define LEN 512
#define SIZE LEN << 2

__global__ void testKernel_max(int* a) {
  const unsigned long long cull_int = 1;
  const long long int cll_int = 1;
  unsigned long long int ull_int;
  long long int ll_int;
  const unsigned long int cul_int = 1;
  const long int cl_int = 1;
  unsigned long int ul_int;
  long int l_int;
  const unsigned int cu_int = 1;
  const int c_int = 1;
  unsigned int u_int;
  int _int;

  int tid = threadIdx.x + blockIdx.x * blockDim.x;

  ull_int = max(cull_int, cll_int);
  ull_int = max(cll_int, cull_int);
  ull_int = max(cull_int, cull_int);
  ll_int = max(cll_int, cll_int);
  ul_int = max(cul_int, cl_int);
  ul_int = max(cl_int, cul_int);
  ul_int = max(cul_int, cul_int);
  l_int = max(cl_int, cl_int);
  u_int = max(cu_int, c_int);
  u_int = max(c_int, cu_int);
  u_int = max(cu_int, cu_int);
  _int = max(c_int, c_int);
  // ull_int = ullmax(cull_int, cull_int); //undefined
  // u_int = umax(cu_int, cu_int); //undefined
}

__global__ void testKernel_min(int* a) {
  const unsigned long long cull_int = 1;
  const long long int cll_int = 1;
  unsigned long long int ull_int;
  long long int ll_int;
  const unsigned long int cul_int = 1;
  const long int cl_int = 1;
  unsigned long int ul_int;
  long int l_int;
  const unsigned int cu_int = 1;
  const int c_int = 1;
  unsigned int u_int;
  int _int;

  int tid = threadIdx.x + blockIdx.x * blockDim.x;

  ull_int = min(cull_int, cll_int);
  ull_int = min(cll_int, cull_int);
  ull_int = min(cull_int, cull_int);
  ll_int = min(cll_int, cll_int);
  ul_int = min(cul_int, cl_int);
  ul_int = min(cl_int, cul_int);
  ul_int = min(cul_int, cul_int);
  l_int = min(cl_int, cl_int);
  u_int = min(cu_int, c_int);
  u_int = min(c_int, cu_int);
  u_int = min(cu_int, cu_int);
  _int = min(c_int, c_int);
  // ull_int = ullmin(cull_int, cull_int); //undefined
  // u_int = umin(cu_int, cu_int); //undefined
}


#define GENERATE_KERNEL(FUNCNAME, FUNC)                                                            \
  __global__ void testKernel_##FUNCNAME(int* a) {                                                  \
    int tid = threadIdx.x + blockIdx.x * blockDim.x;                                               \
    FUNC;                                                                                          \
  }                                                                                                \
  TEST_CASE("Unit_deviceFunctions_CompileTest_" #FUNCNAME) {                                       \
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


GENERATE_KERNEL(abs, abs(1));
GENERATE_KERNEL(labs, labs(1l));
GENERATE_KERNEL(llabs, llabs(1ll));

TEST_CASE("Unit_deviceFunctions_CompileTest_Intmax") {
  int* Outd;
  auto res = hipMalloc((void**)&Outd, SIZE);
  REQUIRE(res == hipSuccess);
  hipLaunchKernelGGL(testKernel_max, dim3(LEN, 1, 1), dim3(1, 1, 1), 0, 0, Outd);
  HIP_CHECK(hipGetLastError());
  res = hipDeviceSynchronize();
  REQUIRE(res == hipSuccess);
  res = hipGetLastError();
  REQUIRE(res == hipSuccess);
  HIP_CHECK(hipFree(Outd));
}

TEST_CASE("Unit_deviceFunctions_CompileTest_Intmin") {
  int* Outd;
  auto res = hipMalloc((void**)&Outd, SIZE);
  REQUIRE(res == hipSuccess);
  hipLaunchKernelGGL(testKernel_min, dim3(LEN, 1, 1), dim3(1, 1, 1), 0, 0, Outd);
  HIP_CHECK(hipGetLastError());
  res = hipDeviceSynchronize();
  REQUIRE(res == hipSuccess);
  res = hipGetLastError();
  REQUIRE(res == hipSuccess);
  HIP_CHECK(hipFree(Outd));
}