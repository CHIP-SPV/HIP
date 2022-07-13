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
//#define RUN_KERNEL(FUNCNAME, FUNC)                                                                 \

#define GENERATE_KERNEL(FUNCNAME, FUNC)                                                            \
  __global__ void testKernel_##FUNCNAME(double* a) {                                                \
    int tid = threadIdx.x + blockIdx.x * blockDim.x;                                               \
    FUNC;                                                                                          \
  }                                                                                                \
  TEST_CASE("Unit_deviceFunctions_CompileTest_" #FUNCNAME) {                                       \
    double* Outd;                                                                                   \
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

GENERATE_KERNEL(__dadd_rd, __dadd_rd(1.0, 1.0));
GENERATE_KERNEL(__dadd_rn, __dadd_rn(1.0, 1.0));
GENERATE_KERNEL(__dadd_ru, __dadd_ru(1.0, 1.0));
GENERATE_KERNEL(__dadd_rz, __dadd_rz(1.0, 1.0));

GENERATE_KERNEL(__ddiv_rd, __ddiv_rd(1.0, 1.0));
GENERATE_KERNEL(__ddiv_rn, __ddiv_rn(1.0, 1.0));
GENERATE_KERNEL(__ddiv_ru, __ddiv_ru(1.0, 1.0));
GENERATE_KERNEL(__ddiv_rz, __ddiv_rz(1.0, 1.0));

GENERATE_KERNEL(__dmul_rd, __dmul_rd(1.0, 1.0));
GENERATE_KERNEL(__dmul_rn, __dmul_rn(1.0, 1.0));
GENERATE_KERNEL(__dmul_ru, __dmul_ru(1.0, 1.0));
GENERATE_KERNEL(__dmul_rz, __dmul_rz(1.0, 1.0));

GENERATE_KERNEL(__drcp_rd, __drcp_rd(1.0));
GENERATE_KERNEL(__drcp_rn, __drcp_rn(1.0));
GENERATE_KERNEL(__drcp_ru, __drcp_ru(1.0));
GENERATE_KERNEL(__drcp_rz, __drcp_rz(1.0));
 
GENERATE_KERNEL(__dsqrt_rd, __dsqrt_rd(1.0));
GENERATE_KERNEL(__dsqrt_rn, __dsqrt_rn(1.0));
GENERATE_KERNEL(__dsqrt_ru, __dsqrt_ru(1.0));
GENERATE_KERNEL(__dsqrt_rz, __dsqrt_rz(1.0));

GENERATE_KERNEL(__dsub_rd, __dsub_rd(1.0, 1.0));
GENERATE_KERNEL(__dsub_rn, __dsub_rn(1.0, 1.0));
GENERATE_KERNEL(__dsub_ru, __dsub_ru(1.0, 1.0));
GENERATE_KERNEL(__dsub_rz, __dsub_rz(1.0, 1.0));
  
GENERATE_KERNEL(__fma_rd, __fma_rd(1.0, 1.0, 1.0));
GENERATE_KERNEL(__fma_rn, __fma_rn(1.0, 1.0, 1.0));
GENERATE_KERNEL(__fma_ru, __fma_ru(1.0, 1.0, 1.0));
GENERATE_KERNEL(__fma_rz, __fma_rz(1.0, 1.0, 1.0));