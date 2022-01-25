/*
Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.

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
#include <hip_test_process.hh>
#include <regex>

TEST_CASE("Unit_printf_specifier") {

  hip::SpawnProc proc("unit/printfExe/printfSepcifiers", true);
  REQUIRE(0 == proc.run());

#ifdef __HIP_PLATFORM_NVIDIA__

  std::string reference(R"here(xyzzy
%
hello % world
%s
%s0xf01dab1eca55e77e
%cxyzzy
sep
-42
42
123.456000
-123.456000
-1.234560e+02
1.234560E+02
123.456
-123.456
x
(null)
(nil)
3.14159000    hello 0xf01dab1eca55e77e
)here");

  REQUIRE(proc.getOutput(), reference);

#elif !defined(_WIN32)

  // Account for float rounding errors etc. due to unknown platform.
  std::string Reference(R"here(xyzzy
%
hello % world
%s
%s0xf01dab1eca55e77e
%cxyzzy
sep
-42
42
123.45600[01]
-123.45600[01]
-1\.234560e\+02
1\.234560E\+02
123\.456
-123\.456
x
\(null\)
0x
3.14159012[ ]+hello 0xf01dab1eca55e77e
)here");

  std::stringstream GoldenSS(Reference);
  std::stringstream CheckedSS(proc.getOutput());

  std::string Golden, Checked;
  while (getline(GoldenSS, Golden)) {
    REQUIRE(getline(CheckedSS, Checked));
    std::regex RegEx(Golden);
    if (!std::regex_match(Checked, RegEx)) {
      std::cerr << "'" << Checked << "' doesn't match regexp '"
		<< Golden << "'." << std::endl;
      REQUIRE(std::regex_match(Checked, RegEx));
    }
  }

#else

  std::regex reference(R"here(xyzzy
%
hello % world
%s
%sF01DAB1ECA55E77E
%cxyzzy
sep
-42
42
123.456000
-123.456000
-1.234560e+02
1.234560E+02
123.456
-123.456
x

0000000000000000
3.14159000    hello F01DAB1ECA55E77E
)here");

  REQUIRE(proc.getOutput(), reference));

#endif

}
