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


GENERATE_KERNEL(acosf, acosf(1.0f));
GENERATE_KERNEL(acoshf, acoshf(1.0f));
GENERATE_KERNEL(asinf, asinf(1.0f));
GENERATE_KERNEL(asinhf, asinhf(1.0f));
GENERATE_KERNEL(atan2f, atan2f(1.0f, 1.0f));
GENERATE_KERNEL(atanf, atanf(1.0f));
GENERATE_KERNEL(atanhf, atanhf(1.0f));
GENERATE_KERNEL(cbrtf, cbrtf(1.0f));
GENERATE_KERNEL(ceilf, ceilf(1.0f));
GENERATE_KERNEL(copysignf, copysignf(1.0f, 1.0f));
GENERATE_KERNEL(cosf, cosf(1.0f));
GENERATE_KERNEL(coshf, coshf(1.0f));
GENERATE_KERNEL(cospif, cospif(1.0f));

GENERATE_KERNEL(cyl_bessel_i0f, cyl_bessel_i0f(1.0f));
GENERATE_KERNEL(cyl_bessel_i1f, cyl_bessel_i1f(1.0f));
GENERATE_KERNEL(erfcf, erfcf(1.0f));
GENERATE_KERNEL(erfcinvf, erfcinvf(1.0f));
GENERATE_KERNEL(erfcxf, erfcxf(1.0f));
GENERATE_KERNEL(erff, erff(1.0f));
GENERATE_KERNEL(erfinvf, erfinvf(1.0f));
GENERATE_KERNEL(exp10f, exp10f(1.0f));
GENERATE_KERNEL(exp2f, exp2f(1.0f));
GENERATE_KERNEL(expf, expf(1.0f));
GENERATE_KERNEL(expm1f, expm1f(1.0f));
GENERATE_KERNEL(fabsf, fabsf(1.0f));
GENERATE_KERNEL(fdimf, fdimf(1.0f, 1.0f));
GENERATE_KERNEL(fdividef, fdividef(1.0f, 1.0f));
GENERATE_KERNEL(floorf, floorf(1.0f));
GENERATE_KERNEL(fmaf, fmaf(1.0f, 1.0f, 1.0f));
GENERATE_KERNEL(fmaxf, fmaxf(1.0f, 1.0f));
GENERATE_KERNEL(fminf, fminf(1.0f, 1.0f));
GENERATE_KERNEL(fmodf, fmodf(1.0f, 1.0f));
GENERATE_KERNEL(frexpf, frexpf(1.0f, reinterpret_cast<int*>(a)));
GENERATE_KERNEL(hypotf, hypotf(1.0f, 1.0f));
GENERATE_KERNEL(ilogbf, ilogbf(1.0f));
GENERATE_KERNEL(isfinite, isfinite(1.0f));
GENERATE_KERNEL(isinf, isinf(1.0f));
GENERATE_KERNEL(isnan, isnan(1.0f));

 /**
 Enalbing this test makes all tests fail assertions
 PROBLEMO GENERATE_KERNEL(j0f, j0f(1.0f));
 PROBLEMO GENERATE_KERNEL(j1f, j1f(1.0f));
 PROBLEMO GENERATE_KERNEL(jnf, jnf(1, 1.0f));
 */

GENERATE_KERNEL(ldexpf, ldexpf(1.0f, 1)); 

//GENERATE_KERNEL(lgammaf, lgammaf(1.0f));// missing implementation, only for lgamma
//GENERATE_KERNEL(llrintf, llrintf(1.0f));//missing implelemntation, calls cuda
//GENERATE_KERNEL(llroundf, llroundf(1.0f));//missing implementation

GENERATE_KERNEL(log10f, log10f(1.0f));
GENERATE_KERNEL(log1pf, log1pf(1.0f));
GENERATE_KERNEL(log2f, log2f(1.0f));
GENERATE_KERNEL(logbf, logbf(1.0f));
GENERATE_KERNEL(logf, logf(1.0f));

// GENERATE_KERNEL(lrintf, lrintf(1.0f)); //missing
// GENERATE_KERNEL(lroundf, lroundf(1.0f)); //missing
GENERATE_KERNEL(max, max(1.0f, 1.0f));
GENERATE_KERNEL(min, min(1.0f, 1.0f));
GENERATE_KERNEL(modff, modff(1.0f, a));
GENERATE_KERNEL(nanf, nanf(const_cast<char*>(reinterpret_cast<char*>(a))));
GENERATE_KERNEL(nearbyintf, nearbyintf(1.0f));
GENERATE_KERNEL(nextafterf, nextafterf(1.0f, 2.0f));
GENERATE_KERNEL(norm3df, norm3df(1.0f, 2.0f, 3.0f));
GENERATE_KERNEL(norm4df, norm4df(1.0f, 2.0f, 3.0f, 4.0f));
// GENERATE_KERNEL(normcdff, normcdff(1.0f)); // bad OCML
// GENERATE_KERNEL(normcdfinvf, normcdfinvf(1.0f));// bad OCML
// GENERATE_KERNEL(normf, normf(1, const_cast<float*>(a)));// missing implementation
GENERATE_KERNEL(powf, powf(1.0f, 2.0f));
GENERATE_KERNEL(rcbrtf, rcbrtf(1.0f));
GENERATE_KERNEL(remainderf, remainderf(1.0f, 2.0f));
GENERATE_KERNEL(remquof, remquof(1.0f, 2.0f, reinterpret_cast<int*>(a)));
GENERATE_KERNEL(rhypotf, rhypotf(1.0f, 2.0f));
// GENERATE_KERNEL(rintf, rintf(1.0f)); // missing impl
// GENERATE_KERNEL(rnorm3df, rnorm3df(1.0f, 2.0f, 3.0f)); //broken
// GENERATE_KERNEL(rnorm4df, rnorm4df(1.0f, 2.0f, 3.0f, 4.0f)); //broken
GENERATE_KERNEL(rnormf, rnormf(1, const_cast<float*>(a)));
GENERATE_KERNEL(roundf, roundf(1.0f));
GENERATE_KERNEL(rsqrtf, rsqrtf(1.0f));
GENERATE_KERNEL(scalblnf, scalblnf(1.0f, 1));
GENERATE_KERNEL(scalbnf, scalbnf(1.0f, 1));
GENERATE_KERNEL(signbit, signbit(1.0f));
GENERATE_KERNEL(sincosf, sincosf(1.0f, a, a));
GENERATE_KERNEL(sincospif, sincospif(1.0f, a, a));
GENERATE_KERNEL(sinf, sinf(1.0f));
GENERATE_KERNEL(sinhf, sinhf(1.0f));
GENERATE_KERNEL(sinpif, sinpif(1.0f));
GENERATE_KERNEL(sqrtf, sqrtf(1.0f));
GENERATE_KERNEL(tanf, tanf(1.0f));
GENERATE_KERNEL(tanhf, tanhf(1.0f));
GENERATE_KERNEL(tgammaf, tgammaf(1.0f));
GENERATE_KERNEL(truncf, truncf(1.0f));
GENERATE_KERNEL(y0f, y0f(1.0f));
GENERATE_KERNEL(y1f, y1f(1.0f));
GENERATE_KERNEL(ynf, ynf(1, 1.0f));