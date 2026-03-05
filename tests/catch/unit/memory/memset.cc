#include <hip_test_common.hh>

TEST_CASE("Unit_hipMemset_4bytes") {
  int* d_a;
  auto res = hipMalloc(&d_a, sizeof(int));
  REQUIRE(res == hipSuccess);
  res = hipMemset(d_a, 0, sizeof(int));
  REQUIRE(res == hipSuccess);
  res = hipFree(d_a);
  REQUIRE(res == hipSuccess);
}

TEST_CASE("Unit_hipMemset_4bytes_hostMem") {
  hipDeviceProp_t prop;
  HIP_CHECK(hipGetDeviceProperties(&prop, 0));
  if (!prop.canMapHostMemory) {
    HipTest::HIP_SKIP_TEST("Test requires canMapHostMemory support");
    return;
  }
  int* d_a;
  auto res = hipHostMalloc(&d_a, sizeof(int), 0);
  REQUIRE(res == hipSuccess);
  res = hipMemset(d_a, 0, sizeof(int));
  REQUIRE(res == hipSuccess);
  res = hipHostFree(d_a);
  REQUIRE(res == hipSuccess);
}
