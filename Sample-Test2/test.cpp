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


TEST(TestVector, Test_init) {
	Vector A;
	EXPECT_EQ(A.Get_size(), 0);
	Vector B(10);
	EXPECT_EQ(B.Get_size(), 1);
	EXPECT_EQ(B[0], 10);
	int d[4] = { 13, 1, 2, -100 };
	Vector C(4, d);
	EXPECT_EQ(C[2], 2);
	EXPECT_EQ(C[0], 13);
	EXPECT_EQ(C[3], -100);
	EXPECT_EQ(C.Get_size(), 4);
}

TEST(TestVector, TestAdd) {
	int arr[3] = { 9, 6, 31 };
	Vector A(3, arr);
	int arr1[3] = { 1, 4, 19 };
	Vector B(3, arr1);
	Vector C = A + B;
	EXPECT_EQ(C[0], 10);
	EXPECT_EQ(C[2], 50);
	EXPECT_EQ(C.Get_size(), 3);
}

TEST(TestVector, TestAddOperator) {
	int arr[3] = { 9, 6, 31 };
	Vector A(3, arr);
	int arr1[3] = { 1, 4, 19 };
	Vector B(3, arr1);
	Vector C = A + B;
	EXPECT_EQ(C[0], 10);
	EXPECT_EQ(C[2], 50);
	EXPECT_EQ(C.Get_size(), 3);
}


TEST(TestVector, Test_vector_slice) {
	int arr[6] = { 9, 6, 31, 13, 23, 104 };
	Vector A(6, arr);
	Vector C = A.Vector_slice(3, 3);
	EXPECT_EQ(C[0], 31);
	EXPECT_EQ(C[2], 23);
	EXPECT_EQ(C.Get_size(), 3);
}

TEST(TestVector, Test_Add_new_element) {
	int arr[6] = { 9, 6, 31, 13, 23, 104 };
	Vector A(6, arr);
	EXPECT_EQ(A.Get_size(), 6);
	A.AddNewElement(16);
	EXPECT_EQ(A[0], 9);
	EXPECT_EQ(A[2], 31);
	EXPECT_EQ(A[6], 16);
	EXPECT_EQ(A.Get_size(), 7);
}

TEST(TestVector, Test_Sort) {
	int arr[6] = { 9, 6, 1, 2, 23, 104 };
	Vector A(6, arr);
	A.Sort();
	EXPECT_EQ(A[0], 1);
	EXPECT_EQ(A[2], 6);
	EXPECT_EQ(A[5], 104);
}

TEST(TestVector, Test_Find_Max) {
	int arr[6] = { 9, 6, 31, 13, 23, 104 };
	Vector A(6, arr);
	EXPECT_EQ(A.FindMax(), 104);
}

TEST(TestVector, Test_copy) {
	Vector A(8);
	Vector B = A;
	EXPECT_EQ(B[0], 8);
 }

TEST(TestVector, Test_Operator_eq) {
	Vector A = 3;
	EXPECT_EQ(A[0], 3);
}

TEST(TestVector, Test_assignment_operator) {
	Vector A = 3, B = 6;
	EXPECT_EQ(B[0], 6);
	B = A;
	EXPECT_EQ(B[0], 3);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}