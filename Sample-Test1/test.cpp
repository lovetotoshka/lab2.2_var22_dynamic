#include "pch.h"
#include "../StaticLib_vector/pch.h"
using namespace lab3;

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(testVector, Test1) {
	Vector A(1);
	EXPECT_EQ(A.Get_arr_i(0), 1);
}