#include "cytnx.hpp"
#include <algorithm>
#include <gtest/gtest.h>

#include "../test_tools.h"

using namespace cytnx;
using namespace testing;
using namespace TestTools;

namespace SortTest {

  void CheckResult(const Tensor& sorted, const Tensor& original);

  void TestSortAllTypes(const std::vector<cytnx_uint64>& shape, const std::string& test_name) {
    for (auto dtype : dtype_list) {
      if (dtype == Type.Bool) {
        continue;
      }
      SCOPED_TRACE("Testing " + test_name + " with dtype: " + std::to_string(dtype));
      Tensor in = Tensor(shape, dtype).to(cytnx::Device.cuda);
      InitTensorUniform(in);
      Tensor sorted = algo::Sort(in);
      CheckResult(sorted, in);
    }
  }

  TEST(Sort, gpu_1d_tensor_all_types) { TestSortAllTypes({1024}, "1D tensor"); }

  TEST(Sort, gpu_2d_tensor_all_types) { TestSortAllTypes({512, 16}, "2D tensor"); }

  TEST(Sort, gpu_3d_tensor_all_types) { TestSortAllTypes({32, 16, 64}, "3D tensor"); }

  TEST(Sort, gpu_4d_tensor_all_types) { TestSortAllTypes({8, 16, 32, 64}, "4D tensor"); }

  TEST(Sort, gpu_single_element_all_types) {
    for (auto dtype : dtype_list) {
      if (dtype == Type.Bool) {
        continue;
      }
      Tensor in = Tensor({1}, dtype).to(cytnx::Device.cuda);
      InitTensorUniform(in);
      Tensor sorted = algo::Sort(in);
      CheckResult(sorted, in);
    }
  }

  void CheckResult(const Tensor& sorted, const Tensor& original) {
    EXPECT_EQ(sorted.shape(), original.shape());
    EXPECT_EQ(sorted.dtype(), original.dtype());
    EXPECT_EQ(sorted.device(), original.device());

    // Compare CUDA sort result and CPU sort result
    Tensor original_cpu = original.to(Device.cpu);
    Tensor expected = algo::Sort(original_cpu);
    Tensor sorted_cpu = sorted.to(Device.cpu);
    EXPECT_TRUE(AreEqTensor(sorted_cpu, expected));
  }

}  // namespace SortTest
