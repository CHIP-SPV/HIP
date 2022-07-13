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


GENERATE_KERNEL(acos, acos(1.0));
GENERATE_KERNEL(acosh, acosh(1.0));
GENERATE_KERNEL(asin, asin(1.0));
GENERATE_KERNEL(asinh, asinh(1.0));
GENERATE_KERNEL(atan2, atan2(1.0, 1.0));
GENERATE_KERNEL(atan, atan(1.0));
GENERATE_KERNEL(atanh, atanh(1.0));
GENERATE_KERNEL(cbrt, cbrt(1.0));
GENERATE_KERNEL(ceil, ceil(1.0));
GENERATE_KERNEL(copysign, copysign(1.0, 1.0));
GENERATE_KERNEL(cos, cos(1.0));
GENERATE_KERNEL(cosh, cosh(1.0));
GENERATE_KERNEL(cospi, cospi(1.0));

GENERATE_KERNEL(cyl_bessel_i0, cyl_bessel_i0(1.0));
GENERATE_KERNEL(cyl_bessel_i1, cyl_bessel_i1(1.0));
GENERATE_KERNEL(erfc, erfc(1.0));
GENERATE_KERNEL(erfcinv, erfcinv(1.0));
GENERATE_KERNEL(erfcx, erfcx(1.0));
GENERATE_KERNEL(erf, erf(1.0));
GENERATE_KERNEL(erfinv, erfinv(1.0));
GENERATE_KERNEL(exp10, exp10(1.0));
GENERATE_KERNEL(exp2, exp2(1.0));
GENERATE_KERNEL(exp, exp(1.0));
GENERATE_KERNEL(expm1, expm1(1.0));
GENERATE_KERNEL(fabs, fabs(1.0));
GENERATE_KERNEL(fdim, fdim(1.0, 1.0));
// GENERATE_KERNEL(fdivide, fdivide(1.0, 1.0)); //not defined for DP
GENERATE_KERNEL(floor, floor(1.0));
GENERATE_KERNEL(fma, fma(1.0, 1.0, 1.0));
GENERATE_KERNEL(fmax, fmax(1.0, 1.0));
GENERATE_KERNEL(fmin, fmin(1.0, 1.0));
GENERATE_KERNEL(fmod, fmod(1.0, 1.0));
GENERATE_KERNEL(frexp, frexp(1.0, reinterpret_cast<int*>(a)));
GENERATE_KERNEL(hypot, hypot(1.0, 1.0));
GENERATE_KERNEL(ilogb, ilogb(1.0));
GENERATE_KERNEL(isfinite, isfinite(1.0));
GENERATE_KERNEL(isinf, isinf(1.0));
GENERATE_KERNEL(isnan, isnan(1.0));

 /**
 Enalbing this test makes all tests fail assertions
 PROBLEMO GENERATE_KERNEL(j0, j0(1.0));
 PROBLEMO GENERATE_KERNEL(j1, j1(1.0));
 PROBLEMO GENERATE_KERNEL(jn, jn(1, 1.0));
 */

GENERATE_KERNEL(ldexp, ldexp(1.0, 1)); 

//GENERATE_KERNEL(lgamma, lgamma(1.0));// missing implementation, only for lgamma
//GENERATE_KERNEL(llrint, llrint(1.0));//missing implelemntation, calls cuda
//GENERATE_KERNEL(llround, llround(1.0));//missing implementation

GENERATE_KERNEL(log10, log10(1.0));
GENERATE_KERNEL(log1p, log1p(1.0));
GENERATE_KERNEL(log2, log2(1.0));
GENERATE_KERNEL(logb, logb(1.0));
GENERATE_KERNEL(log, log(1.0));

// GENERATE_KERNEL(lrint, lrint(1.0)); //missing
// GENERATE_KERNEL(lround, lround(1.0)); //missing
GENERATE_KERNEL(max, max(1.0, 1.0));
GENERATE_KERNEL(min, min(1.0, 1.0));
GENERATE_KERNEL(modf, modf(1.0, (a)));
GENERATE_KERNEL(nan, nan(const_cast<char*>(reinterpret_cast<char*>(a))));
GENERATE_KERNEL(nearbyint, nearbyint(1.0));
GENERATE_KERNEL(nextafter, nextafter(1.0, 2.0));
GENERATE_KERNEL(norm3d, norm3d(1.0, 2.0, 3.0));
GENERATE_KERNEL(norm4d, norm4d(1.0, 2.0, 3.0, 4.0));
// GENERATE_KERNEL(normcdf, normcdf(1.0)); // bad OCML
// GENERATE_KERNEL(normcdfinv, normcdfinv(1.0));// bad OCML
// GENERATE_KERNEL(norm, norm(1, const_cast<double*>(a)));// missing implementation
GENERATE_KERNEL(pow, pow(1.0, 2.0));
GENERATE_KERNEL(rcbrt, rcbrt(1.0));
GENERATE_KERNEL(remainder, remainder(1.0, 2.0));
GENERATE_KERNEL(remquo, remquo(1.0, 2.0, reinterpret_cast<int*>(a)));
GENERATE_KERNEL(rhypot, rhypot(1.0, 2.0));
// GENERATE_KERNEL(rint, rint(1.0)); // missing impl
// GENERATE_KERNEL(rnorm3d, rnorm3d(1.0, 2.0, 3.0)); //broken
// GENERATE_KERNEL(rnorm4d, rnorm4d(1.0, 2.0, 3.0, 4.0)); //broken

GENERATE_KERNEL(rnorm, rnorm(1, const_cast<double*>(a)));

GENERATE_KERNEL(round, round(1.0));
GENERATE_KERNEL(rsqrt, rsqrt(1.0));
GENERATE_KERNEL(scalbln, scalbln(1.0, 1));
GENERATE_KERNEL(scalbn, scalbn(1.0, 1));
GENERATE_KERNEL(signbit, signbit(1.0));
GENERATE_KERNEL(sincos, sincos(1.0, (a), (a)));
GENERATE_KERNEL(sincospi, sincospi(1.0, (a), (a)));
GENERATE_KERNEL(sin, sin(1.0));
GENERATE_KERNEL(sinh, sinh(1.0));
GENERATE_KERNEL(sinpi, sinpi(1.0));
GENERATE_KERNEL(sqrt, sqrt(1.0));
GENERATE_KERNEL(tan, tan(1.0));
GENERATE_KERNEL(tanh, tanh(1.0));
GENERATE_KERNEL(tgamma, tgamma(1.0));
GENERATE_KERNEL(trunc, trunc(1.0));
GENERATE_KERNEL(y0, y0(1.0));
GENERATE_KERNEL(y1, y1(1.0));
// GENERATE_KERNEL(yn, yn(1, 1.0)); // broken