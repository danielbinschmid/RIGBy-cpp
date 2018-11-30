#pragma once

#include "gtest/gtest.h"
#include "test_Misc.hpp"
#include "utils/Mean.hpp"

using namespace Eigen;
using namespace std;

class Means_Tests : public testing::Test {};

TEST_F(Means_Tests, Euclidian)
{
	Initialize();
	MatrixXd ref(2, 2), calc;

	ref << 8.25, 0.0, 0.0, 8.25;
	for (int i = 0; i < REPEAT_TEST; ++i) { Mean(VCov, calc, Metric_Euclidian); }
	EXPECT_TRUE(isAlmostEqual(ref, calc)) << ErrorMsg("Mean Euclidian", ref, calc).str();
}

TEST_F(Means_Tests, LogEuclidian)
{
	Initialize();
	MatrixXd ref(2, 2), calc;

	ref << 4.41379655, 0.0, 0.0, 4.41379655;
	for (int i = 0; i < REPEAT_TEST; ++i) { Mean(VCov, calc, Metric_LogEuclidian); }
	EXPECT_TRUE(isAlmostEqual(ref, calc)) << ErrorMsg("Mean LogEuclidian", ref, calc).str();
}

TEST_F(Means_Tests, Riemann)
{
	Initialize();
	MatrixXd ref(2, 2), calc;

	ref << 4.41379655, 0.0, 0.0, 4.41379655;
	for (int i = 0; i < REPEAT_TEST; ++i) { Mean(VCov, calc, Metric_Riemann); }
	EXPECT_TRUE(isAlmostEqual(ref, calc)) << ErrorMsg("Mean Riemann", ref, calc).str();
}

TEST_F(Means_Tests, LogDet)
{
	Initialize();
	MatrixXd ref(2, 2), calc;

	ref << 4.41390769, 0.0, 0.0, 4.41390769;
	for (int i = 0; i < REPEAT_TEST; ++i) { Mean(VCov, calc, Metric_LogDet); }
	EXPECT_TRUE(isAlmostEqual(ref, calc)) << ErrorMsg("Mean LogDet", ref, calc).str();
}

TEST_F(Means_Tests, Kullback)
{
	Initialize();
	MatrixXd ref(2, 2), calc;

	ref << 4.41379655, 0.0, 0.0, 4.41379655;
	for (int i = 0; i < REPEAT_TEST; ++i) { Mean(VCov, calc, Metric_Kullback); }
	EXPECT_TRUE(isAlmostEqual(ref, calc)) << ErrorMsg("Mean Kullback", ref, calc).str();
}

TEST_F(Means_Tests, Wasserstein)
{
	Initialize();
	MatrixXd ref(2, 2), calc;

	ref << 6.33517159, 0.0, 0.0, 6.33517159;
	for (int i = 0; i < REPEAT_TEST; ++i) { Mean(VCov, calc, Metric_Wasserstein); }
	EXPECT_TRUE(isAlmostEqual(ref, calc)) << ErrorMsg("Mean Wasserstein", ref, calc).str();
}

TEST_F(Means_Tests, ALE)
{
	Initialize();
	MatrixXd ref(2, 2), calc;

	ref << 4.41379655, 0.0, 0.0, 4.41379655;
	for (int i = 0; i < REPEAT_TEST; ++i) { Mean(VCov, calc, Metric_ALE); }
	EXPECT_TRUE(isAlmostEqual(ref, calc)) << ErrorMsg("Mean_ALE", ref, calc).str();
}

TEST_F(Means_Tests, Harmonic)
{
	Initialize();
	MatrixXd ref(2, 2), calc;

	ref << 2.36140606, 0.0, 0.0, 2.36140606;
	for (int i = 0; i < REPEAT_TEST; ++i) { Mean(VCov, calc, Metric_Harmonic); }
	EXPECT_TRUE(isAlmostEqual(ref, calc)) << ErrorMsg("Mean_Harmonic", ref, calc).str();
}

TEST_F(Means_Tests, Identity)
{
	Initialize();
	MatrixXd ref(2, 2), calc;

	ref << 1.0, 0.0, 0.0, 1.0;
	for (int i = 0; i < REPEAT_TEST; ++i) { Mean(VCov, calc, Metric_Identity); }
	EXPECT_TRUE(isAlmostEqual(ref, calc)) << ErrorMsg("Mean_Identity", ref, calc).str();
}
