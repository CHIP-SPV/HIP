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


GENERATE_KERNEL(__cosf, __cosf(1.0f));
GENERATE_KERNEL(__exp10f, __exp10f(1.0f));
GENERATE_KERNEL(__expf, __expf(1.0f));

GENERATE_KERNEL(__fadd_rd, __fadd_rd(1.0f, 1.0f));
GENERATE_KERNEL(__fadd_rn, __fadd_rn(1.0f, 1.0f));
GENERATE_KERNEL(__fadd_ru, __fadd_ru(1.0f, 1.0f));
GENERATE_KERNEL(__fadd_rz, __fadd_rz(1.0f, 1.0f));

GENERATE_KERNEL(__fdiv_rd, __fdiv_rd(1.0f, 1.0f));
GENERATE_KERNEL(__fdiv_rn, __fdiv_rn(1.0f, 1.0f));
GENERATE_KERNEL(__fdiv_ru, __fdiv_ru(1.0f, 1.0f));
GENERATE_KERNEL(__fdiv_rz, __fdiv_rz(1.0f, 1.0f));

GENERATE_KERNEL(__fdividef, __fdividef(1.0f, 1.0f));

/** undefined
GENERATE_KERNEL(__fmaf_ieee_rd, __fmaf_ieee_rd(1.0f, 1.0f, 1.0f));
GENERATE_KERNEL(__fmaf_ieee_rn, __fmaf_ieee_rn(1.0f, 1.0f, 1.0f));
GENERATE_KERNEL(__fmaf_ieee_ru, __fmaf_ieee_ru(1.0f, 1.0f, 1.0f));
GENERATE_KERNEL(__fmaf_ieee_rz, __fmaf_ieee_rz(1.0f, 1.0f, 1.0f));
 */

GENERATE_KERNEL(__fmaf_rd, __fmaf_rd(1.0f, 1.0f, 1.0f));
GENERATE_KERNEL(__fmaf_rn, __fmaf_rn(1.0f, 1.0f, 1.0f));
GENERATE_KERNEL(__fmaf_ru, __fmaf_ru(1.0f, 1.0f, 1.0f));
GENERATE_KERNEL(__fmaf_rz, __fmaf_rz(1.0f, 1.0f, 1.0f));
 
GENERATE_KERNEL(__fmul_rd, __fmul_rd(1.0f, 1.0f));
GENERATE_KERNEL(__fmul_rn, __fmul_rn(1.0f, 1.0f));
GENERATE_KERNEL(__fmul_ru, __fmul_ru(1.0f, 1.0f));
GENERATE_KERNEL(__fmul_rz, __fmul_rz(1.0f, 1.0f));
 
GENERATE_KERNEL(__frcp_rd, __frcp_rd(1.0f));
GENERATE_KERNEL(__frcp_rn, __frcp_rn(1.0f));
GENERATE_KERNEL(__frcp_ru, __frcp_ru(1.0f));
GENERATE_KERNEL(__frcp_rz, __frcp_rz(1.0f));
 
GENERATE_KERNEL(__frsqrt_rn, __frsqrt_rn(1.0f));

GENERATE_KERNEL(__fsqrt_rd, __fsqrt_rd(1.0f));
GENERATE_KERNEL(__fsqrt_rn, __fsqrt_rn(1.0f));
GENERATE_KERNEL(__fsqrt_ru, __fsqrt_ru(1.0f));
GENERATE_KERNEL(__fsqrt_rz, __fsqrt_rz(1.0f));
 
GENERATE_KERNEL(__fsub_rd, __fsub_rd(1.0f, 1.0f)); 
GENERATE_KERNEL(__fsub_rn, __fsub_rn(1.0f, 1.0f)); 
GENERATE_KERNEL(__fsub_ru, __fsub_ru(1.0f, 1.0f)); 
GENERATE_KERNEL(__fsub_rz, __fsub_rz(1.0f, 1.0f)); 
 
GENERATE_KERNEL(__log10f, __log10f(1.0f)); 
GENERATE_KERNEL(__log2f, __log2f(1.0f)); 
GENERATE_KERNEL(__logf, __logf(1.0f)); 
GENERATE_KERNEL(__powf, __powf(1.0f, 1.0f)); 
GENERATE_KERNEL(__saturatef, __saturatef(1.0f)); 
GENERATE_KERNEL(__sincosf, __sincosf(1.0f, a, a)); 
GENERATE_KERNEL(__sinf, __sinf(1.0f)); 
GENERATE_KERNEL(__tanf, __tanf(1.0f)); 

